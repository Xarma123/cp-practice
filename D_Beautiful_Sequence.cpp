#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d;
    cin >> a >> b >> c >> d;
    // 0 1 0 1 0 1
    // b>=a-1
    // b=a-1 end with 0
    // else end with 1
    // 2 1 2 1 2 1 2 3 2 3 2 3 2
    // 0 1 0 1 0 1 0 1 2 1 2 1 2 1 2 3 2 3 2 3 2 3
    lol A = a, B = b, C = c, D = d;
    vector<lol> ans(a + b + c + d);
    if (a)
    {
        a--;
        ans[0] = 0;
        lol i;
        for (i = 1; i < ans.size(); i++)
        {
            lol v = ans[i - 1];
            if (v == 0)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else
                    break;
            }
            else if (v == 1)
            {
                if (a)
                {
                    ans[i] = 0;
                    a--;
                }
                else if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
            else if (v == 2)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else if (d)
                {
                    ans[i] = 3;
                    d--;
                }
                else
                    break;
            }
            else if (v == 3)
            {
                if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
        }
        if (i == ans.size())
        {
            cout << "YES\n";
            for (auto e : ans)
                cout << e << " ";
            return 0;
        }
    }
    a = A, b = B, c = C, d = D;
    if (b)
    {
        b--;
        ans[0] = 1;
        lol i;
        for (i = 1; i < ans.size(); i++)
        {
            lol v = ans[i - 1];
            if (v == 0)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else
                    break;
            }
            else if (v == 1)
            {
                if (a)
                {
                    ans[i] = 0;
                    a--;
                }
                else if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
            else if (v == 2)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else if (d)
                {
                    ans[i] = 3;
                    d--;
                }
                else
                    break;
            }
            else if (v == 3)
            {
                if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
        }
        if (i == ans.size())
        {
            cout << "YES\n";
            for (auto e : ans)
                cout << e << " ";
            return 0;
        }
    }
    a = A, b = B, c = C, d = D;
    if (c)
    {
        c--;
        ans[0] = 2;
        lol i;
        for (i = 1; i < ans.size(); i++)
        {
            lol v = ans[i - 1];
            if (v == 0)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else
                    break;
            }
            else if (v == 1)
            {
                if (a)
                {
                    ans[i] = 0;
                    a--;
                }
                else if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
            else if (v == 2)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else if (d)
                {
                    ans[i] = 3;
                    d--;
                }
                else
                    break;
            }
            else if (v == 3)
            {
                if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
        }
        if (i == ans.size())
        {
            cout << "YES\n";
            for (auto e : ans)
                cout << e << " ";
            return 0;
        }
    }
    a = A, b = B, c = C, d = D;
    if (d)
    {
        d--;
        ans[0] = 3;
        lol i;
        for (i = 1; i < ans.size(); i++)
        {
            lol v = ans[i - 1];
            if (v == 0)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else
                    break;
            }
            else if (v == 1)
            {
                if (a)
                {
                    ans[i] = 0;
                    a--;
                }
                else if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
            else if (v == 2)
            {
                if (b)
                {
                    ans[i] = 1;
                    b--;
                }
                else if (d)
                {
                    ans[i] = 3;
                    d--;
                }
                else
                    break;
            }
            else if (v == 3)
            {
                if (c)
                {
                    ans[i] = 2;
                    c--;
                }
                else
                    break;
            }
        }
        if (i == ans.size())
        {
            cout << "YES\n";
            for (auto e : ans)
                cout << e << " ";
            return 0;
        }
    }
    cout << "NO";
}