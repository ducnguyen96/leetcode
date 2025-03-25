from typing import Optional


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return None
        
        head = ListNode()
        current = head

        while list1 or list2:
             if not list1:
                 current.val = list2.val
                 current.next = list2.next
                 break
             if not list2:
                 current.val = list1.val
                 current.next = list1.next 
                 break
             if list1.val < list2.val:
                 current.val = list1.val
                 list1 = list1.next
             else:
                 current.val = list2.val
                 list2 = list2.next
             current.next = ListNode()
             current = current.next

        return head
