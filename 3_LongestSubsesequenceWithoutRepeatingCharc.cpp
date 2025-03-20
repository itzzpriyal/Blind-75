// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     int l=0;
//     int maxlen=0;
//     int len=0;
//     unordered_map<int, int> mp;
//      for (int i = 0; i < 255; i++) {
//         mp[i] = -1;
//     }   
   
//      for(int i=0;i<s.size();i++){
        
//         if(mp[int(s[i])]== -1){
//             mp[int(s[i])]=i;
//             cout<<" i : "<<i;
//             cout<<" l : "<<l;
//             len=i-l+1;
//             maxlen=max(maxlen,len);
//             cout<<" len : "<<len;
//             cout<<" s[i]: "<<s[i]<<" : "<<mp[int(s[i])]<<endl;
            
//         }
//         else{
//             l = max(l, mp[s[i]] + 1);
//              len=i-l+1;
//             cout<<" i : "<<i;
//             cout<<" l : "<<l;
//             cout<<" len : "<<len;
//             maxlen=max(maxlen,len);
//             l=mp[int(s[i])]+1;
//             cout<<" new l "<<l;
//             mp[int(s[i])]=i;
//             cout<<" "<<s[i]<<" : "<<mp[int(s[i])]<<endl;
//         }
//     }
//     return maxlen;

//     }
// };
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0;
            int maxlen = 0;
            unordered_map<char, int> mp;
    
            for (int i = 0; i < s.size(); i++) {
                if (mp.find(s[i]) != mp.end()) {
                    l = max(l, mp[s[i]] + 1);  // Ensure l only moves forward
                }
    
                mp[s[i]] = i;  // Update the last seen index of s[i]
                maxlen = max(maxlen, i - l + 1);
            }
    
            return maxlen;
        }
    };