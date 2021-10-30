package introduction

import processing.core.PApplet
import processing.core.PConstants

class RandomWalk : PApplet() {
    var x: Float = 0.0f
    var y: Float = 0.0f

    override fun settings() {
        size(700, 500, PConstants.P2D)
    }

    override fun setup() {
        background(255)
        x = width * 0.5f
        y = height * 0.5f
    }

    override fun draw() {
        x += random(-1.0f, 1.0f)
        y += random(-1.0f, 1.0f)

        point(x, y)
    }
}

private fun main() {
    PApplet.main("introduction.RandomWalk")
}