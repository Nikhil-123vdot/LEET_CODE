class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int rem;
        int total=0;
        int prefix_sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            rem=prefix_sum %k;
            if(rem<0)
            {
                rem+=k;
            }
            if(mp.count(rem))
            {
                total+=mp[rem];
                mp[rem]++;
            }
            else{
                mp[rem]=1;
            }
        }
        return total;
    }
};