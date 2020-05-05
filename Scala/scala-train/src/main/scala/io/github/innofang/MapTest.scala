package io.github.innofang

import scala.collection.mutable
import scala.collection.immutable

object MapTest extends App {
  val map0 = Map("Mike" -> 60, "John" -> 77) // 不可变
  val map1 = mutable.Map("Tim" -> 78, "Amy" -> 88) // 可变
  val map2 = new mutable.HashMap[String, Int]
  map2 += ("Tina" -> 68, "Bob" -> 90)

  map2 -= "Tim" // 删除

  // 键值对倒转
  // for 循环可以有返回值，这时候就要用到 yield 关键字
  val map3 = for ((k, v) <- map1) yield { // yield的主要作用是记住每次迭代中的有关值，并逐一存入到一个数组中
    (v -> k)
  }
  println(map3)

  // 有序映射
  val map4 = immutable.SortedMap("Karl" -> 86, "Fred" -> 78, "Alex" -> 99, "Tommy" -> 65)
  println(map4)

  // 要使用可变长有序映射，可以使用 LinkedHashMap
  val map5 = mutable.LinkedHashMap.newBuilder[String, Int]
  map5 += ("Tina" -> 91, "Jerry" -> 67)

  // Scala 有元组的概念，
  val tuple1 = (1, 3.14, "Pi")
  val first = tuple1._1   // 把元组第一个元素传给变量
  val second = { tuple1 _2 } // 把元组第二个元素传给变量（两种方式）
  val (one, two, three) = tuple1 // 把元组元素挨个赋值

  val tuple2 = "New York".partition(_.isUpper)
  println(tuple2) // 把字母分成大写和非大写的元组

  // 通过数组构建映射
  val keys = Array("Doug", "Michel", "Cherry")
  val values = Array(67, 93, 77)
  val map6 = keys.zip(values).toMap
  println(map6)

}
