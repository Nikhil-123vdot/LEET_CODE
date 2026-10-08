class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        int n=s.size();
        int logic=1;
        int i=0;
        int j=i+1;
        while(i<n && j<n)
        {
            if(s[j]=='(')
            {
                logic+=1;
                j++;
            }
            if(s[j]==')')
            {
                logic-=1;
                if(logic==0)
                {
                    for(int p=i+1;p<j;p++)
                    {
                        temp+=s[p];
                    }
                    logic=1;
                    i=j+1;
                    j=i+1;
                }
                else{
                    j++;
                }
            }
        }
        return temp;
    }
};