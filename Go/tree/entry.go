package main

import (
	"fmt"
)

type myTreeNode struct {
	node *treeNode
}

func (myNode *myTreeNode) postOrder() {
	if myNode == nil && myNode.node == nil {
		return
	}  
	left := myTreeNode{myNode.node.left}
	right := myTreeNode{myNode.node.right}

	left.postOrder()
	right.postOrder()
	myNode.node.print()
}

func main() {
	var root treeNode

	// Go struct 有很多构造方法，所以可以不需要所谓的构造函数

	root = treeNode{value: 3}
	root.left = &treeNode{}
	root.right = &treeNode{5, nil, nil}
	root.right.left = new(treeNode)
	root.left.right = createTreeNode(2) // 使用工厂方

	myRoot := myTreeNode{&root}
	myRoot.postOrder()
	fmt.Println()
}
