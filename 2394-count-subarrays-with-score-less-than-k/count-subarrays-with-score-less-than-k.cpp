class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int n=nums.size();
        long long int prefixSum=0;
        long long int start=0;
        long long int end=0;
        long long int total=0;
        while(end<n)
        {
            prefixSum+=nums[end];
            while(prefixSum*(end-start+1)>=k)
            {
                prefixSum-=nums[start];
                start++;
            }
            total+=end-start+1;
            end++;
        }
        return total;
    }
};