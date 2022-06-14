class PrologBuilder {
    private var stringBuilder:StringBuilder = StringBuilder()

    fun genericWrite(value:String) {
        stringBuilder.append(value)
    }

    fun startFunction(returnType: String,name: String,declarations:List<String>) {
        val declarationsAsString = "[${declarations.joinToString(",") }]"
        stringBuilder.append("function($returnType,$name,$declarationsAsString,[")
    }

    fun equality(value: String) {
        when(value) {
            "==" -> stringBuilder.append('=')
        }
    }

    fun unaryOperator(operator:String) {
        stringBuilder.append(operator)
    }

    fun startReturnStatement() {
        stringBuilder.append("return(")
    }

    fun endReturnStatement() {
        stringBuilder.append(")]")
    }

    fun endFunction() {
        if(stringBuilder.last() == ',')
            stringBuilder.setLength(stringBuilder.length - 1)
        stringBuilder.append("])).")
    }

    private fun appendComma(toBeAppended:String) {
        stringBuilder.append("$toBeAppended,")
    }

    fun ifStart() {
        stringBuilder.append("ifStmt(")
    }

    fun ifEnd() {
        stringBuilder.append("),")
    }

    fun elseStart() {
        stringBuilder.append(",[")
    }

    fun elseEnd() {
        stringBuilder.append("])")
    }

    fun relationalOperator(op:String) {
        stringBuilder.append(op)
    }

    override fun toString() = stringBuilder.toString()
}
