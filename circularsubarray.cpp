#include <iostream>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol sum = 0, max = 0;

    extern lol i = 0;
    while (i)
    {
        sum += a[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }  

        if (i<n-1)
        {
            i++;
        } else{
            i=0;
        }
        
    }

    cout << max;
}