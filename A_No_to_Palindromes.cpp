#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ans = false;
    int ind = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int p = s[i] - 'a' + 1;
        for (int j = p; j < k; j++)
        {
            if ((i >= 1 && j == s[i - 1] - 'a') || (i >= 2 && j == s[i - 2] - 'a'))
                continue;
            s[i] = char(j + 'a');
            ind = i + 1;
            ans = 1;
            break;
        }
        if (ans)
            break;
    }
    if (!ans)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = ind; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if ((i >= 1 && j == s[i - 1] - 'a') || (i >= 2 && j == s[i - 2] - 'a'))
                continue;
            s[i] = char(j + 'a');
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;

 
}