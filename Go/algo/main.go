package main

import (
	"LearnGo/algo/UnionFind"
	"fmt"
)

func main() {
	uf := UnionFind.Create(10)
	uf.Union(1, 2)
	uf.Union(1, 3)
	uf.Union(3, 4)
	uf.Union(5, 6)
	uf.Union(2, 7)

	fmt.Println(uf.Find(4))
	fmt.Println(uf.Find(2))
	fmt.Println(uf.IsConnected(4, 5))
}
