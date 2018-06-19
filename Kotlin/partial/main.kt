package partial

import java.nio.charset.Charset

/**
 * Created by Inno Fang on 2017/11/14.
 */

fun <P1, P2, R> Function2<P1, P2, R>.partical2(p2: P2) = fun(p1: P1) = this(p1, p2)
fun <P1, P2, R> Function2<P1, P2, R>.partical1(p1: P1) = fun(p2: P2) = this(p1, p2)

val makeString = fun(byteArray: ByteArray, charset: Charset):String {
    return String(byteArray, charset)
}

val makeStringFromGBKBytes = makeString.partical2(charset("GBK"))
fun main(args: Array<String>) {
    val bytes = "创新".toByteArray(charset("GBK"))
    val stringFromGBK = makeStringFromGBKBytes(bytes)
    println(stringFromGBK)

}