class Solution 
{
    func lengthOfLongestSubstring(_ s: String) -> Int 
    {
        var last_found: [Character: Int] = [:]
        var start = 0
        var length = 0

        // upper bound for solution
        let distinct = Set(s).count

        // compute lengths of possible combinations
        for i in 0..<s.count
        {
            let index = s.index(s.startIndex, offsetBy: i)
            let value = last_found[s[index]]
            if value != nil && (start <= value!)
            {
                length = max(i - start, length)
                start = value! + 1

                if length == distinct // early exit
                {
                    return length
                }
            }
            last_found[s[index]] = i
        }

        return max(s.count - start, length)
    }
}