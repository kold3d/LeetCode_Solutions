/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.40%)
 * Total Accepted:    232.9K
 * Total Submissions: 954.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
bool isMatch(string s, string p) {
	int maxRows = s.size();
	int maxCols = p.size();

	if (maxCols && p[0] == '*') return false;
	
	vector<bool> t(maxCols+1, false);
	vector<vector<bool>> dp(maxRows+1, t);

	dp[0][0] = true;

	for (size_t i = 1; i <= maxCols; i++)
	{
		if (p[i - 1] == '*')
			dp[0][i] = dp[0][i - 2];
	}
    
    for (size_t i = 1; i <= maxRows; i++)
	{
		
			dp[1][0] = false;
	}

	for (int i = 1; i <= maxRows; i++)
	{
		for (int j = 0; j <= maxCols; j++)
		{
			if (s[i-1] == p[j-1] || p[j - 1] == '.')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				if ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j])
					dp[i][j] = true;
				else
					dp[i][j] = dp[i][j-2];
			}
			else
			{
				dp[i][j] = false;
			}
            cout << dp[i][j] << "  ";
		}
        cout << "\n";
	}

	return dp[maxRows][maxCols];
}
};
