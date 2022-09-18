#include <iostream>
using namespace std;
lol mul(lol a  , lol b)
{   if(b==0|a==0)return 0;
     if (b<0)
     {
         b= -b;
         a=-a;
     }
     return (  a + mul(a,b-1)               );
     

}
int main()
{ while (1)
{
  lol a , b ; cin>>a>>b;
  cout<<mul(a,b);
}


}