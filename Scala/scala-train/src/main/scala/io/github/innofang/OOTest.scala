package io.github.innofang

object OOTest {
  def main(args: Array[String]): Unit = {
    val tom = new Person("Tom", 18, "male")
    tom.eat()
    val mike = new Student("Mike", 20, "CS")
    println(mike)
  }
}

abstract class Animal {
  def eat()
}

class Person(val name: String, var age: Int) extends Animal {
  var gender: String = _

  def this(name: String, age: Int, gender: String) {
    this(name, age)
    this.gender = gender
  }

  override def eat(): Unit = {
    println(name + " eat something ...")
  }
}

class Student(name: String, age: Int, var major: String) extends Person(name, age) {
  override def toString: String = {
    s"Name: ${this.name}\nAge: ${this.age}\nMajor: ${this.major}"
  }
}
