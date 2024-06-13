class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        const auto is_member = map_[val];
        
        if (is_member) return false;
        else map_[val] = true;

        return true;
    }
    
    bool remove(int val) {
        const auto is_member = map_[val];
        map_.erase(val);

        return is_member;
    }
    
    int getRandom() {
        const int range = map_.size();
        const int num = rand() % range;
        const auto it = std::next(map_.begin(), num);
        return it->first;
    }

private:
    std::unordered_map<int, bool> map_{};
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */