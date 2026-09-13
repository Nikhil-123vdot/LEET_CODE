class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n <= 2)
            return 0;

        vector<int> front(n);
        vector<int> back(n);

       
        front[0] = height[0];

        for(int i = 1; i < n; i++)
        {
            front[i] = max(front[i - 1], height[i]);
        }

        
        back[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            back[i] = max(back[i + 1], height[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int level = min(front[i], back[i]);

            ans += level - height[i];
        }

        return ans;
    }
};