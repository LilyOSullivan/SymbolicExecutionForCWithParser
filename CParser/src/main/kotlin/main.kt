import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTreeWalker
import java.io.File


fun main(args: Array<String>) {

    if(args.size != 1) {
        throw IllegalArgumentException(
            "A path to the C file must be provided.\n " +
                    "Example first argument: test.C"
        )
    }
    val path = if (args[0].endsWith(".C",ignoreCase = true) ) args[0]  else "$args.C"

//    val path = "./src/main/kotlin/test.C"
    val input = CharStreams.fromFileName(path)
    val lexer = CLexer(input)
    val tokens = CommonTokenStream(lexer)
    val parser = CParser(tokens)
    val tree = parser.compilationUnit()

    val walker = ParseTreeWalker()
    val prologBuilder = PrologBuilder()

    val extractor = Walker(prologBuilder)
    walker.walk(extractor, tree)

    File("parsed.pl").writeText(prologBuilder.toString())
//    println(prologBuilder.toString())
}