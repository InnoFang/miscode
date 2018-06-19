// kotlinc -script <filename>.kts

import java.io.*

println("hello world")


File("../../..").list().forEach(::println)