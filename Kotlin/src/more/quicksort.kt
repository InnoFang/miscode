package more

/**
 * Created by Inno Fang on 2018/2/25.
 */

fun main(args: Array<String>) {
    quickSort(mutableListOf(7, 7, 3, 9, 4, 6, 5, 0, 2, 1, 8)).forEach { print("$it ") }
}

// only one line !!! it's so cool !!!
//fun quickSort(list: List<Int>): List<Int> = if (list.size <= 1) list else with(list.takeLast(list.lastIndex).partition { it < list[0] }) { quickSort(first) + list[0] + quickSort(second) }

fun quickSort(list: List<Int>): List<Int> = if (list.size <= 1) list else list.takeLast(list.lastIndex).partition { it < list[0] }.run { quickSort(first) + list[0] + quickSort(second) }

//fun quickSort(list: List<Int>): List<Int> {
//    return if (list.size <= 1) list
//    else {
//        list.takeLast(list.lastIndex)
//                .partition { it < list[0] }
//                .run { quickSort(first) + list[0] + quickSort(second) }
//    }
//}

