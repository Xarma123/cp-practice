#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    float n, m;
    cin >> n >> m;
    lol ans = 0;
    for (float b = 0; b <= n; b++)
    {
        if (m - b * b >= 0)
        {
            if ((m - b * b) * (m - b * b) + b == n)
            {
                ans++;
            }
        }
    }
    cout << ans;
}