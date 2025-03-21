package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	left := head
	right := head.Next
	for left != nil && right != nil {
		left = left.Next
		right = right.Next
		if left == right {
			return true
		}
		if right != nil {
			right = right.Next
		}
	}
	return false
}
