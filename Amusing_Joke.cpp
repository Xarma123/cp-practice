#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b; 
    
       a= a+b;
    
    string c;
    cin>>c;
    if (a.size() == c.size())
    {
        sort(a.begin(), a.end());
        sort(c.begin(), c.end());
        if (a == c)
            cout << "YES";
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
}