#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    lol n, m, last;
    double t, max(0);
    cin >> n >> m;

    for (lol i = 1; i <= n; i++)
    {
        cin >> t;
        if (ceil(t / m) >= max)
        {   cout<<t<<" ";
            last = i;
            max = ceil(t / m);
        }
    }

    cout << last << endl;
    return 0;
}