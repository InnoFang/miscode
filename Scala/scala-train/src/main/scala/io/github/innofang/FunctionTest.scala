package io.github.innofang

class FunctionTest {

  def main(args: Array[String]) {
    println(add(1, 2))
    println(three) // 没有入参的函数，调用括号可以省略
  }

  def add(x: Int, y: Int): Int = {
    print(x + " + " + y + " = ")
    x + y // 最后一行为返回值时可以不要 return
  }

  def three() = 1 + 2
}
