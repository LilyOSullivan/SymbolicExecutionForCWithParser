#include "eclipseclass.h"
#include "windows.h"
#include <iostream>

typedef int (*{{.functionNameType}})(int);

 std::string get_current_dir() {
    char buff[MAX_PATH];
    GetModuleFileName(nullptr, buff, MAX_PATH);
    std::string::size_type position = std::string(buff).find_last_of("\\/");
    std::string path = std::string(buff).substr(0, position);
    position = path.find_last_of("\\/");
    return path.substr(0, position);
}


extern "C"
int p_external_call_{{.functionName}}()
{
    EC_word return_value = EC_arg(1);
    {{ range .declarations }}{{ stringConverter . }}
    {{end}}

    {{ range .safetyChecks }}{{stringToHtml .}}
    {{ end }}

    std::string current_dir = get_current_dir();
    std::string path = current_dir + "\\" + "{{.dllNameWithExtension}}";
    HINSTANCE dll = LoadLibrary(path.c_str());
    {{.functionNameType}} {{.functionName}} = ({{.functionNameType}}) GetProcAddress(dll,"{{.functionName}}");

    {{.resultType}} result = {{.functionName}}({{ joinDeclarations .declarations}});

    unify(return_value, EC_word(result));
    return EC_succeed;
}