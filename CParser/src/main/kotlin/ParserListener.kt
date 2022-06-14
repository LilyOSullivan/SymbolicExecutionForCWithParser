import org.antlr.v4.runtime.ParserRuleContext

class ParserListener(var prologBuilder: PrologBuilder) : CBaseListener()  {

    override fun enterFunctionDefinition(ctx: CParser.FunctionDefinitionContext) {
        val returnType = ctx.declarationSpecifiers().text
        val declarationCtx = ctx.getChild(1)
        val components = (declarationCtx.getChild(0) as ParserRuleContext).children
        val functionName = components[0].text
        val declarations = mutableListOf<String>()
        if(components.size > 3) {
            // Parameters Exist
            val declarationComponents = (components[2].getChild(0) as ParserRuleContext).children
            for (i in declarationComponents.indices.step(2)) { // Step to skip ','
//                if(i % 2 == 1) { // Skip ','
//                    continue
//                }
                val component = declarationComponents[i]
                val varType = component.getChild(0).text
                val varName = component.getChild(1).text.uppercase()
                declarations.add("$varType($varName)")
            }
        }
        prologBuilder.startFunction(returnType,functionName,declarations)
    }

    override fun exitFunctionDefinition(ctx: CParser.FunctionDefinitionContext?) {
        prologBuilder.endFunction()
    }


    override fun enterSelectionStatement(ctx: CParser.SelectionStatementContext) {
        when(ctx.children[0].text) { // Can be switch
            "if" -> prologBuilder.ifStart()
            "else" -> prologBuilder.elseStart()
        }
    }

    override fun exitSelectionStatement(ctx: CParser.SelectionStatementContext) {
        when(ctx.children[0].text) { // Can be switch
            "if" -> prologBuilder.ifEnd()
        }
    }

//    override fun enterJumpSemiColon(ctx: CParser.JumpSemiColonContext?) {
//        prologBuilder.genericWrite(",")
//    }

    override fun enterLeftBracket(ctx: CParser.LeftBracketContext) {
        prologBuilder.genericWrite(",[")
    }

    override fun enterElseStatement(ctx: CParser.ElseStatementContext?) {
        prologBuilder.elseStart()
    }

    override fun enterUnaryOperator(ctx: CParser.UnaryOperatorContext) {
        prologBuilder.unaryOperator(ctx.text)
    }

    override fun enterPrimaryExpression(ctx: CParser.PrimaryExpressionContext) {
        prologBuilder.genericWrite(ctx.text.uppercase())
    }

    override fun enterJumpStatement(ctx: CParser.JumpStatementContext) {
        when(ctx.children[0].text){
            "return" -> prologBuilder.startReturnStatement()
        }
    }

    override fun exitJumpStatement(ctx: CParser.JumpStatementContext) {
        when(ctx.children[0].text){
            "return" -> prologBuilder.endReturnStatement()
        }
    }

    override fun enterEqualityOperators(ctx: CParser.EqualityOperatorsContext) {
        prologBuilder.equality(ctx.text)
    }

    override fun enterRelationalOperators(ctx: CParser.RelationalOperatorsContext) {
        prologBuilder.relationalOperator(ctx.text)
    }
}