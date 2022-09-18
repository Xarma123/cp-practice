#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol even = 0, odd = 0;
    lol cntEven[2], cntOdd[2];
    cntEven[0] = cntEven[1] = cntOdd[0] = cntOdd[1] = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        odd++;
        lol id = s[i] - 'a';
        if (i % 2 == 0)
        {
            odd += cntEven[id];
            even += cntOdd[id];
            cntEven[id]++;
        }
        else
        {
            odd += cntOdd[id];
            even += cntEven[id];
            cntOdd[id]++;
        }
    } 
    cout<<even<<" "<<odd;

    return 0;
}