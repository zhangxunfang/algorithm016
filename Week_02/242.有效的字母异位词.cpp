/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;
        // map<char, int> s_map, t_map;
        // for (auto c:s)  s_map[c]++;
        // for (auto c:t)  t_map[c]++;

        // if (s_map == t_map) {
        //    return true;
        // } 
        // else {
        //    return false;
        // }
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};
// @lc code=end

