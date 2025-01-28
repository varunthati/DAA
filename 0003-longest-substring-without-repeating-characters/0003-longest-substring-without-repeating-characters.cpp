class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // initialize hashSet
        unordered_set<char> hashSet;
        int ans = 0;
        // left pointer at position 0
        int l = 0;
        // right pointer going through every char
        for (int r = 0; r < s.length(); r++) {
            // if we get to a duplicate
            while (hashSet.count(s[r])) {
                // remove left most
                hashSet.erase(s[l]);
                l++;
            }
            hashSet.insert(s[r]);
            // update window size  
            ans = max(ans, r - l + 1);
        }
        return ans;
    }    
};