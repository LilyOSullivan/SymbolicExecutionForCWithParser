package main

import (
	"fmt"
	"html/template"
	"os"
	"overcast/helpers"
	"strconv"
	"strings"
)

var templateFile = template.Must(template.New("template.c").Funcs(template.FuncMap{
	"stringConverter": func(i interface{ String() string }) string {
		return i.String()
	},
	"stringToHtml": func(s string) template.HTML {
		return template.HTML(s)
	},
	"joinDeclarations": func(declarations []helpers.Declaration) string {
		var declarationStrings []string
		for _, declaration := range declarations {
			declarationStrings = append(declarationStrings, declaration.VarName)
		}
		return strings.Join(declarationStrings[:], ",")
	},
}).ParseFiles("template.c"))

func main() {

	dllName := "libSharedLib.dll"
	functionName := "addOne"
	returnType := "int"
	argumentTypes := []string{"double", "double"}

	var declarations []helpers.Declaration
	var safetyChecks []string

	for i, argumentType := range argumentTypes {
		i = i + 1
		declaration := helpers.Declaration{
			VarType: argumentType,
			VarName: "arg_" + strconv.Itoa(i),
			ArgNum:  i,
		}
		declarations = append(declarations, declaration)
		safetyChecks = append(safetyChecks, declaration.SafetyCheck())
	}

	err := templateFile.Execute(os.Stdout, map[string]interface{}{
		"declarations":         declarations,
		"safetyChecks":         safetyChecks,
		"functionName":         functionName,
		"functionNameType":     strings.Title(functionName),
		"dllNameWithExtension": dllName,
		"resultType":           returnType,
	})

	if err != nil {
		fmt.Println("Template error occurred")
		os.Exit(-1)
	}

}
