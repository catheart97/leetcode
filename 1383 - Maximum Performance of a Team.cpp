#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <list>

class Solution
{
public:
    int maxPerformance(const int n, std::vector<int> & speed, std::vector<int> & efficiency, const int k) const
    {
        // sort engineers by their efficiency
        std::vector<int> engineers(n);
        std::iota(engineers.begin(), engineers.end(), 0);
        std::sort(engineers.begin(), engineers.end(), [&] (const int l, const int r) {
            return efficiency[l] > efficiency[r];
        });

        // keep the max sum of all speeds up to engineer i, and their summands
        long sum{0}, perf{0};
        std::priority_queue<int, std::vector<int>, std::greater<int>> summands;
        for (size_t i : engineers)
        {
            const int e {efficiency[i]}, s {speed[i]};

            if (summands.size() == k)
            {
                const int min = summands.top();
                if (min >= s) continue;
                sum -= min;
                summands.pop();
            }

            sum += s;
            summands.push(s);

            perf = std::max(sum * e, perf);
        }

        return perf % long(1e9 + 7);
    }
};