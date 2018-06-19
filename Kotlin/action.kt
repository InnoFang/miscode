import java.io.File

/**
 * Created by Inno Fang on 2017/11/14.
 */

fun main(args: Array<String>) {
    // 统计字符个数
    val map = HashMap<Char, Int>()
    File("F:\\Github\\playground\\Kotlin\\Kotlin.iml")
            .readText()
            .toCharArray()
            .filterNot(Char::isWhitespace)
            .groupBy { it }
            .map { it.key to it.value.size }
            .forEach(::println)

}