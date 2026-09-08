class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int i = 1000; i <= n; i++) {
            int x = i;
            int digits = 0;

            while (x > 0) {
                x /= 10;
                digits++;
            }

            ans += (digits - 1) / 3;
        }

        return ans;
    }
};