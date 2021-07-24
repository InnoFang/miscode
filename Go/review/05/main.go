package main

import (
	"fmt"
	"strconv"
)

func main() {
	// use '``' to present the raw string
	fmt.Println("Hello \n world")
	fmt.Println(`Hello \n world`)
	// raw string allow the multi-line text
	fmt.Println(`
		Abstract
		Introduction
		Evaluation
	`)

	// rune is aliases for 32-bit integer, so they can transform by each other
	// moreover, byte is aliases for 8-bit interger
	var pi rune = 960
	var alpha rune = 940
	var omega rune = 969
	var bang byte = 33
	fmt.Printf("%v %v %v %v\n", pi, alpha, omega, bang)
	fmt.Printf("%c %c %c %c\n", pi, alpha, omega, bang)

	countdown := 10
	// type cannt not be casted automatically
	// Itoa is 'integer to ASCII'
	str := "Launch in T minus " + strconv.Itoa(countdown) + " seconds."
	fmt.Println(str)

	countdown--
	str = fmt.Sprintf("Launch in T minus %v seconds.", countdown)
	fmt.Println(str)
}
