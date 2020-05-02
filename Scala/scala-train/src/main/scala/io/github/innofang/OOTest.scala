package io.github.innofang

object OOTest {
  def main(args: Array[String]): Unit = {
    val tom = new Person("Tom", 18, "male")
    tom.eat()
  }
}

class Person(val name: String, var age: Int) {
  var gender: String = _

  def this(name: String, age: Int, gender: String) {
    this(name, age)
    this.gender = gender
  }

  def eat(): Unit = {
    println(name + " eat something ...")
  }
}
