package main

import (
	"math/rand"
	"time"
)



func produce(tune chan<- int) {
	rand.Seed(time.Now().UnixNano())
	for {
		num := rand.Intn(100)
		println("produce: ", num, " , len=",len(tune))
		tune <- num
	}
}

func consume(tune <-chan int){
	for {
		num := <- tune
		println("consume: ", num, " , len=",len(tune))
	}
}

func main() {
	tune := make(chan int, 5)
	go produce(tune)
	go consume(tune)

	time.Sleep(1 * time.Second)
}
