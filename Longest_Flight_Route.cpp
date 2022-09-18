#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool visited[100001];
lol child[100001];
lol dist[100001];
bool flag[100001];
vector<lol> v[100001];
void dfs(lol src)
{
	visited[src] = true;
	for (lol i = 0; i < v[src].size(); i++)
	{
		if (!visited[v[src][i]])
			dfs(v[src][i]);
		flag[src] |= flag[v[src][i]];
		if (dist[src] < dist[v[src][i]] + 1 && flag[v[src][i]])
		{
			dist[src] = dist[v[src][i]] + 1;
			child[src] = v[src][i];
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lol n, m;
	cin >> n >> m;
	while (m--)
	{
		lol a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	flag[n] = true;
	dfs(1);
	if (dist[1] == 0)
		cout << "IMPOSSIBLE";
	else
	{
		cout << dist[1] + 1 << '\n';

		lol c = 1;
		while (1)
		{
			cout << c << " ";
			if (c == n)
				break;
			c = child[c];
		}
	}

	return 0;
}