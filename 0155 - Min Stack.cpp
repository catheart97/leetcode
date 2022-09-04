#include <forward_list>
#include <tuple>

class MinStack
{
private:
    std::forward_list<std::pair<int, int>> _data; // singly linked list

public:
    MinStack() = default;
    
    void push(int val) { _data.push_front(std::make_pair(val, _data.empty() ? val : std::min(getMin(), val))); }
    
    void pop() { _data.pop_front(); }
    
    int top() { return _data.front().first; }
    
    int getMin() { return _data.front().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */