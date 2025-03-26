package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var (
	preorderIdx int
	myMap       map[int]int
)

func build(preorder *[]int, start int, end int) *TreeNode {
	if start > end {
		return nil
	}

	val := (*preorder)[preorderIdx]
	preorderIdx++
	root := &TreeNode{Val: val}
	mid := myMap[val]

	root.Left = build(preorder, start, mid-1)
	root.Right = build(preorder, mid+1, end)

	return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	preorderIdx = 0
	myMap = make(map[int]int)
	for i, v := range inorder {
		myMap[v] = i
	}

	return build(&preorder, 0, len(inorder)-1)
}
