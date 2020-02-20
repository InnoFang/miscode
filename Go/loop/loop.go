package loop

import (
	"strconv"
	"fmt"
	"os"
	"bufio"
)

func convert2Bin(n int) string {
	result := ""
	for ; n > 0; n /= 2 {
		lsb := n % 2
		result = strconv.Itoa(lsb) + result
	}
	return result
}

func printFile(filename string) {
	file, err := os.Open(filename)
	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}
}

func main() {
	fmt.Println(
		convert2Bin(10),
		convert2Bin(13),
	)
	printFile("in.txt")


}
