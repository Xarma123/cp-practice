#include <iostream>
using namespace std;
int main()
{
    lol y;
    cin >> y;
    bool a[10] = {true};
    while (++y)
    {
        lol x = y;
        while (x > 0)
        {

            if (a[x % 10])
            {
                a[x % 10] = false;
            }
            else
            {  
                break;
            }
                 

            x= x / 10;
          
           cout<<1;

        }  

        if(x==0) 
        {cout<<y;
        break;
        }
        
         
    }
}
