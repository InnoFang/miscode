package io.github.innofang

/**
  * trait 类似 Java8 的接口（interface）
  */

trait Runnable {
  def run
}

trait Flyable {
  def fly
}

/**
  * 抽象类与 Java 的抽象类是类似的
  */
trait  Tester {
  var name: String = _
  def logI(info: String): Unit ={
    println(s"[INFO] $info")
  }

  def test
}

/**
  * extends 只能是抽象类，所以只能继承一个抽象类
  * 而 trait 可以有多个，用 with 连接
  */

class TraitTest extends Runnable with Tester with Flyable {
  override def test: Unit = {

  }

  override def run: Unit = {

  }

  override def fly: Unit = {

  }
}
