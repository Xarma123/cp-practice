#include <bits/stdc++.h>
#define lol long long
using namespace std;
int Solution(vector<int> &A)
{
    int c[A.size() + 1];

    c[0] = 0;
    for (int i = 0; i < A.size(); i++)
    {
        c[i + 1] = c[i] + A[i];
    }
    int dp[A.size()][A.size()];
    for (int k = 0; k < A.size(); k++)
    {
        for (int i = 0, j = k; i < A.size() && j < A.size(); j++, i++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else if (i == j - 1)
            {
                dp[i][j] = A[i] + A[j];
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int q = i; q < j; q++)
                {

                    dp[i][j] = min(dp[i][q] + dp[q + 1][j] - c[i] + c[j + 1], dp[i][j]);
                }
            }
        }
    }
    return dp[0][A.size() - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(7);
    cout << Solution(A);

    return 0;
}