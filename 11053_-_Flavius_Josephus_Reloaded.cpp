#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, a, b;
void nx(lol &i)
{
    i = ((((i * 1ll * i)%n) *1ll* a)%n + b) % n;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> a >> b;
        lol f = 0, s = 0;

        do
        {
            nx(f);
            nx(f);
            nx(s);
        } while (f != s);
        s = 0;
        while (s != f)
        {
            nx(f);
            nx(s);
        }
        lol c = 0;

        do
        {
            nx(f);
            c++;
        } while (f != s);
        cout << n - c << endl;
    }

    return 0;
}