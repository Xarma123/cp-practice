#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lol o1 = 0, o2 = 0;
    for (auto c : s1)
    {
        if (c == '1')
            o1++;
    }
    for (auto c : s2)
    {
        if (c == '1')
            o2++;
    }
    if (o1 + (o1 % 2) >= o2)
    {

        cout << "YES";
    }
    else
        cout << "NO";
}