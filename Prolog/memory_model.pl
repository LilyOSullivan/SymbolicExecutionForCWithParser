:- lib(hash).
:- lib(csv).
:- lib(lambda).

:- local reference(memory_model).

initialise_memory_model :-
    % % Ensure "variable_sizes.csv" exists
    % open("variable_sizes.csv", read, Stream),
    % close(Stream),

    % Reads as a list of lists. Each row is a list.
    % The first row is the header row, which is not needed, is removed with the `|` operator.
    csv_read("variable_sizes.csv", [_ | Csv_file], []),
    maplist(\[C_type,Size_in_bytes]^(atom_string(Type,C_type), assert(get_sizeof(Type,Size_in_bytes))), Csv_file),

    hash_create(Memory),
    setref(memory_model, Memory).

add_variable_to_memory_model(Variable) :-
    c_var__get_type(Variable, Type),
    get_sizeof(Type, Type_byte_size),
    add_to_memory(Variable, Type_byte_size).

add_pointer_to_memory_model(Pointer) :-
    get_sizeof(pointer, Type_byte_size),
    add_to_memory(Pointer, Type_byte_size).

add_to_memory(Value, Type_byte_size) :-
    getref(memory_model, Memory_model),
    getval(free_address, Free_address),
    hash_set(Memory_model, Free_address, Value),
    Next_free_address is Free_address + Type_byte_size,
    setval(free_address, Next_free_address),
    setref(memory_model, Memory_model).

get_from_memory(Address, Value) :-
    (
        c_var__is_variable(Address) ->
            c_var__get_out_var(Address, Use_address)
        ;
            Use_address = Address
    ),

    %% Suspend unless Address is ground
    getref(memory_model, Memory),
    (hash_get(Memory, Use_address, Value) ->
        true
    ;
        random(Random_value_at_address), % Will this work for floats?
        %% ptc_solver__variable([Value], int),
        c_var__create(int, Random_value_at_address, _, "__memory_model_junk__", Use_address, Value),
        hash_set(Memory, Use_address, Value)
    ).


% get_from_memory(Address, Value) :-
%     %% Suspend unless Address is ground
%     (
%         nonground(Address) ->
%             suspend(get_from_memory(Address, Value), 3, Address->inst)
%         ;
%             getref(memory_model, Memory),
%             (hash_get(Memory, Address, Value) ->
%                 true
%             ;
%                 % random(Random_value_at_address), % Will this work for floats?
%                 ptc_solver__variable([Value], int),
%                 % c_var__create(int, Random_value_at_address, _, _, Address, Value),
%                 hash_set(Memory, Address, Value)
%             )
%     ).



get_free_address(Free_address) :-
    getval(free_address, Free_address).

% get_sizeof(char, 1).
% get_sizeof(short, 2).
% get_sizeof(int, 4).
% get_sizeof(long, 8).
% get_sizeof('long long', 8).
% get_sizeof(float, 4).
% get_sizeof(double, 8).

% get_sizeof(charpointer, 8).
% get_sizeof(intpointer, 8).
% get_sizeof(floatpointer, 8).

% sizeof(Type, Byte_size).