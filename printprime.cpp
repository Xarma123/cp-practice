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
 




                



   void prlolallprime(lol N){

                for (lol i = 2; i <=N; i++)
                {
                    if (isprime(i))
                    {
                        cout<<i<<endl;
                    }
                    

                } }int main(){
      lol x;
      cin>>x;
      prlolallprime(x);
      getch();
      return 0;
  }
