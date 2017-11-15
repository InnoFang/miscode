package dsl

/**
 * Created by Inno Fang on 2017/11/12.
 */

fun html(block: Tag.() -> Unit): Tag {
    return Tag("html").apply(block)
}

fun Tag.head(block: Head.() -> Unit) {
    this@head + Head().apply(block)
}

fun Tag.body(block: Body.() -> Unit) {
    this@body + Body().apply(block)
}

class StringNode(val content: String) : Node {
    override fun render() = content
}

class Head : Tag("head")

class Body : Tag("body") {
    var id by MapDelegate(properties)
    var `class` by MapDelegate(properties)
}