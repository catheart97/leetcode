class Solution
{
public:   
    bool reorderedPowerOf2(int n)
    {
        std::array<char, 10> counts{};
        while (n)
        {
            counts[n % 10]++;
            n = n / 10;
        }
        
        static std::array<std::array<char, 10>, 35> data {
            std::array<char, 10>{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
            std::array<char, 10>{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 2
            std::array<char, 10>{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
            std::array<char, 10>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 8
            std::array<char, 10>{0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, // 16
            std::array<char, 10>{0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 32
            std::array<char, 10>{0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // 64
            std::array<char, 10>{0, 1, 1, 0, 0, 0, 0, 0, 1, 0}, // 128
            std::array<char, 10>{0, 0, 1, 0, 0, 1, 1, 0, 0, 0}, // 256
            std::array<char, 10>{0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, // 512
            std::array<char, 10>{1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, // 1024 
            std::array<char, 10>{1, 0, 1, 0, 1, 0, 0, 0, 1, 0}, // 2048
            std::array<char, 10>{1, 0, 0, 0, 1, 0, 1, 0, 0, 1}, // 4096
            std::array<char, 10>{0, 1, 1, 0, 0, 0, 0, 0, 1, 1}, // 8192
            std::array<char, 10>{0, 1, 0, 1, 1, 0, 1, 0, 1, 0}, // 16384
            std::array<char, 10>{0, 0, 1, 1, 0, 0, 1, 1, 1, 0}, // 32768
            std::array<char, 10>{0, 0, 0, 1, 0, 2, 2, 0, 0, 0}, // 65536
            std::array<char, 10>{1, 2, 1, 1, 0, 0, 0, 1, 0, 0}, // 131072
            std::array<char, 10>{0, 1, 2, 0, 2, 0, 1, 0, 0, 0}, // 262144
            std::array<char, 10>{0, 0, 2, 0, 1, 1, 0, 0, 2, 0}, // 524288
            std::array<char, 10>{1, 1, 0, 0, 1, 1, 1, 1, 1, 0}, // 1048576
            std::array<char, 10>{1, 1, 2, 0, 0, 1, 0, 1, 0, 1}, // 2097152
            std::array<char, 10>{1, 1, 0, 1, 3, 0, 0, 0, 0, 1}, // 4194304
            std::array<char, 10>{1, 0, 0, 1, 0, 0, 1, 0, 4, 0}, // 8388608
            std::array<char, 10>{0, 2, 1, 0, 0, 0, 2, 3, 0, 0}, // 16777216
            std::array<char, 10>{0, 0, 1, 3, 2, 2, 0, 0, 0, 0}, // 33554432
            std::array<char, 10>{1, 1, 0, 0, 1, 0, 2, 1, 2, 0}, // 67108864
            std::array<char, 10>{0, 2, 2, 1, 1, 0, 0, 2, 1, 0}, // 134217728
            std::array<char, 10>{0, 0, 1, 1, 2, 2, 2, 0, 1, 0}, // 268435456
            std::array<char, 10>{1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, // 536870912
            std::array<char, 10>{1, 2, 1, 1, 2, 0, 0, 2, 1, 0}, // 1073741824
            std::array<char, 10>{0, 1, 1, 1, 3, 0, 1, 1, 2, 0}, // 2147483648
            std::array<char, 10>{0, 0, 2, 0, 2, 0, 2, 1, 0, 3}, // 4294967296
            std::array<char, 10>{0, 0, 1, 1, 1, 2, 0, 0, 2, 3}, // 8589934592
            std::array<char, 10>{0, 3, 0, 0, 1, 0, 1, 2, 2, 2}  // 17179869184
        };

        for (const auto & arr : data)
        {
            bool all_equal = true;
            for (size_t j = 0; j < 10; ++j)
            {
                if (counts[j] != arr[j])
                {
                    all_equal = false;
                    break;
                }
            }
            if (all_equal)
                return true;
        }
        

        return false;
    }
};