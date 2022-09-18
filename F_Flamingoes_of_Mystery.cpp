#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol N;
    cin >> N;
    lol ans[N];

    cout << "? " << 1 << " " << N << endl;
    fflush(stdout);
    lol sum;
    cin >> sum;
    lol i = 2;
    lol sum2 = 0;
    while (1)
    {
        cout << "? " << i << " " << N << endl;
        fflush(stdout);
        lol t;
        cin >> t;
        ans[i - 2] = sum - t - sum2; 
      
        sum2 += ans[i-2];
        i++;
        if (i == N)
            break;
    }
    cout << "? " << 1 << " " << N - 1 << endl;
    fflush(stdout);
    cin >> ans[N - 1];
    ans[N - 1] = sum - ans[N - 1];
    ans[N - 2] = sum - sum2 - ans[N - 1];
    cout << '!';
    fflush(stdout);
    for (lol i = 0; i < N; i++)
    {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}