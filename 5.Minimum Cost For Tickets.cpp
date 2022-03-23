class Solution
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int n = days.size();
        vector<int>sourav(n+1, INT_MAX);
        sourav[n] = 0;
        int day7, day30, minimum_days,a,b,c;
        for(int i = n-1 ; i>=0 ; --i)
        {
            day7 = day30 = i;
            while(day7 < n && days[day7] < days[i]+7)
            {
                day7++;
            }
            while(day30 < n && days[day30] < days[i]+30)
            {
                day30++;
            }
            a=costs[0]+sourav[i+1];
            b=costs[1]+sourav[day7];
            c=costs[2]+sourav[day30];
            if(a<=b&&a<=c)
            {
                minimum_days=a;
            }
            else if(b<=a&&b<=c)
            {
                minimum_days=b;
            }
            else
            {
                minimum_days=c;
            }
            sourav[i] = minimum_days;
        }
        return sourav[0];
    }
};
