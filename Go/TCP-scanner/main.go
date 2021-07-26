package main

import (
	"fmt"
	"net"
	"sync"
	"time"
)

func main() {
	ip := `127.0.0.1`
	var wg sync.WaitGroup
	start := time.Now()
	for i := 1; i <= 65535; i++ {
		wg.Add(1)
		go func(port int) {
			defer wg.Done()
			address := fmt.Sprintf("%v:%v", ip, port)
			conn, err := net.Dial("tcp", address)
			if err != nil {
				fmt.Printf("IP %v was closed!\n", address)
				return
			}
			conn.Close()
			fmt.Printf("IP %v is opening ...\n", address)
		} (i)
	}
	wg.Wait()
	elapsed := time.Since(start) / 1e9
	fmt.Printf("\nused %v seconds.\n", elapsed)
}
