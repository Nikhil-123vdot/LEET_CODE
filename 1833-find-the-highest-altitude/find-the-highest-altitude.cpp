class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>addo;
        int sum=0;
        addo.push_back(0);
        for(int i=0;i<gain.size();i++)
        {
            sum=sum+gain[i];
            addo.push_back(sum);
        }
        int maxe=INT_MIN;
        for(int i=0;i<addo.size();i++)
        {
            maxe=max(addo[i],maxe);
        }
        return maxe;
    }
};