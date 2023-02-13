#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A;
    cin >> A;
    stack<int> x;
    int ans = 0;
    lol c = 1;
    int l = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(')
        {
            x.push(i);
        }
        else
        {
            if (x.size() == 0)
            {
                l = i;
                continue;
            }
            x.pop();
            if (x.size() == 0)
            {
                if (ans < i - l)
                {
                    ans = i - l;
                    c = 1;
                }
                else if (ans == i - l)
                {
                    c++;
                }
            }
            else
            {
                if (ans < i - x.top())
                {
                    ans = i - x.top();
                    c = 1;
                }
                else if (ans == i - x.top())
                {
                    c++;
                }
            }
        }
    }
    cout << ans << " " << c;

    return 0;
}