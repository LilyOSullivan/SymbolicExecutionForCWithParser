class PrologBuilder {
    private var stringBuilder:StringBuilder = StringBuilder()

    fun genericWrite(value:Char) {
        stringBuilder.append(value)
    }
    fun genericWrite(value:String) {
        stringBuilder.append(value)
    }

    fun startFunction(returnType: String,name: String,declarations:List<String>) {
        val declarationsJoined = "[${declarations.joinToString(",") }]"
        stringBuilder.append("function($returnType,$name,$declarationsJoined,[")
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
        var i = 0
        while(stringBuilder.indexOf(",]").also { i=it } != -1) {
            stringBuilder.replace(i,i+1,"]")
        }
        stringBuilder.append("]).")
    }

    fun ifStart() {
        stringBuilder.append("if_stmt(")
    }

    fun ifEnd() {
        stringBuilder.append("),")
    }

    fun elseStart() {
        stringBuilder.append(",[")
    }

    fun elseEnd() {
        stringBuilder.append("]),")
    }

    fun relationalOperator(op:String) {
        stringBuilder.append(op)
    }

    fun beginDeclaration(type:String) {
        stringBuilder.append("assignment($type(")
    }

    fun exitDeclaration() {
        stringBuilder.append("),")
    }

    override fun toString() = stringBuilder.toString()

}
