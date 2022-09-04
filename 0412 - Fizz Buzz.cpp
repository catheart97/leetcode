class Solution
{
public:
    vector<string> fizzBuzz(int n) const noexcept
    {
        std::vector<std::string> result(n);
        for (int i = 1; i <= n; ++i)
        {
            const int i3{!(i % 3)}, i5{!(i % 5)};
            if (i3 && i5) result[i - 1] = "FizzBuzz";
            else if (i3) result[i - 1] = "Fizz";
            else if (i5) result[i - 1] = "Buzz";
            else result[i - 1] = std::to_string(i);
        }
        return std::move(result);
    }
};