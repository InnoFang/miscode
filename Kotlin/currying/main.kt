package currying

import java.io.OutputStream

/**
 * Created by Inno Fang on 2017/11/14.
 */
fun log(tag: String, target: OutputStream, message: Any?) {
    target.write("[$tag] $message\n".toByteArray())
}

//fun log(tag: String)
//        = fun(target: OutputStream)
//        = fun(message: Any?)
//                = target.write("[$tag] $message\n".toByteArray())

fun main(args: Array<String>) {
//    log("Inno", System.out, "HelloWorld")
//    log("Inno")(System.out)("HelloWorld")
//    val curriedLog = ::log.currying()
//    curriedLog("Inno")(System.out)("HelloWorld")

//    val newLog = ::log.uncurrying()
//    newLog("Inno", System.out, "HelloWorld")

    val logger = (::log.currying())("Inno")(System.out)
    logger("Hello")
    logger("world")
}

// currying
fun <P1, P2, P3, R> Function3<P1, P2, P3, R>.currying()
        : (p1: P1) -> (p2: P2) -> (p3: P3) -> R
        = fun(p1: P1)
        = fun(p2: P2)
                = fun(p3: P3)
                        = this(p1, p2, p3)

// uncurrying
fun <P1, P2, P3, R> Function1<P1, (p2: P2) -> (p3: P3) -> R>.uncurrying()
        : (p1: P1, p2: P2, p3: P3) -> R
        = fun(p1: P1, p2: P2, p3: P3)
        = this(p1)(p2)(p3)
