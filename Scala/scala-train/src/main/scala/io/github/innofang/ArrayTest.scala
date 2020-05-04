package io.github.innofang

import scala.collection.mutable.ArrayBuffer

object ArrayTest extends App {

  // 定长数组
  val arr1 = new Array[Int](5)
  for (i <- 1 until 5) {
    arr1(i) = i
  }
  println(arr1.min)
  println(arr1.max)
  println(arr1.sum)
  println(arr1.mkString(","))

  // 可变长数组
  var arr2 = ArrayBuffer[Int]()
  // add data
  arr2 += 1           // 加一个元素
  arr2 += 2           // 加一个元素
  arr2 += (3, 4, 5, 6)   // 加一组元素
  arr2 ++= Array(7, 8, 9, 10) // 加一个数组的元素
  arr2.insert(0, 0)   // 第 0 位置插入元素 0
  arr2.remove(1)      // 删除下标为 1 的元素
  arr2.remove(0, 3) // 删除 [0, 3) 位置的元素
  arr2.trimEnd(2)   // 删除最后面两个元素
  arr2 -= 5   // remove 删除的是下标，-= 删除的是元素
  arr2 -= (6, 7)
  arr2 --= Array(9, 11) // 删除的元素不存在也不会出错

  // 遍历
  for (ele <- arr2) {
    println(ele)
  }
  println()
  // 逆序遍历
  for (i <- (0 until arr2.length).reverse) {
    println(arr2(i))
  }

  println(arr2)
}
