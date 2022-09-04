public class Solution
{
    private int[] _dp;

    private int RobHouse(in int[] nums, in int idx)
    {
        if (idx < 0) return 0;
        if (_dp[idx] != -1) return _dp[idx];
        return _dp[idx] = System.Math.Max(RobHouse(nums, idx - 1), nums[idx] + RobHouse(nums, idx - 2));
    }

    public int Rob(in int[] nums)
    {
        _dp = new int[nums.Length];
        System.Array.Fill(_dp, -1);
        return RobHouse(nums, nums.Length - 1);
    }
}