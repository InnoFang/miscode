package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello World")
	fmt.Printf("A boy named %v, who is %v years-old and %v LBS.\n", "Tom", 18, 140)
	fmt.Printf("%-15v $%4v\n", "SpaceX", 94)
	fmt.Printf("%-15v $%4v\n", "Virgin Galactic", 100)
	var number = 10
	number = number + 10
	number += 10
	number++ // but without the syntax of '++ number', due to it's not allowed.
	fmt.Println(number)
}
