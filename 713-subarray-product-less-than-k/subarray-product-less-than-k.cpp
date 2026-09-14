class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int n=nums.size();
        int start=0;
        int end=0;
        int total=0;
        while(end<n)
        {
            product*=nums[end];
            while(product>=k && start<=end)
            {
                product=product/nums[start];
                start++;
            }
            total+=end-start+1;
            end++;
        }
        return total;
    }
};