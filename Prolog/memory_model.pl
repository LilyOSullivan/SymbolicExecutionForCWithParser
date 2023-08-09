:- lib(hash).

%% declare the memory model as a global variable
:- local reference(memory_model).

initialise_memory_model :-
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
            get_type_information('pointer', Type_byte_size, _ , _)
        ;
            c_var__get_type(Value, Type),
            get_type_information(Type, Type_byte_size, _ , _)
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
get_from_memory(Address, Return_value_at_address) :-
    c_var__get_out_var(Address, Use_address),
    utils__get_appropriate_cvar_type(Address, Type),
    % utils__get_ptc_out_if_cvar(Address, Use_address),

    getref(memory_model, Memory_model),
    (hash_get(Memory_model, Use_address, Value_at_address) ->
        true
    ;
        random(Random_value_at_address), % QUESTION: Will this work for floats?
        % utils__demotion(Random_value_at_address, Type, Demoted_value),
        c_var__create(int, Demoted_value, _, "__memory_model_junk__", Use_address, Value_at_address),
        hash_set(Memory_model, Use_address, Value_at_address)
    ).

%% get_free_address/1
%% get_free_address(-Free_address)
%% Gets the next free address in the memory model
%% Parameters:
%%   Free_address: The next free address in the memory model
get_free_address(Free_address) :-
    getval(free_address, Free_address).
