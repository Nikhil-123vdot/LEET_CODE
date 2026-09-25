class Solution {
public:
    void permutation(vector<int>nums,vector<vector<int>>&ans,vector<bool>visited,vector<int>&temp)
    {
        //base case
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                permutation(nums,ans,visited,temp);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool>visited(nums.size(),0);
        vector<int>temp;
        permutation(nums,ans,visited,temp);
        return ans;
    }
};