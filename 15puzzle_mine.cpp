#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
const ll N = 1e6;

int m = 0, n = 4;

int cost(int temp[10][10], int t[10][10])
{
	int i, j, m = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (temp[i][j] != t[i][j])
				m++;
		}
	return m;
}

int check(int a[10][10], int t[10][10])
{
	int i, j, f = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] != t[i][j])
				f = 0;
	return f;
}

void solve()
{
	int p, i, j, n = 4, input[10][10], target[10][10], temp[10][10], r[10][10];
	int m = 0, start = 0, end = 0, ans = 1000, dmin = 0, l = 0;

	printf("\nEnter the matrix to be solved,space with zero :\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> input[i][j];
		}
	}

	printf("\nEnter the target matrix,space with zero :\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> target[i][j];
		}
	}

	printf("\nEntered Matrix is :\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << input[i][j] << " ";
		}

		cout << endl;
	}

	printf("\nTarget Matrix is :\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << target[i][j] << " ";
		}
		cout << endl;
	}

	while (!(check(input, target)))
	{
		l++;
		ans = 1000;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (input[i][j] == 0)
				{
					start = i;
					end = j;
				}
			}
		}

		// To move upwards
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				temp[i][j] = input[i][j];

		if (start != 0)
		{
			p = temp[start][end];
			temp[start][end] = temp[start - 1][end];
			temp[start - 1][end] = p;
		}

		m = cost(temp, target);
		dmin = l + m;

		if (dmin < ans)
		{
			ans = dmin;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					r[i][j] = temp[i][j];
		}

		// To move downwards***************************************
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				temp[i][j] = input[i][j];

		if (start != n - 1)
		{
			p = temp[start][end];
			temp[start][end] = temp[start + 1][end];
			temp[start + 1][end] = p;
		}

		m = cost(temp, target);
		dmin = l + m;

		if (dmin < ans)
		{
			ans = dmin;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					r[i][j] = temp[i][j];
		}

		// To move right side***********************************
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				temp[i][j] = input[i][j];

		if (end != n - 1)
		{
			p = temp[start][end];
			temp[start][end] = temp[start][end + 1];
			temp[start][end + 1] = p;
		}

		m = cost(temp, target);
		dmin = l + m;

		if (dmin < ans)
		{
			ans = dmin;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					r[i][j] = temp[i][j];
		}

		// To move left*************************************
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				temp[i][j] = input[i][j];

		if (end != 0)
		{
			p = temp[start][end];
			temp[start][end] = temp[start][end - 1];
			temp[start][end - 1] = p;
		}

		m = cost(temp, target);
		dmin = l + m;

		if (dmin < ans)
		{
			ans = dmin;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					r[i][j] = temp[i][j];
		}

		printf("\nCalculated Intermediate Matrix Value :\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cout << r[i][j] << " ";
			cout << endl;
		}

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				input[i][j] = r[i][j];
				temp[i][j] = 0;
			}
		cout << "Maximum cost: " << ans << endl;
	}
}

int main()
{

	solve();

	return 0;
}
