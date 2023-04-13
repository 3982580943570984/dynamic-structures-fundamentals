package main

import (
	"math/rand"
	"strconv"
	"time"
)

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

type BST struct {
	Root *Node
}

/* Создание пустого дерева */
func NewBST() *BST {
	return &BST{}
}

/* Проверка пустоты */
func (bst *BST) isEmpty() bool {
	return bst.Root == nil
}

/* Добавление нового узла */
func (bst *BST) Insert(value int) {
	if bst.isEmpty() {
		bst.Root = &Node{Value: value}
		return
	}
	bst.insertRecursive(value, bst.Root)
}

func (bst *BST) insertRecursive(value int, node *Node) {
	if value < node.Value {
		if node.Left == nil {
			node.Left = &Node{Value: value}
		} else {
			bst.insertRecursive(value, node.Left)
		}
	} else {
		if node.Right == nil {
			node.Right = &Node{Value: value}
		} else {
			bst.insertRecursive(value, node.Right)
		}
	}
}

/* Создание дерева (параметры: интервал допустимых значений, количество */
func (bst *BST) CreateTree(min, max, count int) {
	bst.Root = nil

	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < count; i++ {
		value := r.Intn(max-min) + min
		bst.Insert(value)
	}
}

/* Обход сверху вниз */
func (bst *BST) Preorder() string {
	result := ""
	bst.preorderRecursive(bst.Root, &result)
	return result
}

func (bst *BST) preorderRecursive(node *Node, result *string) {
	if node == nil {
		return
	}
	*result += strconv.Itoa(node.Value) + " "
	bst.preorderRecursive(node.Left, result)
	bst.preorderRecursive(node.Right, result)
}

/* Удаление дерева */
func (bst *BST) Clear() {
	bst.clearRecursive(bst.Root)
	bst.Root = nil
}

func (bst *BST) clearRecursive(node *Node) {
	if node == nil {
		return
	}
	bst.clearRecursive(node.Left)
	bst.clearRecursive(node.Right)
	node.Left = nil
	node.Right = nil
}
