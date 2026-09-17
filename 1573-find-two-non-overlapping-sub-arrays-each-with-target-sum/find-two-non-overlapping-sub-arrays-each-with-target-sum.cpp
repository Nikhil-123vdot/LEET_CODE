class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;
        int sum = 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        vector<int> best(n, INT_MAX);
        int minLen = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(mp.count(sum - target)) {
                int start = mp[sum - target] + 1;
                int len = i - mp[sum - target];
                
                if(start > 0 && best[start - 1] != INT_MAX) {
                    ans = min(ans, len + best[start - 1]);
                }
                
                minLen = min(minLen, len);
            }
            
            best[i] = minLen;
            mp[sum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};