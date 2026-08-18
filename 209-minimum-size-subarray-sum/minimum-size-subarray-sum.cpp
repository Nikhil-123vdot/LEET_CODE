class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int minimum = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum >= target) {
                int len = j - i + 1;
                minimum = min(minimum, len);

                sum -= nums[i];
                i++;
            }
        }

        return minimum == INT_MAX ? 0 : minimum;
    }
};
