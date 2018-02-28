package functional

/**
 * Created by Inno Fang on 2018/2/28.
 */


object YCombinator {
    interface Lambda<E> {
        fun call(n: Any): E
    }

    fun yCombinator(f: Lambda<Lambda<*>>): Lambda<Lambda<*>> {
        return object : Lambda<Lambda<*>> {
            override fun call(n: Any): Lambda<*> {
                val u = n as Lambda<Lambda<*>>
                return u.call(u)
            }
        }.call(object : Lambda<Lambda<*>> {
            override fun call(n: Any): Lambda<*> {
                val x = n as Lambda<Lambda<*>>

                return f.call(object : Lambda<Any> {
                    override fun call(n: Any): Any {
                        return x.call(x).call(n)!!
                    }
                })
            }
        }) as Lambda<Lambda<*>>
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val y = yCombinator(object : Lambda<Lambda<*>> {
            override fun call(n: Any): Lambda<*> {
                val fab = n as Lambda<Int>
                return object : Lambda<Int> {
                    override fun call(n: Any): Int {
                        val n = Integer.parseInt(n.toString())
                        return if (n < 2) {
                            Integer.valueOf(1)
                        } else {
                            n * fab.call(n - 1)
                        }
                    }
                }
            }
        })

        println(y.call(10))
    }
}