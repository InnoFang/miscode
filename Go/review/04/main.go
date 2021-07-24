package main

import (
	"fmt"
	"math/big"
)

func main() {
	// use big.Int, when integer is larger than 10^18, that is, it cannot hold by any integer type
	lightSpeed := big.NewInt(299792)
	secondsPerDay := big.NewInt(86400)
	fmt.Println(lightSpeed, secondsPerDay)

	// but the parameter passed into the big.NewInt also is an integer type,
	// so if we want to create a big.Int instance in practice, use SetString is recommend
	distance := new(big.Int)
	distance.SetString("240000000000000000000000000", 10) // decimal
	fmt.Println(distance)

	// literal value is constant value by default, which means that the bigger value (largger than 10^18) can use to computation directly
	// Because the computation for literal value and constant value is finished in compile stage not runtime stage.
	// Tthe untype constant value supported by big.Int, and it cannot convert into normal integer type
	fmt.Println("Andromeda galaxy is", 2400000000000000/28878/86400, "light days away.")
	// NOTE that that constant value larger than 10^18 cannot be passed to the function with int type
	// the follow code are illegal
	// // const distance = 2400000000000000
	// // fmt.Println(distance)
}
