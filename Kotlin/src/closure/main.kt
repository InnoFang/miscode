package closure

/**
 * Created by Inno Fang on 2017/11/13.
 */
fun makeFun(): () -> Unit {
    var count = 0
    return fun() {
        println(count++)
    }
}

fun main(args: Array<String>) {
//    val x = makeFun()
//    x()
//    x()
//    x()
//    x()
//    x()


//    val f = fibonacci()
//    println(f())
//    println(f())
//    println(f())
//    println(f())
//    println(f())
//    println(f())

//    fibonacci().takeWhile { it <= 1000 }.forEach { print("$it ") }

    val add5 = add(5)
    println(add5(2))
}

//fun add(x: Int) = fun(y: Int) = x + y

fun add(x: Int): (Int) -> Int {
    return fun(y: Int): Int {
        return x + y
    }
}

/*

fun fibonacci(): () -> Long {
    var first = 0L
    var second = 1L
    return fun(): Long {
        val result = second
        second += first
        first = second - first
        return result
    }
}*/


fun fibonacci(): Iterable<Long> {
    var first = 0L
    var second = 1L
    return Iterable<Long> {
        object : LongIterator() {
            override fun hasNext(): Boolean = true

            override fun nextLong(): Long {
                val result = second
                second += first
                first = second - first
                return result
            }

        }
    }
}
