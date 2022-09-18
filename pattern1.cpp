#include<iostream>
#include<conio.h>
using namespace std;
int main(){

    lol a ; 
    cin>>a;lol row=1 ; 
    while(row<=a){lol column=1;

    if (row%2==0)
    {
        cout<<1;
        for (lol i = 1; i < row-1; i++)
        {
            cout<<0;
        }
         cout<<1;



    }
    else
    {
    
    
    
     while (column<=row)
     {
        cout<<1;
        column++;
     }}
     
       row++;
       cout<<endl;
 
        
    }
    
        getch();
        return 0;
}