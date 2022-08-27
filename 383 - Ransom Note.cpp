class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::array<int, 26> magazine_letters{};
        for (auto c : magazine) magazine_letters[c - 'a'] += 1;
        
        for (auto c : ransomNote)
        {
            auto val = magazine_letters[c - 'a'];
            if (val) magazine_letters[c - 'a'] -= 1;
            else return false;
        }
        
        return true;
    }
};