/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.78%)
 * Total Accepted:    50.6K
 * Total Submissions: 118.4K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle. 
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * Example 1:
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Note:
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
class Solution {
public:
//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char,int>mp;
//         int count = 0;
//         for(auto e : tasks)
//         {
//             mp[e]++;
//             count = max(count, mp[e]);
//         }
        
//         int ans = (count-1)*(n+1);
//         for(auto e : mp) if(e.second == count) ans++;
//         return max((int)tasks.size(), ans);
//     }
    
    
    int leastInterval(vector<char>& tasks, int n) 
    {

        
                vector<int> map(26,0);
        
        for (char c: tasks)
            map[c - 'A']++;
        
   sort(map.begin(), map.end());
            
        int time = 0;
		
        while (map[25] > 0) 
		{
            int i = 0;
            
            while (i <= n) 
			{
                if (map[25] == 0)
                    break;
                
                if (i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                
                time++;
                i++;
            }
           sort(map.begin(), map.end());
        }
		
		
        return time;
        
    }
    
    
};