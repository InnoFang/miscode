package oop

/**
 * Created by Inno Fang on 2018/2/27.
 */

open class A

interface B
interface C
class D : A(), B, C

////////////////////////

class Project
class Milestone

interface ProjectService {
    val name: String
    val owner: String
    fun save(project: Project)
    fun print() {
        println("I am project")
    }
}

interface MilestoneService {
    val name: String
    fun save(milestone: Milestone)
    fun print() {
        println("I am Milestone")
    }
}

class ProjectMilestoneServiceImpl : ProjectService, MilestoneService {


    override val name: String
        get() = "ProjectMilestone"
    override val owner: String
        get() = "Jack"

    override fun save(project: Project) {
        println("Save Project")
    }

    override fun save(milestone: Milestone) {
        println("Save Milestone")
    }
    override fun print() {
        super<MilestoneService>.print()
        super<ProjectService>.print()
    }
}



/////////////multiple inheritance//////////////

abstract class Animal{
    fun doEat() {
        println("Animal Eating")
    }
}

interface Runnable {
    fun doRun()
}

interface Flyable {
    fun doFly()
}

class Archaeopteryx: Animal(), Runnable, Flyable {
    override fun doRun() {
        println("Archaeopteryx Running")
    }

    override fun doFly() {
        println("Archaeopteryx Flying")
    }
}


fun main(args: Array<String>) {
//    ProjectMilestoneServiceImpl().print()
    val a = Archaeopteryx()
    a.doEat()
    a.doFly()
    a.doRun()
}