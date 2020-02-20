package array

import "fmt"

func main() {
	var arr1 [5]int 			// 定义长度为 5 的整型数组，默认值都为 0
	arr2 := [3]int{1, 3, 5}		// 定义并初始化长度为 3 的整型数组
	arr3 := [...]int{1, 3, 4}   // 不指定长度初始化一个整型数组
	var grid [3][4]int			// 定义 3 行 4 列的二维数组

	fmt.Println(arr1, arr2, arr3, grid)

	arr := [...]int{2, 4, 6, 8, 10}
	for i, v := range arr {
		fmt.Println(i, v)
	}
}