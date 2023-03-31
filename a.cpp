#include <bits/stdc++.h>
using namespace std;
int pw(int a, int b)
{
    int r = 1;
    while (b > 0)
    {
        if (b % 2)
            r = r * 1ll * a;
        a = a * 1ll * a;
        b /= 2;
    }
    return r;
}
int decimal2Binary(int num)
{

    int ans = 0;
    int p = 0;
    while (num > 0)
    {
        ans += ((num % 2) * 1ll * pw(10, 2));
        num /= 2;
        p++;
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;
    cout << decimal2Binary(N);
    return 0;
}