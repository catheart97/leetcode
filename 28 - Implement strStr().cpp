class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (!needle.size()) return -1;
        
        for (size_t i = 0; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[0])
            {
                size_t candidate = i;
                bool successful = true;
                for (size_t j = 1; j < needle.size(); ++j)
                {
                    if (haystack[++i] != needle[j])
                    {
                        i = candidate;
                        successful = false;
                        break;
                    }
                }
                
                if (successful)
                    return candidate;
                else
                    continue;
            }
        }
        
        return -1;
    }
};