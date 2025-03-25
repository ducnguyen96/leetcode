package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	current := head

	remain := 0

	for l1 != nil || l2 != nil {
		sum := l1.Val + l2.Val + remain
		current.Val = sum % 10
		remain = sum / 10

		if l1.Next == nil && l2.Next == nil {
			break
		}

		if l1.Next == nil {
			l1.Val = 0
		} else {
			l1 = l1.Next
		}

		if l2.Next == nil {
			l2.Val = 0
		} else {
			l2 = l2.Next
		}
		current.Next = &ListNode{}
		current = current.Next
	}

	if remain > 0 {
		current.Next = &ListNode{Val: remain}
	}

	return head
}

func main() {
	l1 := &ListNode{Val: 2, Next: &ListNode{Val: 4, Next: &ListNode{Val: 3}}}
	l2 := &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 4}}}
	l := addTwoNumbers(l1, l2)
	for l != nil {
		fmt.Println(l.Val)
		l = l.Next
	}
}
