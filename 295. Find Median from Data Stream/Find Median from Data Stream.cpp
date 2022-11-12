class MedianFinder {
public:
    int size;
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() 
    {
           size=0;
    }
    
    void addNum(int num) 
    {
       if(size==0) pq1.push(num);
       else if(size%2==1)
       {
           int x=pq1.top();
           if(num>x) pq2.push(num);
           else 
           {
               pq1.pop();pq1.push(num);
               pq2.push(x);
           }
       }
       else
       {
           int x=pq2.top();
           if(num<x) pq1.push(num);
           else 
           {
               pq2.pop();pq2.push(num);
               pq1.push(x);
           }
       }
     
        size++;
    }
    
    double findMedian() 
    {
       if(size%2==1) return pq1.top();
       else return (double) (pq1.top()+pq2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

