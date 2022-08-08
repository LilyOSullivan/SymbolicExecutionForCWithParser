package helpers

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

type DllInformation struct {
	DllName       string   `json:"dll_name"`
	FunctionName  string   `json:"function_name"`
	ReturnType    string   `json:"return_type"`
	ArgumentTypes []string `json:"argument_types"`
	Path          string   `json:"path"`
}

func ParseJson() (DllInformation, error) {
	fileContent, err := ioutil.ReadFile("libSharedLib.json")
	if err != nil {
		fmt.Println("Error opening file\n" + err.Error())
		os.Exit(-1)
	}
	var dllInformation DllInformation
	err = json.Unmarshal(fileContent, &dllInformation)
	if err != nil {
		fmt.Println("Error parsing JSON\n" + err.Error())
		os.Exit(-1)
	}

	if dllInformation.Path == "." || dllInformation.Path == "./" {
		exePath, pathErr := os.Getwd()
		if pathErr == nil {
			dllInformation.Path = strings.ReplaceAll(exePath, "\\", "\\\\")
		}
	}

	if !strings.HasSuffix(dllInformation.DllName, ".dll") {
		dllInformation.DllName = dllInformation.DllName + ".dll"
	}
	return dllInformation, nil
}

func normaliseTypes(types []string) {
	for i, typeName := range types {

		types[i] = strings.ToLower(typeName)
	}
}
