#include "eclipseclass.h"
#include "windows.h"
#include <iostream>

typedef int (*AddOne)(int);

extern "C"
int p_external_call()
{
    EC_word return_value = EC_arg(1);
    long arg_2;
    

    if(EC_arg(2).is_long(&arg_2))
	return EC_fail;
    

    std::string path = "C:\\Users\\Person\\Dropbox\\Mac (2)\\Documents\\Github\\SymbolicExecutionForCWithParser\\overcast" + std::string("\\") + "libSharedLib.dll";
    HINSTANCE dll = LoadLibrary(path.c_str());
    AddOne addOne = (AddOne) GetProcAddress(dll,"addOne");

    int result = addOne(arg_2);

    unify(return_value, EC_word(result));
    return EC_succeed;
}