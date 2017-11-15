package compose

import closure.add

/**
 * Created by Inno Fang on 2017/11/14.
 */
// f(g(x))

val add5 = { i: Int -> i + 5 }
val multiplyBy2 = { i: Int -> i * 2 }

fun main(args: Array<String>) {
    println(multiplyBy2(add5(8))) // (5 + 8) * 2

    val add5AndThenMultiplyBy2 = add5 andThen multiplyBy2
    println(add5AndThenMultiplyBy2(8))

    val f = multiplyBy2 compose add5
    println(f(8))
}

/* P1作为参数传入Function1（即 add5）得到的结果 P2 作为参数传入另一个 Function1（即multiplyBy2），然后的到的结果为R，返回R  */
/* add5: 即中缀前一个表达式 */       /* multiplyBy2: 即中缀后一个表达式*/
infix fun <P1, P2, R> Function1<P1, P2>.andThen(function: Function1<P2, R>): Function1<P1, R> {
    return fun(p1: P1): R {
        return function.invoke(this.invoke(p1))
        //     multiplyBy2    (add5       (8))
    }
}

// 重新实现
//infix fun <P1, P2, R> Function1<P1, P2>.complex(function: Function1<P2, R>): Function1<P1, R> {
//    return fun(p1: P1): R {
//        return function.invoke(this.invoke(p1))
//    }
//}

// val f =  multiplyBy2 compose add5
// f(8)
infix fun <P1, P2, R> Function1<P2, R>.compose(function: Function1<P1, P2>): Function1<P1, R> {
    return fun(p1: P1): R {
        return this.invoke(function.invoke(p1))
    }
}