package main

import (
	"math/rand"
	"time"
	"fmt"
	"sync"
)

var ticket = 10
var mutex sync.Mutex
var wg sync.WaitGroup

func saleTickets(name string) {
	defer wg.Done()
	rand.Seed(time.Now().UnixNano())
	for {
		mutex.Lock()
		if ticket > 0 {
			time.Sleep(time.Duration(rand.Intn(1000)) * time.Millisecond)
			fmt.Println(name,"Sale:", ticket)
			ticket--
		} else {
			mutex.Unlock()
			fmt.Println(name,"Sold out")
			break
		}
		mutex.Unlock()
	}
}

func main() {
	wg.Add(4)
	go saleTickets("Win 1")
	go saleTickets("Win 2")
	go saleTickets("Win 3")
	go saleTickets("Win 4")
	wg.Wait()
}
