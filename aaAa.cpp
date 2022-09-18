     #include<iostream>
     using namespace std;

         lol  k = 1;
bool isLucky(lol n) {
        
         k++;
         
         
         if(n%k==0)
         return 0;
         
         
          if(k>n)
         return 1;
        
         isLucky((n-n/k));
         
          
         
           
} 
int main()
{
    cout<<isLucky(96);
}