/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (34.35%)
 * Total Accepted:    135.2K
 * Total Submissions: 393.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */
class Solution {
public:
int minDistance(string word1, string word2) 
{
	int row = word1.size();
	int col = word2.size();
    
    if(row == 0 && col == 0 ) return 0;
    
    if(word1.compare(word2) == 0) return 0;
    
	vector<int> p(col+1, 0);

	vector<vector<int>> dist(row+1, p);

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (i == 0)
				dist[i][j] = j;

            else if (j == 0)
				dist[i][j] = i;

			else if (word1[i - 1] == word2[j - 1])
				dist[i][j] = dist[i - 1][j - 1];

			else
				dist[i][j] = 1 + min(dist[i - 1][j - 1], min(dist[i][j - 1], dist[i - 1][j]));
		}
	}
    
	return dist[row][col];
}
    
};
