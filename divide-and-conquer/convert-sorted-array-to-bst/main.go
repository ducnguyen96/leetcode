package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func build(nums *[]int, start int, end int) *TreeNode {
	if start > end {
		return nil
	}

	mid := int(math.Ceil(float64(end-start) / 2))
	mid += start
	val := (*nums)[mid]
	node := &TreeNode{Val: val}

	node.Left = build(nums, start, mid-1)
	node.Right = build(nums, mid+1, end)

	return node
}

func sortedArrayToBST(nums []int) *TreeNode {
	return build(&nums, 0, len(nums)-1)
}
