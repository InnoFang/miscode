package main

import (
	"fmt"
)

// In Go, If the fist letter of function name is upper-case, it can be called by others,
// but if it's lower-case, it cannot be called.

func kelvinToCelsius(k float64) float64 {
	k -= 273.15
	return k
}

func celsiusToFahrenheit(c float64) float64 {
	f := (c * 9.0 / 5.0) + 32.0
	return f
}

func kelvinToFahrenheit(k float64) float64 {
	f := ((k - 273.15) * 9.0 / 5.0) + 32.0
	return f
}

func main() {
	kelvin := 233.0
	celsius := kelvinToCelsius(kelvin)
	fahrenheit := celsiusToFahrenheit(celsius)
	fmt.Println(kelvin, "° K is ", celsius, "° C")
	fmt.Println(celsius, "° C is ", fahrenheit, "° F")
	fmt.Println("0 K is ", kelvinToFahrenheit(0), "° F")
}
