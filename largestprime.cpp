#include<iostream>
#include<conio.h>

using namespace std;bool isprime(lol n){

                for (lol i = 2; i < n; i++)
                {
                    if (n%i==0)
                    {
                      return false;                   }
                    
                }  return true;

}
 




                



   void prlolallprime(){

                for (unsigned long long lol i = 2; i>0; i++)
                {
                    if (isprime(i))
                    {
                        cout<<i<<endl;
                    }
                    

                } }int main(){
     
      prlolallprime();
      getch();
      return 0;
  }
