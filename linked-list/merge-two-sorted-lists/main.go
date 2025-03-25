package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil && list2 == nil {
		return nil
	}

	head := &ListNode{}
	current := head

	for list1 != nil || list2 != nil {
		if list1 == nil {
			current.Val = list2.Val
			current.Next = list2.Next
			break
		}
		if list2 == nil {
			current.Val = list1.Val
			current.Next = list1.Next
			break
		}
		if list1.Val < list2.Val {
			current.Val = list1.Val
			list1 = list1.Next
		} else {
			current.Val = list2.Val
			list2 = list2.Next
		}

		current.Next = &ListNode{}
		current = current.Next
	}

	return head
}
