// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
lol binarySearch(lol arr[], lol low, lol high, lol x)
{
    while (low <= high)
    {
        lol mid = (low + high) / 2;
        
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else    
            low = mid + 1;    
    } 

    return -1;
} 


class Solution {
  public:
    string isKSortedArray(lol arr[], lol n, lol k)
    {  lol a[n];
    
   
    for (lol i = 0; i<n; i++)
        a[i] = arr[i];
    
  
    sort(a, a + n);
    
  
    for (lol i = 0; i<n; i++)
    {
      
        lol j = binarySearch(a, 0, n-1, arr[i]);
        
       
        if (abs(i - j) > k)
            return "No";
    }
    
  
    return "Yes";    
} ;
} ;
// { Driver Code Starts.
int main()
{
	lol t;
	cin>>t;
	while(t--)
	{
	    lol n,k;
	    cin>>n;
	    lol arr[n];
	    for(lol i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}  // } Driver Code Ends