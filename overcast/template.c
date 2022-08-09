#include "eclipseclass.h"
#include "windows.h"
#include <iostream>

typedef {{.resultType}} (*{{.functionNameType}})({{ .argumentTypes}});

extern "C"
int p_external_call_{{.functionName}}()
{
    EC_word return_value = EC_arg(1);
    {{ range .declarations }}{{ stringConverter . }}
    {{end}}

    {{ range .safetyChecks }}{{ noEscape .}}
    {{ end }}

    std::string path = "{{.pathToDll}}" + std::string("\\") + "{{.dllNameWithExtension}}";
    HINSTANCE dll = LoadLibrary(path.c_str());
    {{.functionNameType}} {{.functionName}} = ({{.functionNameType}}) GetProcAddress(dll,"{{.functionName}}");

    {{.resultType}} result = {{.functionName}}({{ joinDeclarationVarNames .declarations}});

    unify(return_value, EC_word(result));
    return EC_succeed;
}