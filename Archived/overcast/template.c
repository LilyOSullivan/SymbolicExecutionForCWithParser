#include "eclipseclass.h"
#include "windows.h"
#include <iostream>

typedef {{.resultType}} (*{{.functionNameType}})({{ .argumentTypes}});

extern "C"
int p_external_call()
{
    EC_word return_value = EC_arg(1);
    {{ range .declarations }}{{ stringConverter . }}
    {{end}}

    {{ range .safetyChecks }}{{ noEscape .}}
    {{ end }}

    std::string path = "{{.pathToDll}}" + std::string("\\") + "{{.dllNameWithExtension}}";
    HINSTANCE dll = LoadLibrary(path.c_str());
    if (dll == NULL)
    {
        unify(return_value, EC_atom("Error loading dll"));
        return EC_fail;
    }

    {{.functionNameType}} {{.functionName}} = ({{.functionNameType}}) GetProcAddress(dll,"{{.functionName}}");
    if ({{.functionName}} == NULL)
    {
        unify(return_value, EC_atom("Error loading function"));
        return EC_fail;
    }

    {{.resultType}} result = {{.functionName}}({{ joinDeclarationVarNames .declarations}});
    unify(return_value, EC_word(result));
    return EC_succeed;
}