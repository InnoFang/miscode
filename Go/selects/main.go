package main

import (
	"time"
	"fmt"
)

func main() {
	ch1 := make(chan int)
	ch2 := make(chan int)

	go func() {
		time.Sleep(1 * time.Second)
		ch1 <- 100
	}()

	select {
	case num1 := <-ch1:
		fmt.Println("Read from ch1:", num1)
	case num2, ok := <-ch2:
		if ok {
			fmt.Println("Read from ch2:", num2)
		} else {
			fmt.Println("ch2 has been closed")
		}
	case <-time.After(1 * time.Second):
		fmt.Println("After 3 seconds")
	default:
		fmt.Println("default ...")
	}
}
