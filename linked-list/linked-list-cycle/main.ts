class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}
function hasCycle(head: ListNode | null): boolean {
  if (!head) return false;

  let left: ListNode | null = head;
  let right: ListNode | null = head.next;
  while (left && right) {
    left = left.next;
    right = right.next;
    if (left == right) return true;
    if (right) right = right.next;
  }

  return false;
}
