package main

import "fmt"

func main() {
	bst := NewBST()
	bst.CreateTree(0, 100, 20)
	fmt.Println(bst.Preorder())
}
