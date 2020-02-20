package function

import (
	"fmt"
	"reflect"
	"runtime"
)

func div(a, b int) (q, r int) {
	q = a / b
	r = a % b
	return
}

func eval(a, b int, op string) (int, error) {
	switch op {
	case "+": return a + b, nil
	case "-": return a - b, nil
	case "*": return a * b, nil
	case "/": return a / b, nil
	default:
		return 0, fmt.Errorf("unsupported operation: " + op)
	}
}

func apply(op func(int, int) int, a, b int) int {
	p := reflect.ValueOf(op).Pointer()
	opName := runtime.FuncForPC(p).Name()
	fmt.Printf(
		"Calling function %s with args (%d, %d)\n", opName, a, b)
	return op(a, b)
}

func sum(numbers ...int) int {
	s := 0
	for i := range numbers {
		s += numbers[i]
	}
	return s
}

func swap(a, b *int) {
	*a , *b = *b, *a
}

func main() {
	fmt.Println(
		//div(13, 4),
		apply(func(a int, b int) int {
			return a * b
		}, 2, 3),
	)
	if res, err := eval(13, 4, "x"); nil != err {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println(res)
	}

	a, b := 3, 4
	swap(&a, &b)
	fmt.Println(a, b)
}

