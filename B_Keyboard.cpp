#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30+5;
bool can[maxn],canb[maxn];//can为1表示小写出现，大写为1表示不需要两只手
char in[maxn][maxn];
char tmp[500005];
int main()
{
int n,m,x;
scanf("%d%d%d",&n,&m,&x);
for(int i=0;i<n;i++) scanf("%s",in[i]);
bool has=false;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
if(in[i][j]=='S')
{
has=true;
for(int k=0;k<n;k++)
for(int l=0;l<m;l++)
if((k-i)*(k-i)+(l-j)*(l-j)<=x*x&&in[k][l]!='S')
canb[in[k][l]-'a']=1;
}
else can[in[i][j]-'a']=1;
int q,i,ans=0;
scanf("%d%s",&q,tmp);
for(i=0;i<q;i++)
if(tmp[i]>='A'&&tmp[i]<='Z')
{
if(!has) break;
if(canb[tmp[i]-'A']){}
else if(can[tmp[i]-'A']) ans++;
else break;
}
else if(can[tmp[i]-'a']) {}
else break;
if(i<q) printf("-1\n");
else printf("%d\n",ans);
return 0;
}