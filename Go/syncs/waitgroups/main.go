package main

import (
	"sync"
	"fmt"
)

var wg sync.WaitGroup // 创建同步等待组对象

func main() {

	wg.Add(2) // 设置等待组中要执行的子 goroutine 的数量

	go foo()
	go bar()

	fmt.Println("Main Wait")
	wg.Wait()	// 表示 Main Goroutine 进入等待，意味着阻塞
	fmt.Println("Main Done")
}

func foo() {
	for i := 1; i < 10; i++ {
		println("Foo:", i)
	}
	defer wg.Done()
}

func bar() {
	for i := 1; i < 10; i++ {
		println("Bar:", i)
	}
	defer wg.Done() // 给 wg 等待组中的 counter 减一
}
