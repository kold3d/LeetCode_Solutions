/*
 * [755] Reach a Number
 *
 * https://leetcode.com/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (29.04%)
 * Total Accepted:    5.3K
 * Total Submissions: 18.1K
 * Testcase Example:  '1'
 *
 * 
 * You are standing at position 0 on an infinite number line.  There is a goal
 * at position target.
 * 
 * On each move, you can either go left or right.  During the n-th move
 * (starting from 1), you take n steps.
 * 
 * Return the minimum number of steps required to reach the destination.
 * 
 * 
 * Example 1:
 * 
 * Input: target = 3
 * Output: 2
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second step we step from 1 to 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: target = 2
 * Output: 3
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second move we step  from 1 to -1.
 * On the third move we step from -1 to 2.
 * 
 * 
 * 
 * Note:
 * target will be a non-zero integer in the range [-10^9, 10^9].
 * 
 */
class Solution {
public:
    int reachNumber(int t) {
        if (t < 0) t = -t;
        int i = 2, s = 1;
        while (s < t || (s-t) % 2) s += i++;
        return i-1;
    }
};
