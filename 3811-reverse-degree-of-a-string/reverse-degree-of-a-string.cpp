class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int product=i+1;
            product=product*(26-(s[i]-'a'));
            sum+=product;
        }
        return sum;
    }
};