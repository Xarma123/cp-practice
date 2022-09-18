#include <bits/stdc++.h>
#define lol long long
using namespace std;

class Solution
{
public:
    lol majorityElement(vector<lol> &nums)
    {   lol i,n=nums.size() ;
        for ( i = 0; i < nums.size(); i++)
        {
            lol c = 1;
            for (lol j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == nums[i])
                {
                    c++;
                    nums.erase(nums.begin() + j);
                    j--;
                } 

            }  
            if(c>(n/2))
            break;

        } 
        return nums[i];
    }
};