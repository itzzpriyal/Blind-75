class Solution {
    public:
         int characterReplacement(string s, int k) {
            unordered_map<char, int> mp;
            int ans = 0;
            int left = 0;
            int right = 0;
            int maxf = 0;
    
            for (right = 0; right < s.size(); right++) {
                mp[s[right]]++;
                maxf = max(maxf, mp[s[right]]);
    
                if ((right - left + 1) - maxf > k) { //window trim
                   mp[s[left]] -= 1;
                    left++;
                } else {
                    ans = max(ans, (right - left + 1));
                }
            }
    
            return ans;
        }
    };