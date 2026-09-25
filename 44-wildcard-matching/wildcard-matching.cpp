class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;              // string pointer
        int j = 0;              // pattern pointer

        int star = -1;          // last position of '*'
        int match = 0;          // where '*' started matching in s

        while (i < s.size()) {

            // Case 1: normal character or '?'
            if (j < p.size() &&
                (p[j] == '?' || p[j] == s[i])) {

                i++;
                j++;
            }

            // Case 2: '*'
            else if (j < p.size() && p[j] == '*') {

                star = j;

                // Initially '*' matches zero characters
                match = i;

                j++;
            }

            // Case 3: mismatch
            else {

                // No previous '*'
                if (star == -1) {
                    return false;
                }

                // Let previous '*' consume one more character
                j = star + 1;
                match++;
                i = match;
            }
        }

        // Remaining '*' can match empty string
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};