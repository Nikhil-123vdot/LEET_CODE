class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1;
        map<char,int> mp2;

        int n = s.size();
        int m = t.size();

        if(m != n)
            return false;

        for(int i = 0; i < n; i++)
        {
            mp1[s[i]]++;
        }

        for(int i = 0; i < m; i++)
        {
            mp2[t[i]]++;
        }

        for(auto it : mp1)
        {
            if(it.second != mp2[it.first])
                return false;
        }

        return true;
    }
};