package io.github.innofang

object FunctionTest {

  def main(args: Array[String]): Unit = {
    println(add(1, 2))
    println(three) // 没有入参的函数，调用括号可以省略
    defaultFunc()
    defaultFunc("James")
    println(speed(time = 2.0f, distance = 10.0f))
    call("Mike", "Amy")
    call("Jane", "Tom", "Bob")
  }

  def add(x: Int, y: Int): Int = {
    print(x + " + " + y + " = ")
    x + y // 最后一行为返回值时可以不要 return
  }

  def three() = 1 + 2

  // 默认函数
  def defaultFunc(name: String = "Anonymous "): Unit = {
    println("My name is " + name)
  }

  // 命名函数
  def speed(distance: Float, time: Float) = distance / time

  // 可变参数
  def call(person: String*) {
    person.foreach(p => println("hello, " + p))
  }
}
