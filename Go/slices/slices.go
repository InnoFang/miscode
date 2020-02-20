package slices

import "fmt"



func main() {
	arr := [...]int{0, 1, 2, 3, 4, 5, 6, 7}
	fmt.Println(arr[2:6])	// [2 3 4 5]
	fmt.Println(arr[:6])	// [0 1 2 3 4 5]
	fmt.Println(arr[2:])	// [2 3 4 5 6 7]
	fmt.Println(arr[:])		// [0 1 2 3 4 5 6 7]
}
