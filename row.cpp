#include <iostream>

using namespace std;

int main()
{
    lol n;
    cin >> n;
    for (lol r = 0; r < n+1; r++)
    {   lol k = n;
        for (lol c = 0; c < r + 1; c++)
        {
            cout << k;
            k--;
        }   

        cout.width(2*n-2*r);
         for (lol c = 0; c < r + 1; c++)
        {      k++;
            if(k!=0)
            cout << k;
           
        }  

          cout<<endl;
    }  

     for (lol r = n-1; r >=0; r--)
    {   lol k = n;
        for (lol c = 0; c < r + 1; c++)
        {
            cout << k;
            k--;
        }   

        cout.width(2*n-2*r);
         for (lol c = 0; c < r + 1; c++)
        {      k++;
            if(k!=0)
            cout << k;
           
        }  

          cout<<endl;
    }  
     

    return 0;
}