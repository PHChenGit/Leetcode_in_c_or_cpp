#include <iostream>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int i = 0, j;
        std::string ans, s2;

        for (j = s.length()-1; j >= 0; --j) {
            s2 += s[j];
        }

        while (i < s.length()) {
            if (s[i] == s2[i]) {
                if (ans.length() < ans.length()+1) {
                    ans += s[i];
                }
            }
            ++i;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::string res;

    res = sol.longestPalindrome("ac");
    int len = res.length();
    std::cout << "res: " << res << " len: " << len << std::endl;
    return 0;
}