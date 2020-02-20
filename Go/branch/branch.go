package branch

import (
	"io/ioutil"
	"fmt"
)

func testIf() {
	const filename = "in.txt"
	if contents, err := ioutil.ReadFile(filename); err == nil {
		fmt.Printf("%s\n", contents)
	} else {
		fmt.Println(err)
	}
}

func eval(a, b int, op string) int {
	var result int
	switch op {
	case "+":
		result = a + b
	case "-":
		result = a - b
	case "*":
		result = a * b
	case "/":
		result = a / b
	default:
		panic("unsupported operator:" + op)
	}
	return result
}

func testSwitch() {
	fmt.Println(
		eval(1, 2, "+"),
		eval(3, 4, "*"),
		eval(5, 6, "-"),
		eval(4, 5, "/"),
	)
}

func main() {
	//testIf()
	testSwitch()
}
