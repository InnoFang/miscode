package gravity

import processing.core.PApplet
import processing.core.PVector

/**
 * Created by Inno Fang on 2018/3/3.
 */


class Mover(val p: PApplet) {

    private var acceleration = PVector(0.01F, 0.01F)
    private val velocity = PVector(0F, 0F)
    private val position = PVector(p.random(p.width.toFloat()), p.random(p.height.toFloat()))

    fun update() = p.run {
        val mouse = PVector(mouseX.toFloat(), mouseY.toFloat())
        val dir = PVector.sub(mouse, position)

        dir.normalize()
        dir.mult(0.5F)
        acceleration = dir

        velocity.add(acceleration)
        velocity.limit(10F)
        position.add(velocity)
    }

    fun display() = p.run {
        stroke(0F)
        strokeWeight(2F)
        fill(127)
        ellipse(position.x, position.y, 32F, 32F)
    }

    fun checkEdge() = p.run {
        if (position.x > width) {
            position.x = width.toFloat()
            velocity.x *= -1
        } else if (position.x < 0) {
            position.x = 0F
            velocity.x *= -1
        }

        if (position.y > height) {
            position.y = height.toFloat()
            velocity.y *= -1;
        } else if (position.y < 0) {
            position.y = 0F
            velocity.y *= -1
        }
    }

}


class Gravity : PApplet() {
    lateinit var mover: Mover

    override fun settings() {
        mover = Mover(this)
        size(1280, 960)
    }

    override fun setup() {
        stroke(0F)
        strokeWeight(2F)
        fill(127)
    }

    override fun draw() {
        background(255)
        with(mover) {
            update()
            display()
            checkEdge()
        }
    }
}

fun main(args: Array<String>) {
    PApplet.main(Gravity::class.java)
}