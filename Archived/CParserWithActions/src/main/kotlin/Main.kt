import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import java.io.ByteArrayOutputStream
import java.io.File
import java.io.PrintStream

fun main() {
    val path = "./src/main/kotlin/temp.c"
    var sb = ByteArrayOutputStream()
    val consoleStream = System.out
    System.setOut(PrintStream(sb))
    val input = CharStreams.fromFileName(path)
    val lexer = CLexer(input)
    val tokens = CommonTokenStream(lexer)
    val parser = CParser(tokens)
    parser.buildParseTree = false
    parser.compilationUnit()

    var result:String = sb.toString()
    // Strip ",]" from output
    result = result.replace(",]","]") + "."

    System.setOut(consoleStream)
    println(result)
}