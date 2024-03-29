//O(n+reserve+unreserve)
// class SeatManager {
// public:
//     SeatManager(int n) {
//         for(int i = 1;i <= n;++i){
//             minHeap.push(i);
//         }
//     }
    
//     int reserve() {
//         int smallest = minHeap.top();
//         minHeap.pop();
//         return smallest;
//     }
    
//     void unreserve(int seatNumber) {
//         minHeap.push(seatNumber);
//     }
// private:
//     priority_queue<int,vector<int>,greater<int>> minHeap;
// };

//O(reserve+unreserve)
class SeatManager {
 public:
  SeatManager(int n) {}

  int reserve() {
    if (minHeap.empty())return ++num;

    const int minNum = minHeap.top();
    minHeap.pop();
    return minNum;
  }

  void unreserve(int seatNumber) {
    minHeap.push(seatNumber);
  }

 private:
  priority_queue<int, vector<int>, greater<>> minHeap;
  int num = 0;
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */