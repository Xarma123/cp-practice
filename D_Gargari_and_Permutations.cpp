#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> lcs1(vector<lol> &X, vector<lol> &Y)
{
    int m = X.size(), n = Y.size();
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    vector<lol> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs.push_back(X[i - 1]);
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    vector<lol> s, l;
    for (lol i = 0; i < k; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i == 0)
            {
                lol t;
                cin >> t;
                s.push_back(t);
            }
            else
            {
                lol t;
                cin >> t;
                l.clear();
                l.push_back(t);
            }
        } 
        if(i!=0)
        {
            s=lcs1(s,l);
        }
    }
    cout<<s.size();

    return 0;
}