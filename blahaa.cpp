// C++ program to prlol largest contiguous array sum
#include<iostream>
#include<climits>
#include<conio.h>
using namespace std;

lol maxSubArraySum(lol a[], lol size)
{
	lol max_so_far = INT_MIN, max_ending_here = 0;

	for (lol i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	lol a[] = {1 , 6 , -7 , 1 , 1};
	lol n = sizeof(a)/sizeof(a[0]);
	lol max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
    getch();
	return 0;
}
