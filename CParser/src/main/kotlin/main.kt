import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTreeWalker
import java.io.File


fun main(args: Array<String>) {

    val path = if(args.size != 1) {
        println(
            "Argument not provided, defaulting to test.c" +
                    "Example first argument: test.c"
        )
        "./src/main/kotlin/test.C"
    } else {
        if (args[0].endsWith(".c",ignoreCase = true) ) args[0] else "$args.c"
    }

    val input = CharStreams.fromFileName(path)
    val lexer = CLexer(input)
    val tokens = CommonTokenStream(lexer)
    val parser = CParser(tokens)
    val tree = parser.compilationUnit()

    val walker = ParseTreeWalker()
    val prologBuilder = PrologBuilder()

    val listener = ParserListener(prologBuilder)
    walker.walk(listener, tree)

    File("parsed.pl").writeText(prologBuilder.toString())
//    println(prologBuilder.toString())
}