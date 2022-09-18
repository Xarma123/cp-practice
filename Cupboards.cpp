#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol l0 = 0, l1 = 0, r0 = 0, r1 = 0, t;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < 2; j++)
        {
            cin >> t;
            if (j == 0)
            {
                if (t == 0)
                    l0++;
                else
                {
                    l1++;
                }
            }
            else
            {
                if (t == 0)
                    r0++;
                else
                {
                    r1++;
                }
            }
        }
    } 

     cout<<min(l0,l1)+min(r0,r1);
     

}