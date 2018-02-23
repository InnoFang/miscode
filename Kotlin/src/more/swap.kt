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
    chars.swap(0,2)
    ints.puts()
    chars.puts()

    var a = 1
    var b = 2
    println("a:$a, b:$b")
    (a to b).let{ a = it.second; b = it.first }

    "a:$a, b:$b"()

}

operator fun String.invoke() = println(this)