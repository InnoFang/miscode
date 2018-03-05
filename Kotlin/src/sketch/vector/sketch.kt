package vector

import processing.core.PApplet

/**
 * Created by Inno Fang on 2018/3/3.
 */

class Sketch : PApplet() {
    var x = 0F
    var y = 0F
    var x2 = 0F
    var y2 = 0F
    val easing = 0.01F
    val Neasing = 0.05F

    override fun settings() {
        size(1200, 1700)
    }

    override fun setup() {
        stroke(10F, 50F)
        background(253)
    }

    override fun draw() {
        x += (mouseX - x) * easing
        y += (mouseY - y) * easing
        x2 += (mouseX - x2) * Neasing
        y2 += (mouseY - y2) * Neasing
        line(x, y, x2, y2)
    }
}

fun main(args: Array<String>) {
    PApplet.main(Sketch::class.java)
}