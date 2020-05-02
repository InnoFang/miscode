package io.github.innofang

import scala.util.Random

object BranchTest {
  def main(args: Array[String]): Unit = {
    val num = Random.nextInt(10)
    val active = if (num > 5) num else 0
    println(active)
  }
}
