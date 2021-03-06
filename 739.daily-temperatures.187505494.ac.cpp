/*
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (56.28%)
 * Total Accepted:    34.8K
 * Total Submissions: 61.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */
class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) 
{
	vector<int> ans;
	bool found = false;
    
    int max = INT_MIN;
	for (int i = 0; i < temperatures.size(); i++)
	{
        if(temperatures[i] > max)  max = temperatures[i];
    }

	for (int i = 0; i < temperatures.size(); i++)
	{
		
        if(max > temperatures[i]) // Search only if this is not a max temparature.
        {
        
            for (int j = i; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    ans.push_back(j - i);
                    found = true;
                    break;
                }
            }
            if(!found)ans.push_back(0);
            found = false;
        }
        else
        {
            ans.push_back(0);   
        }
	}
	return ans;
}
};
