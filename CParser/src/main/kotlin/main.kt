import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTreeWalker


fun main() {
    val path = "./src/main/kotlin/test.C"
    val input = CharStreams.fromFileName(path)
    val lexer = CLexer(input)
    val tokens = CommonTokenStream(lexer)
    val parser = CParser(tokens)
    val tree = parser.compilationUnit()

    val walker = ParseTreeWalker()
    val prologBuilder = PrologBuilder()

    val extractor = CWalker(prologBuilder)
    walker.walk(extractor, tree)

    println(prologBuilder.toString())
}