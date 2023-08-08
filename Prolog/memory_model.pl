:- lib(hash).
:- lib(csv).
:- lib(lambda).

:- local reference(memory_model).

:- dynamic get_type_bytesize/2.

initialise_memory_model :-
    % % Ensure "variable_sizes.csv" exists
    % open("variable_sizes.csv", read, Stream),
    % close(Stream),

    % Ensure sizes are up to date on each run, without previous run influence.
    retractall(get_type_bytesize(_,_)),

    % Reads as a list of lists. Each row is a list.
    % The first row is the header row, which is not needed, it is removed with the `|` operator.
    csv_read("variable_sizes.csv", [_ | Csv_file], []),
    maplist(\[C_type,Size_in_bytes] ^ (atom_string(Type,C_type), assert(get_type_bytesize(Type, Size_in_bytes))), Csv_file),

    hash_create(Memory_model),
    setref(memory_model, Memory_model).


add_to_memory(Value) :-
    (
        c_var__is_pointer(Value) ->
            get_type_bytesize(pointer, Type_byte_size)
        ;
            c_var__get_type(Value, Type),
            get_type_bytesize(Type, Type_byte_size)
    ),
    getref(memory_model, Memory_model),
    getval(free_address, Free_address),
    c_var__set_address(Value, Free_address),
    hash_set(Memory_model, Free_address, Value),
    Next_free_address is Free_address + Type_byte_size,
    setval(free_address, Next_free_address).

get_from_memory(Address, Value_at_address) :-
    (
        c_var__is_variable(Address) ->
            c_var__get_out_var(Address, Use_address)
        ;
            Use_address = Address
    ),

    getref(memory_model, Memory_model),
    (hash_get(Memory_model, Use_address, Value_at_address) ->
        true
    ;
        random(Random_value_at_address), % QUESTION: Will this work for floats?
        c_var__create(int, Random_value_at_address, _, "__memory_model_junk__", Use_address, Value_at_address),
        hash_set(Memory_model, Use_address, Value_at_address)
    ).

get_free_address(Free_address) :-
    getval(free_address, Free_address).
