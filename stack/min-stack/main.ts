class MinStack {
  idx: number = -1;
  values: number[] = Array(30000);
  mins: number[] = Array(30000);

  constructor() {}

  push(val: number): void {
    if (this.idx == -1) {
      this.mins[0] = val;
    } else {
      this.mins[this.idx + 1] = Math.min(this.getMin(), val);
    }
    this.values[this.idx + 1] = val;
    this.idx++;
  }

  pop(): void {
    this.idx--;
  }

  top(): number {
    return this.values[this.idx];
  }

  getMin(): number {
    return this.mins[this.idx];
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
