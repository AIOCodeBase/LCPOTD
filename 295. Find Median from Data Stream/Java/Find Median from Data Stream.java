class MedianFinder {
    PriorityQueue<Integer> lo;
    PriorityQueue<Integer> high;
    public MedianFinder() {
        high = new PriorityQueue<>();
        lo = new PriorityQueue<>((a, b) -> b - a);
    }
    
    public void addNum(int num) {
        lo.add(num);
        high.add(lo.poll());

        if (lo.size() < high.size()){
            lo.add(high.poll());
        }
    }
    
    public double findMedian() {
        if (lo.size() > high.size()){
            return lo.peek();
        }
        return (lo.peek() + high.peek()) * 0.5;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */