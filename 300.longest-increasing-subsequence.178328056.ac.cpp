/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.29%)
 * Total Accepted:    157.3K
 * Total Submissions: 400.3K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
int lengthOfLIS(vector<int>& nums) 
{
	if(!nums.size()) return 0;
    vector<int> dp(nums.size(), 1);
	int maximum = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((nums[i] > nums[j]) && ( (dp[j] + 1) > dp[i]))
			{
				dp[i] = dp[j] + 1;
				maximum = max(maximum, dp[i]);
			}
				
		}
	}
    return maximum;
}
};
