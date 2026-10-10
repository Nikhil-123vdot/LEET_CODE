class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> st1;
        stack<char> st2;
        int close = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (!st2.empty()) {
                    ans++;
                    st2.pop();
                }
                st1.push(s[i]);
            }
            else {
                // Check whether two consecutive ')' exist
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else {
                    ans++; // Insert one missing ')'
                }

                if (!st1.empty()) {
                    st1.pop();
                }
                else {
                    ans++; // Insert one missing '('
                }
            }
        }

        ans += st1.size() * 2;

        return ans;
    }
};