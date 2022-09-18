// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long N)
{     if(N==1)return 0;
    long long i = N/2 -1;
    long long j = N/2;
    long long ans=0; 
    
    lol polol = N/2;
    for(lol k=0;k<=i;k++)
    { if(polol!=N)
       { while(arr[polol]<arr[k])
        {
            polol++;
            if(polol==N)
            break;
        }
       } 
       ans+=polol;
    } 
    
    
    
    
    
    
    
    
    while(i>=0&&j<N)
    {
        if(arr[i]>arr[j])
        { 
            swap(arr[i],arr[j]);
            i--;
            j++;
        }
        else
        break;
    } 
    sort(arr,arr+N);
    return ans;
    
    
}
long long lol inversionCount(long long arr[], long long N)
{    if(N==1)return 0;
    long long m = N/2;
    
     long long l = inversionCount(arr,m); 
     long long r = inversionCount(arr+m,N-m); 
     
     long long v = merge(arr,N);
     cout<<l<<" "<<r<<" "<<v<<endl;
     return (l+v+r);
     
     
   
}





};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends