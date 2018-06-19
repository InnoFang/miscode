package move

import processing.core.PApplet

/**
 * Created by Inno Fang on 2018/3/1.
 */

class Stripes(val p: PApplet) {
    var x: Float = 0F
    var speed: Float = p.random(1F)
    var weight: Float = p.random(10F, 30F)
    var mouse: Boolean = false

    fun display() = with(p) {
        fill(255F, 100F)
        noStroke()
        rect(x, 0F, weight, height.toFloat())
    }

    fun move() = with(p) {
        x += speed
        if (x > width + 20) x = -20F
    }
}

class Sketch : PApplet() {

    val stripes = Array(50) { Stripes(this) }

    override fun settings() {
        size(500, 500)
    }

    override fun draw() {
        background(100)
        stripes.forEach { stripe ->
            with(stripe) {
                move()
                display()
            }
        }
    }

    override fun mousePressed() {
        background(64)
    }
}

fun main(args: Array<String>) {
    PApplet.main(Sketch::class.java)
}
