#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<lol> arrival;
    vector<lol> departure;
    for (char j = 'A'; j <= 'Z'; j++)
    {
        lol p = -1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == j)
            {
                if (p == -1)
                {

                    arrival.push_back(i);
                }
                p = i;
            }
        }
        if (p != -1)
        {
            departure.push_back(p);
        }
    }
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    lol i = 0;
    lol j = 0;
    lol ans = LONG_LONG_MIN;
    lol c = 0;

    while (i < arrival.size() && j < departure.size())
    {
        if (arrival[i] < departure[j])
        {
            c++;
            i++;
        }
        else if (arrival[i] == departure[j])
        {   
            ans = max(ans, (c + 1));
           
            i++;
            j++;
        }
        else
        {
            c--;
            j++;
        }
        ans = max(ans, c);
    } 
   
    if (ans > k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}