:- lib(hash).

:- local reference(memory_model).

create_memory_model :-
    hash_create(Memory),
    setref(memory_model, Memory).

add_to_memory(Value) :-
    getref(memory_model, Memory),
    getval(free_address, Free_address),
    hash_set(Memory, Free_address, Value),
    Next_free_address is Free_address + 1,
    setval(free_address, Next_free_address),
    setref(memory_model, Memory).

get_from_memory(Address, Value) :-
    getref(memory_model, Memory),
    (hash_get(Memory, Address, Value) ->
        true
    ;
        random(Random_value_at_address),
        hash_set(Memory, Address, Random_value_at_address),
        Value = Random_value_at_address
    ).

get_free_address(Free_address) :-
    getval(free_address, Free_address).