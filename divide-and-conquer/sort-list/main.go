package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func merge(left *ListNode, right *ListNode) *ListNode {
	tail := &ListNode{}
	dummy := tail

	for left != nil && right != nil {
		if left.Val < right.Val {
			tail.Next = left
			tail = left
			left = left.Next
		} else {
			tail.Next = right
			tail = right
			right = right.Next
		}
	}

	if left != nil {
		tail.Next = left
	} else {
		tail.Next = right
	}

	return dummy.Next
}

func _mid(node *ListNode) *ListNode {
	slow, fast := node, node

	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	mid := slow.Next
	slow.Next = nil

	return mid
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	mid := _mid(head)
	left := sortList(head)
	right := sortList(mid)

	return merge(left, right)
}

func main() {
	head := &ListNode{
		Val:  4,
		Next: &ListNode{Val: 2, Next: &ListNode{Val: 1, Next: &ListNode{Val: 3}}},
	}

	tail := sortList(head)
	// tail := head

	for tail != nil {
		fmt.Printf("%d, ", tail.Val)
		tail = tail.Next
	}
}
