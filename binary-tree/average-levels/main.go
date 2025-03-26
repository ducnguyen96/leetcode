package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
	ans := []float64{}

	level := []*TreeNode{root}

	for len(level) > 0 {
		tmp := []*TreeNode{}
		sum := 0.0
		for _, node := range level {
			sum += float64(node.Val)
			if node.Left != nil {
				tmp = append(tmp, node.Left)
			}
			if node.Right != nil {
				tmp = append(tmp, node.Right)
			}
		}
		ans = append(ans, sum/float64(len(level)))
		level = tmp
	}

	return ans
}
