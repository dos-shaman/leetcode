#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class Temp> struct comparator {

    bool operator()( Temp a , Temp b)
    {   
        // in case both have different score return the one with greater score
        if( a.first != b.first)
        {
            return a.first > b.first;
        }
        // incase of same score return lexographically smallest 
        return a.second < b.second;
    }
};

template <class Temp> using pbds =  tree<Temp, null_type, comparator<Temp>, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
public:
    
    pbds<pair<int,string>>st;
    int current = 0;
    SORTracker() {
        current = 0;
    }
    
    void add(string name, int score) {
        st.insert({score , name});
    }
    
    string get() {

        pair<int,string>data = *st.find_by_order(current);
        current += 1;

        return data.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */