package helpers

import (
	"fmt"
	"strings"
)

type Declaration struct {
	VarType string
	VarName string
	ArgNum  int
}

func (d *Declaration) String() string {
	return fmt.Sprintf("%s %s;", strings.ToLower(d.VarType), strings.ToLower(d.VarName))
}

func (d *Declaration) SafetyCheck() string {

	var builder strings.Builder

	if isFloatingPointType(d.VarType) {
		builder.WriteString(fmt.Sprintf("if(EC_arg(%d).is_double(&%s))\n", d.ArgNum, d.VarName))
		builder.WriteString("\treturn EC_fail;")
	} else if isIntegerType(d.VarType) {
		d.VarType = "long"
		builder.WriteString(fmt.Sprintf("if(EC_arg(%d).is_long(&%s))\n", d.ArgNum, d.VarName))
		builder.WriteString("\treturn EC_fail;")
	} else if isString(d.VarType) {
		d.VarType = "char*"
		builder.WriteString(fmt.Sprintf("if(EC_arg(%d).is_string(&%s))\n", d.ArgNum, d.VarName))
		builder.WriteString("\treturn EC_fail;")
	}

	return builder.String()
}

func isFloatingPointType(varType string) bool {
	varType = strings.ToLower(varType)
	switch varType {
	case "float":
		fallthrough
	case "double":
		fallthrough
	case "long double":
		return true

	default:
		return false
	}
}

func isIntegerType(varType string) bool {
	varType = strings.ToLower(varType)
	switch varType {
	case "char":
		fallthrough
	case "unsigned char":
		fallthrough
	case "signed char":
		fallthrough
	case "int":
		fallthrough
	case "unsigned int":
		fallthrough
	case "short":
		fallthrough
	case "unsigned short":
		fallthrough
	case "long":
		fallthrough
	case "unsigned long":
		return true

	default:
		return false
	}
}

func isString(varType string) bool {
	varType = strings.ToLower(varType)
	switch varType {
	case "char":
		fallthrough
	case "std::string":
		fallthrough
	case "string":
		return true

	default:
		return false
	}
}
