package io.github.innofang

object CompanionTest {
  def main(args: Array[String]): Unit = {
    // 如果伴生对象没有实现apply方法，那么就需要写 new
    val c = Companion() // 调用的是伴生对象的apply方法
    c.foo() // 调用实例成员
    Companion.bar() // 调用静态成员
    c()     // 调用的是伴生类的apply方法
  }
}

/**
  * 伴生类和伴生对象必须在一个文件里
  *
  * Scala 中没有 static 关键字，因此出现了伴生对象和伴生类的概念
  * 伴生对象本质上是一个单例类，里面的成员都会被当作是静态的；伴生类中的成员则会被当作是实例的
  * 因此要访问伴生对象里面的成员或者属性，方式为 `伴生对象名.成员`
  * 而要访问伴生类中的成员或者属性，则需要先有一个伴生类的实例对象，方式为 `伴生类对象.成员`
  * 此外，伴生对象和伴生类的私有属性都可以互相访问
  *
  * 伴生对象的意义就是弥补了类中不能定义 static 属性的缺陷
  */

class Companion {
  private val classTAG = "class"

  def foo(): Unit ={
    // 可以直接访问伴生对象的私有变量
    println(s"print Object TAG: ${Companion.objectTAG}")
  }

  /**
    * 伴生类也有apply方法，调用方式是为 `伴生对象()`
    */
  def apply() = {
    println("Class apply")
  }
}

object Companion {
  private val objectTAG = "object"

  def bar(): Unit = {
    val companion = new Companion
    // 可以直接访问伴生类的私有变量
    println(s"print Class TAG: ${companion.classTAG}")
  }

  /**
    * apply 方法是特别指定的。伴生对象的 apply 方法的返回值一般都为伴生类的对象
    * 这样做的好处就是在创建实例对象时，可以不用写 new
    * 也就是说，在创建实例对象时，最先访问的是伴生对象的 apply 方法，
    * @return
    */
  def apply(): Companion = {
    println("Object apply")
    new Companion()
  }
}