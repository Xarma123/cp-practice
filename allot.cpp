#include <iostream>
using namespace std;
lol search(lol key, lol *a)
{
    for (lol i = 0; i < 8; i++)
    {
        if (a[i] == key)
            return i;
    }  
    return -1;
}
int main()
{
 

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
       lol n; //no of teams
    cin >> n;
    lol a[n][8];
    lol startups[8] = {0};
    string startupsname[8] = {"DhobiLite", "iMumz", "Happy Minds", "Tushions Enterprises", "TradeGrub", "Channilier", "Finlatics", "Stodict"};

    string Given[n];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < 8; j++)
        {
            cin >> a[i][j];
        }
    }  
    lol x;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 1; j <= 8; j++)
        {   

            x = search(j, a[i]);
             if(x==4) continue;
            if (startups[x] < (n / 7))
            {  
                startups[x]++;
                Given[i] = startupsname[x];
                break; 
            }
        }    
    }

    for (lol i = 0; i < n; i++)
    {     
        cout << Given[i] << endl;
    }   
}
