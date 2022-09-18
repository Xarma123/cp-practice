#include <iostream>
#include <conio.h>
using namespace std;
int main()
{  
     lol l;cin>>l;
    for (lol i = 1; i*i<l*l/2; i++)
{
      lol b= l*l-i*i;
       for (lol j = 0; j <b ; j++)
        {
           if (j*j==b)
           { cout<<j<<" "<<i<<endl;
               break;
           }
           
        }  
}      getch();
return 0;

}