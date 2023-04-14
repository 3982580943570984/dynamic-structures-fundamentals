package main

import "fmt"

func main() {
	values := []int{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 70, 31, 44, 66, 90}

	bst := NewBST()
	for _, v := range values {
		bst.Insert(v)
	}

	fmt.Println(bst.Inorder())
	fmt.Println(bst.Preorder())
	fmt.Println(bst.Postorder())

	fmt.Printf("Дерево пустое: %t\n", bst.IsEmpty())
	bst.Clear()
	fmt.Printf("Дерево пустое: %t\n", bst.IsEmpty())

	bst.CreateTree(0, 100, 10)

	fmt.Println(bst.Inorder())
	fmt.Println(bst.Preorder())
	fmt.Println(bst.Postorder())

	fmt.Printf("Дерево пустое: %t\n", bst.IsEmpty())
	bst.Clear()
	fmt.Printf("Дерево пустое: %t\n", bst.IsEmpty())
}
