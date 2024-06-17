// class StockSpanner {
// public:
//     StockSpanner() {}
    
//     int next(int price) {
//         if(prices_.empty()||price < prices_.back())dp_.push_back(1);
//         else{
//             int j = prices_.size()-1;
//             while(j >= 0 && price >= prices_[j]){
//                 j -= dp_[j];
//             }
//             dp_.push_back(prices_.size() - j);
//         }
//         prices_.push_back(price);
//         return dp_.back();
//     }
// private:
//     vector<int> dp_;
//     vector<int> prices_;
// };


//O(n)
class StockSpanner {
public:
  StockSpanner() {}
 
  int next(int price) {
    int span = 1;
    while (!s_.empty() && price >= s_.top().first) {
      span += s_.top().second;  
      s_.pop();
    }
    s_.emplace(price, span);//push
    return span;
  }
private:
  stack<pair<int, int>> s_; // {price, span}, ordered by price DESC.
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */