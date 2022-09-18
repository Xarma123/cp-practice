#include <iostream>
using namespace std;
int main()
{
    long long lol t;
    cin >> t;
    while (t--)
    {

        long long lol n;
        cin >> n;
        string a;
        cin >> a;
        long long lol k3 = 0, k7 = 0, i; bool l=true;
        for (i = 0; i < n; i++)
        { 
        if (a[i] == '1' || a[i] == '4' || a[i] == '6' || a[i] == '8' || a[i] == '9')
            {       
                cout << 1 << endl;
                cout << a[i]; l=false;
                break; 
            }
        } 
        if(l)
      {  for (i = 0; i < n; i++)
        {
            
            if ((i != 0) && (a[i] == '2'))
            {
                cout << 2 << endl;
                cout << a[i - 1] << a[i];
                break;
            }
            if ((i != 0) && (a[i] == '5'))
            {
                cout << 2 << endl;
                cout << a[i - 1] << a[i];
                break;
            }
            if (a[i] == '3')
            {
                k3++;
            }
            if (a[i] == '7')
            {
                k7++;
            }
            if (k3 > 1)
            {
                cout << 2 << endl;
                cout << 33;
                break;
            }
            if (k7 > 1)
            {
                cout << 2 << endl;
                cout << 77;
                break;
            }
        }
        if (i == n)
        {
            cout << 2 << endl;
            if (a == "237")
                cout << 27;
            else if (a == "273")
                cout << 27;
            else if (a == "537")
                cout << 57;
            else if (a == "573")
                cout << 57;
            else
            {
               
                cout<<a;
            }
            
        }  
      }
        cout<<endl;
    }
}