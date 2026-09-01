class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> freq(26, 0);

        
        for (char c : p)
            freq[c - 'a']++;

        int left = 0;
        int right = 0;
        int count = p.size();

        while (right < s.size()) {
           
            if (freq[s[right] - 'a'] > 0)
                count--;

            freq[s[right] - 'a']--;
            right++;

           
            if (right - left > p.size()) {
                freq[s[left] - 'a']++;

                if (freq[s[left] - 'a'] > 0)
                    count++;

                left++;
            }

           
            if (count == 0)
                ans.push_back(left);
        }

        return ans;
    }
};
