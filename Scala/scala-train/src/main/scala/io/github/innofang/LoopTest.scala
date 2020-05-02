package io.github.innofang

object LoopTest {
  def main(args: Array[String]): Unit = {
    println(1 to 10)          // [1, 10]
    println(1.to(10))         // [1, 10]
    println(1 until 10)       // [1, 10)
    println(1.until(10))      // [1, 10)
    println(Range(1, 10))     // [1, 10)
    println(Range(1, 10, 2))  // [1, 3, 5, 7, 9] 一到十步长为2

    for (i <- 1 to 10 if i % 2 == 0) {
      println(i)
    }

    (1 to 10).foreach(n => println(n * 2))
  }
}
