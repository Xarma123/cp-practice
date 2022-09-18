#include<iostream>
#include<conio.h>
using namespace std;
int main(){
           lol v;cin>>v;
       lol a[40]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
       lol s, m ,e;
       s=0;e=39;
          while (true)
          {
              m=(s+e)/2;
              if (a[m]==v)
              {    cout<<m;
                  break;
              }
              if (a[m]>v)
              {
                  e=m-1;
                  continue;
              }
                 if (a[m]<v)
                 {
                    s=m+1;
                    continue;
                 }
                    }
          

        






getch();
return 0;










}