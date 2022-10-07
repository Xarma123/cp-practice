#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
lol q(string s)
{
    lol mx = 0;
    for (char a = 'a'; a <= 'z'; a++)
    {
        lol v = 0;
        for (auto c : s)
        {
            if (c == a)
                v++;
        }
        mx = max(mx, v);
    }
    for (char a = 'A'; a <= 'Z'; a++)
    {
        lol v = 0;
        for (auto c : s)
        {
            if (c == a)
                v++;
        }
        mx = max(mx, v);
    }

    return mx;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string s1;
    cin >> s1;
    lol m1 = q(s1);
  
    string s2;
    cin >> s2;
    lol m2 = q(s2);
   
    string s3;
    cin >> s3;
    lol m3 = q(s3);
   
    if (n == 1 && m1 == s1.size())
        s1.pop_back();

    if (n == 1 && m2 == s2.size())
        s2.pop_back();

    if (n == 1 && m3 == s3.size())
        s3.pop_back();

    m1 = min((long long)s1.size(), m1 + n);
    m2 = min((long long)s2.size(), m2 + n);
    m3 = min((long long)s3.size(), m3 + n);
    if (m1 > m2 && m1 > m3)
        cout << "Kuro";
    else if (m2 > m1 && m2 > m3)
        cout << "Shiro";
    else if (m3 > m1 && m3 > m2)
        cout << "Katie";
    else
        cout << "Draw";

    return 0;
}