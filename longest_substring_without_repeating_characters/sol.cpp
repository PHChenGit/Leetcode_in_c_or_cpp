#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // k is the size of sliding window
        int i = 0, j = 0, ans = 0;
        // to record that the last position of the duplicate character
        std::unordered_map<char, int> m;

        for (i = 0; i < s.length(); ++i) {
            if (m.empty() || m.count(s[i]) == 0) {
                m.insert({s[i], i});
            }
            else {
                j = std::max(j, m[s[i]]);
                m[s[i]] = i;
            }
            ans = std::max(ans, i-j);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // test case, excepted result
    std::unordered_map<std::string, int> cases = {
        {"pwwkew", 3},
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"p", 1},
        {"", 0},
        {"abba", 2},
    };
    int res;
    
    // for (auto it = cases.begin(); it != cases.end(); it++) {
    //     res = sol.lengthOfLongestSubstring(it->first);
    //     if (res != it->second) {
    //         std::printf("Case: %s, Failed. output: %d, excepted: %d\n", it->first.c_str(), res, it->second);
    //     } else {
    //         std::printf("Case: %s, Passed.\n", it->first.c_str());
    //     }
    // }
    return 0;
}