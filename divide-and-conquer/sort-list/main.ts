class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function merge(left: ListNode | null, right: ListNode | null): ListNode | null {
  let tail = new ListNode();
  const dummy = tail;

  while (left && right) {
    if (left.val < right.val) {
      tail.next = left;
      tail = left;
      left = left.next;
    } else {
      tail.next = right;
      tail = right;
      right = right.next;
    }
  }

  tail.next = left ? left : right;
  return dummy.next;
}

function getMid(node: ListNode): ListNode | null {
  let [slow, fast] = [node, node];

  while (fast.next && fast.next.next) {
    slow = slow.next!;
    fast = fast.next.next;
  }

  const mid = slow?.next;
  slow.next = null;

  return mid;
}

function sortList(head: ListNode | null): ListNode | null {
  if (!head || !head.next) return head;

  const mid = getMid(head);
  const left = sortList(head);
  const right = sortList(mid);
  return merge(left, right);
}
