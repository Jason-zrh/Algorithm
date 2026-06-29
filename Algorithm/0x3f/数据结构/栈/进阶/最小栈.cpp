#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MinStack {
public:
    MinStack() {
        _st.emplace(0, INT_MAX);
    }
    
    void push(int val) {
        _st.emplace(val, min(val, getMin()));
    }
    
    void pop() {
        _st.pop();
    }
    
    int top() {
        return _st.top().first;
    }
    
    int getMin() {
        return _st.top().second;
    }
private:
    // 在这个pair中，first保存就是值，second保存的是前i个值中的最小值
    stack<pair<int, int>> _st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */