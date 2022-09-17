#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <string_view>
#include <set>

template <class value_t>
std::ostream &operator<<(std::ostream &os, const std::vector<value_t> &v)
{
    os << "[";
    if (v.size())
    {
        for (size_t i = 0; i < v.size() - 1; ++i)
            os << v[i] << ", ";
        os << v.back();
    }
    os << "]";
    return os;
}

class Solution
{
    bool palindromeCheck(const std::string &a, const long s, const long e) const noexcept
    {
        long i {s}, j{e};
        while (i < j)
        {
            if (a[i] != a[j]) return false;
            i++; j--;
        }
        return true;
    }

public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words) const noexcept
    {
        std::unordered_map<std::string, size_t> map;
        for (size_t i = 0; i < words.size(); ++i) map[words[i]] = i;

        std::set<std::vector<int>> solution;
        if (map.find("") != map.end())
        {
            size_t j = map[""];
            for (size_t i = 0; i < words.size(); ++i)
            {
                if (i == j) continue;
                if (palindromeCheck(words[i], 0, words[i].size() - 1))
                {
                    solution.insert({int(map[""]), int(i)});
                    solution.insert({int(i), int(map[""])});
                }
            }
        }

        for (size_t i = 0; i < words.size(); ++i)
        {
            if (words[i].size() == 0) continue;

            std::string match{""};
            for (size_t j = 0; j < words[i].size(); ++j)
            {
                match = words[i][j] + match;
                if (map.find(match) != map.end() && map[match] != i && 
                    palindromeCheck(words[i], j + 1, words[i].size() - 1))
                    solution.insert({int(i), int(map[match])});
            }

            match = "";
            for (size_t j = 0; j < words[i].size(); ++j)
            {
                match += words[i][words[i].size() - j - 1];
                if (map.find(match) != map.end() && map[match] != i && 
                    palindromeCheck(words[i], 0, long(words[i].size()) - j - 2))
                    solution.insert({int(map[match]), int(i)});
            }
        }

        std::vector<std::vector<int>> res;
        for (auto & v : solution) res.push_back(v);
        return std::move(res);
    }
};

int main()
{
    std::vector<std::string> words{"abcd", "dcba", "lls", "s", "sssll"};
    std::cout << Solution().palindromePairs(words) << std::endl;

    words = {"bat", "tab", "cat"};
    std::cout << Solution().palindromePairs(words) << std::endl;

    words = {"a", ""};
    std::cout << Solution().palindromePairs(words) << std::endl;
}