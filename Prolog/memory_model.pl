:- lib(hash).
:- lib(csv).
:- lib(lambda).

%% declare the memory model as a global variable
:- local reference(memory_model).

%% get_type_bytesize(+Type, -Size_in_bytes)
%% Gets the size of a c type in bytes
%% Parameters:
%%   Type: The type to get the size of
%%   Size_in_bytes: The size of the type in bytes
:- dynamic get_type_bytesize/2.

initialise_memory_model :-
    % % Ensure "variable_sizes.csv" exists
    % open("variable_sizes.csv", read, Stream),
    % close(Stream),

    % Ensure sizes are up to date on each run, without previous run influence.
    retractall(get_type_bytesize(_,_)),

    % Reads as a list of lists. Each row is a list.
    % The first row is the header row, which is not needed, it is removed with the `|` operator.
    % Csv_file is a list of lists, each list is a row.
    % Eg: [[int,4],[float,4],[double,8],[char,1],[pointer,4]]
    csv_read("variable_sizes.csv", [_ | Csv_file], []),

    % A lambda to convert the Type to an atom from a string (csv_read creates a string) and asserts the types to the database.
    % The lambda effectively means: given a list ([C_type,Size_in_bytes]), convert C_type to an atom and
    % assert the `get_type_bytesize` predicate.
    % This lambda is applied to every element of the Csv_file list.
    maplist(\[C_type,Size_in_bytes] ^ (atom_string(Type,C_type), assert(get_type_bytesize(Type, Size_in_bytes))), Csv_file),

    hash_create(Memory_model),
    setref(memory_model, Memory_model).

%% add_to_memory/1
%% add_to_memory(+Value)
%% Adds a value to the memory model
%% Parameters:
%%   Value: The value to add to the memory model
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

%% get_from_memory/2
%% get_from_memory(+Address, -Value_at_address)
%% Gets the value at the given address.
%% If a value does not exist at the given address, a random value is created and returned in the form of a c_var.
%% Parameters:
%%   Address: The address of the desired value
%%   Value_at_address: The value at the given address
get_from_memory(Address, Value_at_address) :-
    utils__get_ptc_out_if_cvar(Address, Use_address),

    getref(memory_model, Memory_model),
    (hash_get(Memory_model, Use_address, Value_at_address) ->
        true
    ;
        random(Random_value_at_address), % QUESTION: Will this work for floats?
        c_var__create(int, Random_value_at_address, _, "__memory_model_junk__", Use_address, Value_at_address),
        hash_set(Memory_model, Use_address, Value_at_address)
    ).

%% get_free_address/1
%% get_free_address(-Free_address)
%% Gets the next free address in the memory model
%% Parameters:
%%   Free_address: The next free address in the memory model
get_free_address(Free_address) :-
    getval(free_address, Free_address).
