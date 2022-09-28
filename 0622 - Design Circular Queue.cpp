#include <vector>

class MyCircularQueue
{
    std::vector<int> _data;
    size_t _i{0}, _n{0};
    const size_t _N;

public:
    MyCircularQueue(int k) : _N(k), _data(k) {}

    bool enQueue(int value)
    {
        if (_n == _N) return false;

        _i = (_i + _N + 1) % _N;
        _data[_i] = value;
        _n++;

        return true;
    }

    bool deQueue()
    {
        if (_n == 0) return false; 
        _n--;
        return true;
    }

    int Rear()
    {
        return (_n > 0) ? _data[ _i ] : -1;
    }

    int Front()
    {
        return (_n > 0) ? _data[ (_i + _N - _n + 1) % _N ] : -1;
    }

    bool isEmpty()
    {
        return _n == 0;
    }

    bool isFull()
    {
        return _n == _N;
    }
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