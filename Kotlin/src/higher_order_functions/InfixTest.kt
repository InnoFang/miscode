package higher_order_functions

/**
 * Created by Inno Fang on 2018/2/28.
 */

infix fun Int.x(x: Int): Int {
    return this * x
}


fun Int.equal() {
    println(this)
}

object Vocabulary {
    val 这 = "this"
    val 我 = "me"

    public infix fun String.是(v: String){
        println("$this is $v")
    }
}

fun main(args: Array<String>) {
    (1 x 2).equal()
    (2 x 3).equal()
    (3 x 4).equal()
    (1 + (2 x 3) + (5 x 2)).equal()

    with(Vocabulary) {
        这 是 我
    }
}