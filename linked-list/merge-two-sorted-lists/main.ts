class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function mergeTwoLists(
  list1: ListNode | null,
  list2: ListNode | null,
): ListNode | null {
  if (!list1 && !list2) return null;

  const head = new ListNode();
  let current = head;

  while (list1 || list2) {
    if (!list1) {
      current.val = list2!.val;
      current.next = list2!.next;
      break;
    }
    if (!list2) {
      current.val = list1!.val;
      current.next = list1!.next;
      break;
    }

    if (list1!.val < list2!.val) {
      current.val = list1!.val;
      list1 = list1!.next;
    } else {
      current.val = list2!.val;
      list2 = list2!.next;
    }
    current.next = new ListNode();
    current = current.next;
  }

  return head;
}
