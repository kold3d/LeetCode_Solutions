/*
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (67.02%)
 * Total Accepted:    51.1K
 * Total Submissions: 76.3K
 * Testcase Example:  '1\n22'
 *
 * 
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 * 
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 * 
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * 
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * 
 * Example 1:
 * 
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 
 * Note:
 * The boundaries of each input argument are 1 .
 * 
 */
class Solution {
public:

vector<int> selfDividingNumbers(int left, int right) 
{
	vector<int> ans;
	for (int i = left; i <= right; i++)
	{
		int num = i;
        
		while (num)
		{
		    if(num%10 == 0) break;
            
            if (i % (num % 10) == 0) num /= 10;
			else
				break;
		}
		if (!num)
		{
			ans.push_back(i);
		}
	}
	return ans;
}
    
};
