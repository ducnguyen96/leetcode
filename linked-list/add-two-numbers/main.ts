class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null,
): ListNode | null {
  const head = new ListNode();
  let current = head;
  let remain = 0;

  while (l1 || l2) {
    const sum = l1!.val + l2!.val + remain;
    current.val = sum % 10;
    remain = Math.floor(sum / 10);

    if (!l1?.next && !l2?.next) break;

    if (l1?.next) {
      l1 = l1.next;
    } else {
      l1!.val = 0;
    }

    if (l2?.next) {
      l2 = l2.next;
    } else {
      l2!.val = 0;
    }

    current.next = new ListNode();
    current = current.next;
  }

  if (remain) current.next = new ListNode(remain);

  return head;
}
