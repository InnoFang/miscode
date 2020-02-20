package main

import (
	"errors"
	"fmt"
)

func tryRecover() {
	defer func() {
		r := recover()
		if err, ok := r.(error); ok {
			// 如果是 error， 则会进行处理
			fmt.Println("Error occured:", err)
		} else {
			// 如果不是 error，比如直接 `panic(123)` ，则不处理
			panic(fmt.Sprint("I don't know what to do: %v", r))
		}
	}()
	panic(errors.New("this is an error"))
}

func main() {
	tryRecover()
}
