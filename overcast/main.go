package main

import (
	"bytes"
	"fmt"
	"html/template"
	"io/ioutil"
	"os"
	"os/exec"
	"overcast/helpers"
	"strconv"
	"strings"
)

var templateFile = template.Must(template.New("template.c").Funcs(template.FuncMap{
	"stringConverter": func(i interface{ String() string }) string {
		return i.String()
	},
	"noEscape": func(s string) template.HTML {
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

	dllInformation, err := helpers.ParseJson()
	if err != nil {
		fmt.Println(err)
		os.Exit(-1)
	}

	dllName := dllInformation.DllName
	functionName := dllInformation.FunctionName
	returnType := dllInformation.ReturnType
	argumentTypes := dllInformation.ArgumentTypes

	var declarations []helpers.Declaration
	var safetyChecks []string

	for i, argumentType := range argumentTypes {
		i = i + 2
		declaration := helpers.Declaration{
			VarType: argumentType,
			VarName: "arg_" + strconv.Itoa(i),
			ArgNum:  i,
		}
		safetyChecks = append(safetyChecks, declaration.SafetyCheck())
		declarations = append(declarations, declaration)
	}

	buffer := bytes.NewBuffer(nil)
	err = templateFile.Execute(buffer, map[string]interface{}{
		"declarations":         declarations,
		"safetyChecks":         safetyChecks,
		"functionName":         functionName,
		"functionNameType":     strings.Title(functionName),
		"dllNameWithExtension": dllName,
		"resultType":           returnType,
		"pathToDll":            dllInformation.Path,
	})

	if err != nil {
		fmt.Println("Template error occurred")
		os.Exit(-1)
	}

	err = ioutil.WriteFile("libSharedLib.cpp", buffer.Bytes(), 0644)
	if err != nil {
		fmt.Println("Error writing file")
		os.Exit(-1)
	}

	outputAsBytes, err := exec.Command("nmake", "/f", "EclipseBuilder", "libSharedLib").CombinedOutput()
	if err != nil {
		outputAsString := string(outputAsBytes[:])
		fmt.Println("Error compiling Eclipse Plugin")
		fmt.Println(outputAsString)
		os.Exit(1)
	}
}
