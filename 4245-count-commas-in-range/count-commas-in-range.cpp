class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int a=n;
        while(a >= 1) {
            a = a / 10;
            count++;
        }
        if(count<4)
        {
            return 0;
        }
        int commas=(count-1)/3;
        int minus=1;
        for(int i=0;i<commas;i++)
        {
            minus=minus*1000;
        }
        int amount=n-minus;
        return (commas*amount)+1;
    }
};