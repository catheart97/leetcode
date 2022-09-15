#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

template<typename value_t>
std::ostream & operator<<(std::ostream & os, const std::vector<value_t> & v)
{
    os << "[";
    if (v.size())
    {
        for (size_t i = 0; i < v.size() - 1; ++i) os << v[i] << ", ";
        os << v.back();
    }
    os << "]";
    return os;
}

class Solution 
{
public:
    std::vector<int> findOriginalArray(std::vector<int> & changed)
    {
        if (changed.size() % 2 == 1) return {};

        // allocate result array
        std::vector<int> original;
        original.reserve(changed.size() / 2);

        // sort input
        std::sort(changed.begin(), changed.end());

        // compute machings
        std::unordered_map<int, int> cache;
        for (int V : changed)
        { 
            const int T = V / 2;

            if (!(V % 2) && cache[T])
            {
                cache[T]--;
                original.push_back(T);
            }
            else
                cache[V]++;
        }

        for (const auto & v : cache) if (v.second) return {};
        return original;
    }
};

int main()
{
    std::vector<int> test{ 6,3,0,1 };
    std::cout << Solution().findOriginalArray(test) << std::endl;
}