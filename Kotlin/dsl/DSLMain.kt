package dsl

/**
 * Created by Inno Fang on 2017/11/12.
 */
fun main(args: Array<String>) {
    html {
        "id"("HtmlId")
        "head"{
            "id"("HeadId")
        }
        body {
            id = "BodyId"
            `class` = "BodyClass"
            "a" {
                "href"("https://innofang.github.io")
                +"InnoFang"
            }
        }
    }.render().let(::println)
}