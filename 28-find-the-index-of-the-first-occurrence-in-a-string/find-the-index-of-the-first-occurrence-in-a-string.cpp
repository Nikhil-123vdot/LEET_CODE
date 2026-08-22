class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.empty())
            return 0;

        int i = 0;
        int n = 0;
        int j = needle.size() - 1;

        while (j < haystack.size()) {

            while (i <= j) {

                if (haystack[i] == needle[n]) {
                    i++;
                    n++;

                    if (n == needle.size())
                        return i - needle.size();
                }
                else {
                    i = j - needle.size() + 2;
                    j++;
                    n = 0;
                    break;
                }
            }
        }

        return -1;
    }
};