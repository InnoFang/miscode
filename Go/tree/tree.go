package main

import "fmt"

type treeNode struct {
	value       int
	left, right *treeNode
}

func (node treeNode) print() {
	fmt.Print(node.value)
}

// 工厂方法
func createTreeNode(value int) *treeNode {
	return &treeNode{value: value} // 返回的是局部变量的地址！！
}

func min() {
	var root treeNode

	// Go struct 有很多构造方法，所以可以不需要所谓的构造函数

	root = treeNode{value: 3}
	root.left = &treeNode{}
	root.right = &treeNode{5, nil, nil}
	root.right.left = new(treeNode)
	root.left.right = createTreeNode(2) // 使用工厂方法

	// 定义在 Slice 中可以省略反复写 treeNode
	nodes := []treeNode {
		{value: 3},
		{},
		{6, nil, nil},
	}
	fmt.Println(nodes)
}
