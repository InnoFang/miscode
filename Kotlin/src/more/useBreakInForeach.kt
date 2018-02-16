package more

/**
 * Created by Inno Fang on 2018/2/16.
 */


fun main(args: Array<String>) {
    run breaking@ {
        (0..20).forEach continuing@ {
            if (10 <= it) return@breaking
            println(it)
        }
    }
}