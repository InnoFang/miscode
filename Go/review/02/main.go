package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	var num = rand.Intn(10) + 1
	fmt.Println("random number is:", num)
	var hw = "hello world"
	var exit = strings.Contains(hw, "world")
	if exit {
		fmt.Println("got it!")
	} else {
		fmt.Println("got nothing!")
	}

	var room = "lake"
	switch room {
	case "cave":
		fmt.Println("You find yourself in a dimly lit cavern")
	case "mountain", "hill":
		fmt.Println("And now on the top!")
	case "lake":
		fmt.Println("The ice seems solid enough.")
		fallthrough // this key word's meaning is the opposite of the 'break'
		// excute the body code of the next case directly
	case "underwater":
		fmt.Println("The water is freezing cold.")
	}

	var count = 5
	fmt.Println("Counting down:")
	for count > 0 {
		fmt.Println(count)
		time.Sleep(time.Second)
		count--
	}
	fmt.Println("done.")
}
