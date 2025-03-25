package main

type MinStack struct {
	idx    int
	values [30000]int
	mins   [30000]int
}

func Constructor() MinStack {
	return MinStack{idx: -1, values: [30000]int{}, mins: [30000]int{}}
}

func (this *MinStack) Push(val int) {
	if this.idx == -1 {
		this.mins[0] = val
	} else {
		this.mins[this.idx+1] = min(this.GetMin(), val)
	}
	this.values[this.idx+1] = val
	this.idx++
}

func (this *MinStack) Pop() {
	this.idx--
}

func (this *MinStack) Top() int {
	return this.values[this.idx]
}

func (this *MinStack) GetMin() int {
	return this.mins[this.idx]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
