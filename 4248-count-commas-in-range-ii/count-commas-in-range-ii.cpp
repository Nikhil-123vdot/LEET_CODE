class Solution {
public:
    long long countCommas(long long n) {
        int count = 0;
        long long a=n;
        while(a >= 1) {
            a = a / 10;
            count++;
        }
        if(count<4)
        {
            return 0;
        }
        int commas=(count-1)/3;
        long long minus=1;
        for(int i=0;i<commas;i++)
        {
            minus=minus*1000;
        }
        long long amount=n-minus;
        long long recent=(commas*amount)+commas;
        long long previous=0;
        long long store=minus;
        commas-=1;
        while(commas>0)
        {
            store=store/1000;
            previous+=(minus-store)*commas;
            commas--;
            minus=minus/1000;
        }
        return previous+recent;
    }
};