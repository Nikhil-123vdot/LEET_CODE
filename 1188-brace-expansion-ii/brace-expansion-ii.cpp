class Solution {
public:

    // expression = term { , term }
    set<string> expression(string &s, int &i) {

        set<string> ans = term(s, i);

        while (i < s.size() && s[i] == ',') {
            i++;  // skip ','

            set<string> next = term(s, i);

            ans.insert(next.begin(), next.end());
        }

        return ans;
    }

    // term = factor factor factor...
    // Adjacent factors are concatenated
    set<string> term(string &s, int &i) {

        set<string> ans = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> cur = factor(s, i);

            set<string> temp;

            // Cartesian product = concatenation
            for (const string &a : ans) {
                for (const string &b : cur) {
                    temp.insert(a + b);
                }
            }

            ans = temp;
        }

        return ans;
    }

    // factor = word OR { expression }
    set<string> factor(string &s, int &i) {

        set<string> ans;

        if (s[i] == '{') {

            i++;  // skip '{'

            ans = expression(s, i);

            i++;  // skip '}'

        }
        else {

            string word;

            while (i < s.size() && isalpha(s[i])) {
                word += s[i];
                i++;
            }

            ans.insert(word);
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = this->expression(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};