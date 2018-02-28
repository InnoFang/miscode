package oop

/**
 * Created by Inno Fang on 2018/2/27.
 */

object Singleton{
    val a = 1
    fun print(x: Int) = println("singleton: $x")
}

fun main(args: Array<String>) {
    Singleton.print(Singleton.a)

    val coor = object { var x = 0; var y = 0 }

}