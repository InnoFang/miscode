package higher_order_functions

import java.io.BufferedReader
import java.io.FileReader

/**
 * Created by Inno Fang on 2017/11/13.
 */
fun main(args: Array<String>) {
    val list = listOf(1, 2, 3, 4, 5, 6, 7)

    val newList = ArrayList<Int>()

    list.map { it * 2 + 3 }.map { newList.add(it) }
    newList.forEach(::println)

//    list.forEach{
//        val newElement = it * 2 + 3
//        newList.add(newElement)
//    }
//
//    newList.forEach(::println)

    val list1 = listOf(
            1..20,
            2..5,
            100..233
    )
    // chagne to [1,2,3...20,2,3,..,5,100,101,...,233]
    val newLi = list1.flatMap { it.map { "NO. $it" } }
    newLi.forEach(::println)

    val list2 = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    list2.reduce { acc, i -> acc + i }.let(::println)

    // 0 - 6 的阶乘
    (0..6).map(::factorial).let(::println)

    // 初始值 5
    (1..10).fold(5) { acc, i -> acc + i }.let(::println)
    // 拼接字符串
    (0..6).map(::factorial).fold(StringBuilder()) { acc, i -> acc.append(i).append(",") }.let(::println)
    // 倒着拼接
    (0..6).map(::factorial).foldRight(StringBuilder()) { i, acc -> acc.append(i).append(",") }.let(::println)
    (0..6).map(::factorial).joinToString(",").let(::println)

    // 过滤阶乘为奇数的情况
    (0..6).map(::factorial).filter { it % 2 == 1 }.let(::println)
    // 过滤奇数位上的情况
    (0..6).map(::factorial).filterIndexed { index, i -> index % 2 == 1 }.let(::println)

    // 取数据，取到不符合要求的情况下终止
    (0..6).map(::factorial).takeWhile { it < 120 }.let(::println)

    // let , apply , with
    findPerson()?.let { (name, age) ->
        println(name)
        println(age)
    }

    findPerson()?.apply {
        findPerson()
        println("print info")
    }

    // read text
    val br = BufferedReader(FileReader("F:\\IDEA\\KotlinInAction\\src\\script\\helloworld.kts"))
    with(br) {
        var line: String?
        while (true) {
            line = readLine() ?: break
            println(line)
        }
        close()
    }

    // use 用于可关闭 Closeable 接口下的实现类，使用完自动调用 close()
    BufferedReader(FileReader("F:\\IDEA\\KotlinInAction\\src\\script\\helloworld.kts")).use {
        var line: String?
        while (true) {
            // 这里需要加 it，不然调用的不是 BufferedReader 的 readLine
            line = it.readLine() ?: break
            println(line)
        }
    }

}

fun factorial(n: Int): Int {
    if (n == 0) return 1
    return (1..n).reduce { acc, i -> acc * i }
}

fun findPerson(): Person? {
    return null
}

data class Person(val name: String, val age: Int) {
    fun showInfo() {
        println("name=$name, age=$age")
    }
}