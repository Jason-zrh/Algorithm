#include <stack>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class BrowserHistory {
public:
    vector<string> history;
    int cur;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        // 删除当前页之后的所有前进记录
        history.resize(cur + 1);
        // 加入新访问页面
        history.push_back(url);
        // 当前页变成最后一个
        cur++;
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min((int)history.size() - 1, cur + steps);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
