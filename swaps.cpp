#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long o[(2 * n)+1], e[(2 * n)+1];
        for (long long i = 0; i < n; i++)
        {
            long long t;
            cin >> t;
            o[t] = i;
        }
        for (long long i = 0; i < n; i++)
        {
            long long t;
            cin >> t;
            e[t] = i;
        }
        long long ans = INT_MAX, cur_ans = INT_MAX;
        for (long long i = 2; i <= 2 * n; i = i + 2)
        {
            cur_ans = e[i];
            for (long long j = 1; j < i; j = j + 2)
            {
                cur_ans += o[j]; 
                ans = min(ans, cur_ans);
                  cur_ans -= o[j]; 
            }
           
        }
        cout << ans << endl;
    }

    return 0;
}