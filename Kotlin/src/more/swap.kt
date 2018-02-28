package more

/**
 * Created by Inno Fang on 2018/2/23.
 */

fun <T> Array<T>.swap(i: Int, j: Int) {
    val tmp = this[i]
    this[i] = this[j]
    this[j] = tmp
}

fun <T> Array<T>.puts() {
    this.forEach { print("$it ") }
    println()
}

fun main(args: Array<String>) {
    val ints = arrayOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
    val chars = arrayOf('a', 'b', 'c', 'd', 'e', 'f')

    println("------ method one  ------")
    println("------ before swap ------")
    ints.puts()
    chars.puts()
    println("------ after  swap ------")
    ints.swap(0, 2)
    chars.swap(0, 2)
    ints.puts()
    chars.puts()

    var a = 1
    var b = 2
    println("a:$a, b:$b")
    // swap
    // method 1
//    (a to b).let{ a = it.second; b = it.first }

    // method 2
//    with(a to b) { a = second; b = first }

    // method 3
    (a to b).run { a = second; b = first }
    "a:$a, b:$b"()
    val str = "jaskldjfhakljashdfiwjhialsjhlkblzjmxd"
    val store = HashMap<Char, Int>()
    str.forEach { store[it] = store.getOrElse(it, { 0 }) + 1 }
    store.forEach(::println)


    // swap 3 variable
    a = 1
    b = 2
    var c = 3
    Triple(a, b, c).run { a = third; b = first; c = second; }

    printResult(1, 2)
}

data class Swap(val a: Int, val b: Int)
fun printResult(x: Int, y: Int) {
    println("before: x:$x, y:$y")
    val (y, x) = Swap(x, y)
    println("after : x:$x, y:$y")
}



operator fun String.invoke() = println(this)
