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
        std::unordered_map<std::string_view, std::vector<std::string>> contents;

        for (std::string & p_ : paths)
        {
            std::string_view p(p_);
            size_t space = p.find(' ');
            const auto directory = p.substr(0, space);
            auto r = p.substr(space + 1, p.size());

            do
            {
                space = r.find(' ');
                auto fnc = r.substr(0, space);
                r = r.substr(space + 1, r.size());
                
                const auto brc = fnc.find('(');
                const auto cnt = fnc.substr(brc, fnc.size() - 3);
                fnc = fnc.substr(0, brc);

                contents[cnt].push_back(std::string(directory) + '/' + std::string(fnc));
            }
            while (space != std::string::npos);
        }

        std::vector<std::vector<std::string>> ans;
        ans.reserve(contents.size());
        for (auto & c : contents) 
            if (c.second.size() > 1) 
                ans.push_back(std::move(c.second));

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