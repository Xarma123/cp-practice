#include <bits/stdc++.h>
#define lol long long
using namespace std;

vector<string> ans;
void q(int l, int r, string s)
{
    cout << s << endl;
    if (l == 0 && r == 0)
    {
        stack<char> x;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                x.push('(');
            else
            {
                if (x.top() == '(')
                    x.pop();
                else
                    x.push(')');
            }
        }
        if (x.size() == 0)
            ans.push_back(s);
        return;
    }
    if (l > 0)
    {
        s.push_back('(');
        q(l - 1, r, s);
        s.pop_back();
    }
    if (r > 0)
    {
        s.push_back(')');
        q(l, r - 1, s);
        s.pop_back();
    }
    return;
}

int main()
{
    lol n;
    cin >> n;
    q(n, n, "");

    return 0;
}