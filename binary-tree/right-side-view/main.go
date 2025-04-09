package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	queue := []*TreeNode{root}
	ans := []int{}

	for len(queue) > 0 {
		breadth := len(queue)

		for i := 0; i < breadth; i++ {
			node := queue[0]
			queue = queue[1:]
			if i == 0 {
				ans = append(ans, node.Val)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
		}
	}

	return ans
}
