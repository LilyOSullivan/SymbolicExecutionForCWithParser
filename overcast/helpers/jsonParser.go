package helpers

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

type DllInformation struct {
	Dll_name       string
	Function_name  string
	Return_type    string
	Argument_types []string
	Path           string
}

func ParseJson() (DllInformation, error) {
	fileContent, err := ioutil.ReadFile("libSharedLib.json")
	if err != nil {
		fmt.Println("Error opening file")
		os.Exit(-1)
	}
	var dllInformation DllInformation
	err = json.Unmarshal(fileContent, &dllInformation)
	if err != nil {
		return DllInformation{}, err
	}

	if dllInformation.Path == "." {
		dllInformation.Path = "." + string(os.PathSeparator)
	}
	if !strings.HasSuffix(dllInformation.Dll_name, ".dll") {
		dllInformation.Dll_name = dllInformation.Dll_name + ".dll"
	}
	return dllInformation, nil
}

func normaliseTypes(types []string) {
	for i, typeName := range types {

		types[i] = strings.ToLower(typeName)
	}
}