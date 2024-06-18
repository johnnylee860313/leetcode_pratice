//O(n)
class MyCircularQueue {
public:
    MyCircularQueue(int k):data(k) {
        k_sz = k;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        data[(head+size)%k_sz] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        head = (head+1)%k_sz;
        --size;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:data[head];
    }
    
    int Rear() {
        return isEmpty()?-1:data[(head+size-1)%k_sz];
    }
    
    bool isEmpty() {
        return size == 0 ? true:false;
    }
    
    bool isFull() {
        return size == k_sz ? true:false;
    }
private:
    vector<int> data;
    int head = 0;
    int size = 0;
    int k_sz = 0;
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */