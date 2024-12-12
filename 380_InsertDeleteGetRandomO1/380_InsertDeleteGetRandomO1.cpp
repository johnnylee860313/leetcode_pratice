class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (nums_index.count(val))return false;
        nums_order.push_back(val);
        nums_index[val] = nums_order.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!nums_index.count(val))return false;
        //3,2,5,6 -> 3,6,5,
        //(3,0),(2,1),(5,2),(6,3) -> (3,0),(5,2),(6,1)
        int last = nums_order.back();
        nums_index[last] = nums_index[val];
        nums_order[nums_index[val]] = last;
        nums_order.pop_back();
        nums_index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums_order[rand() % nums_order.size()];
        
    }
private:
    vector<int> nums_order;
    unordered_map<int,int> nums_index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */