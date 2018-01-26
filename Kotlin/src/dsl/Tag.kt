package dsl

/**
 * Created by Inno Fang on 2017/11/12.
 */
open class Tag(val name: String) : Node {

    val children = ArrayList<Node>()

    val properties = HashMap<String, String>()

    operator fun String.invoke(value: String) {
        properties[this] = value
    }

    operator fun String.invoke(block: Tag.() -> Unit) {
        this@Tag.children.add(Tag(this).apply(block))
    }

    // 一元加号运算符
    operator fun String.unaryPlus() {
        children.add(StringNode(this))
    }

    operator fun plus(node: Node) {
        children.add(node)
    }
    // <html id="htmlId" style=""><head> </head> <body> </body></html>
    override fun render(): String {
        return StringBuilder()
                .append("<$name")
                .let { stringBuilder ->
                    if (!this.properties.isEmpty()) {
                        this.properties.forEach {
                            stringBuilder.append(" ${it.key}=\"${it.value}\"")
                        }
                    }
                    stringBuilder
                }
                .append(">")
                .let { stringBuilder ->
                    children.map(Node::render).map(stringBuilder::append)
                    stringBuilder
                }
                .append("</$name>")
                .toString()
    }
}