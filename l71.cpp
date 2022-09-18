#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool searchMatrix(vector<vector<lol>> &matrix, lol target)
{
    lol m = matrix.size() / matrix[0].size();
    lol n = matrix[0].size() / sizeof(lol);
    lol s=0,e=n*m-1;
    while (s<=e)
    {
       lol mi = (s+e)/2;
       if(matrix[mi/n][mi%n]==target)
       return true;
       else if(matrix[mi/n][mi%n]<target)
       s=mi+1;
       else
       e= mi-1;
    } 
    return false;
    




   
}