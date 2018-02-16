package more

/**
 * Created by Inno Fang on 2018/2/16.
 */

fun main(args: Array<String>) {

    // way one

    fun lambda(it: Int): Int =
            if (it <= 2) 1 else lambda(it - 1) + lambda(it - 2)


    (1..10).map(::lambda).forEach(::format).let(::newLine)


    // //

    // way two

    var lambda2: (Int) -> Int = { it }
    lambda2 = { if (it <= 2) 1 else lambda2(it - 1) + lambda2(it - 2) }
    (1..10).map(lambda2).forEach(::format).let(::newLine)
}

fun format(arg: Any) = print("$arg ")
fun newLine(arg: Any) = println()