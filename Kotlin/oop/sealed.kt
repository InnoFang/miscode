package oop

import java.util.*

/**
 * Created by Inno Fang on 2018/2/27.
 */

/**
 * sealed 的作用其实跟 enum 很像，只不过 enum 限制的是常量，sealed 限制的是类
 *
 * 一个类之所以设计成sealed，就是为了限制类的继承结构，将一个值限制在有限集中的类型中，而不能有任何其他的类型
 */
sealed class Expression

class ONE : Expression()
class TWO : Expression()
class THREE : Expression()

fun main(args: Array<String>) {
    Random().nextInt(3)
            .let { arrayOf(ONE(), TWO(), THREE())[it] }
            .let {
                when (it) {
                    is ONE -> println("ONE")
                    is TWO -> println("TWO")
                    is THREE -> println("THREE")
                }
            }
    data class A(var a: Int = 0, var b: Int = 1)

}

