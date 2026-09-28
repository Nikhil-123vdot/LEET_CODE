class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                sum+=1;
            }
            if(s[i]==')')
            {
                sum-=1;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};