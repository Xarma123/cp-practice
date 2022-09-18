#include <iostream>
using namespace std;
int main()
{
    lol n;
    cin >> n;
   lol k;
    lol X=0, Y=0, Z=0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            cin >>k;
            switch (j)
            {
            case 0:
                X +=k;
                break;
            case 1:
                Y +=k;
                break;
            case 2:
                Z +=k;
                break;
            }
        }
    } 
    if (X==0&&Y==0&&Z==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    
}