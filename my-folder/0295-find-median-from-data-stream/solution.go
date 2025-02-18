import (
    "container/heap"
    "fmt"
)

type IntHeap struct {
    data []int  
    isMaxHeap bool
}

func (h *IntHeap) Len() int {
    return len(h.data)
}

func (h *IntHeap) Less(i, j int) bool { 
    if h.isMaxHeap {
        return h.data[i] > h.data[j]
    }
    return h.data[i] < h.data[j]
}

func (h *IntHeap) Push(x interface{}) {
    h.data = append(h.data, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    old := h.data
    oldVal := old[len(old)-1]
    h.data = old[:len(old)-1]
    return oldVal
}

func (h *IntHeap) Swap(i, j int) {
    h.data[i], h.data[j] = h.data[j], h.data[i]
}

func initHeap(isMaxHeap bool) *IntHeap {
    intHeap := &IntHeap{data: []int{}, isMaxHeap: isMaxHeap}
    heap.Init(intHeap)
    return intHeap
}

type MedianFinder struct {
    left *IntHeap
    right *IntHeap
}


func Constructor() MedianFinder {
    return MedianFinder {
        left: initHeap(true),
        right: initHeap(false),
    }
}


func (this *MedianFinder) AddNum(num int)  {
    heap.Push(this.left, num)
    heap.Push(this.right, heap.Pop(this.left))

    if this.left.Len() <this.right.Len() {
        heap.Push(this.left, heap.Pop(this.right))
    }
}


func (this *MedianFinder) FindMedian() float64 {
    if this.left.Len() > this.right.Len() {
		return float64(this.left.data[0])
	}
	return float64(this.left.data[0]+this.right.data[0]) / 2.0
}


/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
