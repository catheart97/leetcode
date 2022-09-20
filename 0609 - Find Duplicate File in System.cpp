#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

template<class value_t>
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
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string> & paths)
    {
        std::unordered_map<std::string, size_t> indices;
        std::vector<std::vector<std::string>> ans;

        for (std::string & p : paths)
        {
            size_t space = p.find(' ');
            const auto directory = p.substr(0, space);
            std::string r = p.substr(space + 1, p.size());

            do
            {
                space = r.find(' ');
                auto fnc = r.substr(0, space);
                r = r.substr(space + 1, r.size());
                
                auto brc = fnc.find('(');
                auto cnt = fnc.substr(brc, fnc.size() - 3);
                fnc = fnc.substr(0, brc);

                std::string path = directory + '/' + fnc;
                if (auto c = indices.find(cnt); c != indices.end())
                {
                    ans[c->second].push_back(path);
                }
                else
                {
                    indices[cnt] = ans.size();
                    ans.push_back({path});
                }
            }
            while (space != std::string::npos);
        }

        auto m = std::partition(
            ans.begin(), ans.end(),
             [] (const std::vector<std::string> & v) { return v.size() > 1; }
        );
        ans.resize(std::distance(ans.begin(), m));

        return ans;
    }
};

int main()
{
    std::vector<std::string> paths {
        "root/a 1.txt(abcd) 2.txt(efgh)",
        // "root/c 3.txt(abcd)",
        "root/c/d 4.txt(efgh)","root 4.txt(efgh)"
    };

    std::cout << Solution().findDuplicate(paths) << std::endl;
}