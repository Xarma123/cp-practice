#include<iostream>
#include<conio.h>
using namespace std; 
int main(){    lol n;
                cin>>n;
                lol a[100]={0};
                for (lol i = 0; i <n; i++)
                {
                    cin>>a[i];
                }
                lol max=a[0];
                lol min=a[0];
                for (lol i = 0; i <n; i++)
                {
                    if (a[i]>=max)
                    {    max=a[i];
                        
                    }if (a[i]<=min)
                    {
                        min=a[i];
                    }
                    
                }cout<<max<<endl;
                cout<<min;
                getch();
                return 0;
                
                




}