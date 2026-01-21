#include <iostream>
#include <stack>


using namespace std;

// 差分 - 夯

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



// 维护双栈 - 人上人
class MinStack {
public:
    stack<int> data;
    stack<int> min;
    // 不单独维护最小元素。查找最小栈栈顶
    MinStack() {
    }

    void push(int val) {
        // data插入
        data.push(val);
        // min插入。若当前min空或最小元素（min栈顶）大于val，插入val
        if (min.empty() || val < min.top()) {
            min.push(val);
        }
        else {
            min.push(min.top());
        }
    }

    void pop() {
        if (!data.empty() && !min.empty()) {
            data.pop();min.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};