#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string p;
        cin >> p;
        map<lol, lol> liked;
        map<lol, lol> disliked;
        for (lol i = 0; i < n; i++)
        {
            if (p[i] == '1')
                liked[a[i]] = i;
            else
                disliked[a[i]] = i;
        }
        lol rating = n;
        for (auto i = liked.rbegin(); i != liked.rend(); i++)
        {   
            a[(*i).second] = rating;
            rating--;
        } 
        for (auto i = disliked.rbegin(); i != disliked.rend(); i++)
        {
            a[(*i).second] = rating;
            rating--;
        }  
        for (lol i = 0; i < n; i++)
        {  
           cout<<a[i]<<" ";
        } 
        cout<<endl;
        

    }

    return 0;
}