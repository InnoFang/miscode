package enum

import (
	"fmt"
	"math"
	"math/cmplx"
)

func variableZero() {
	var a int
	var s string
	fmt.Printf("%d %q\n", a, s)
}

func euler() {
	fmt.Println(cmplx.Exp(1i * math.Pi) + 1)
}

func enums() {

	const (
		Mon = iota
		Tue
		Wed
		Thr
		Fri
		Sat
		Sun
	)
	fmt.Println(Mon, Tue, Wed, Thr, Fri, Sat, Sun)

	const (
		b = 1 << (10 * iota)
		kb
		mb
		gb
		tb
		pb
	)
	fmt.Println(b, kb, mb, gb, tb, pb)
}

func main() {
	variableZero()
	euler()
	enums()
}
