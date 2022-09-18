#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol Solution(vector<lol> &A, lol B)
{
    unordered_map<lol, lol> x;
    x[0] = 1;
    lol s = 0;
    lol ans = 0;
    for (lol i = 0; i < A.size(); i++)
    {
        s = s ^ A[i];
        lol t = s ^ B;
        if (x.count(t))
        {
            ans += x[t];
        }
        x[s]++;
    } 
    return (lol)ans;
}
