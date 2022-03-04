#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
const int maxn = 200+5; //点的最大值
const int maxm = 100002; //边的最大值
const int inf = 0x3f3f3f3f;
using namespace std;
struct Edge
{
	int v, cap, cost, next;
	int from;
}p[maxm << 1];
int e, sumFlow, m, st, en; //sumFlow记录最大流 n是点的个数
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];
int a[55][110];
int b[55][110];
void init()
{
	e=0;
	sumFlow = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
	p[e].from=u;
	p[e].v = v; p[e].cap = cap; p[e].cost = cost;
	p[e].next = head[u]; head[u] = e++;
	p[e].from=v;
	p[e].v = u; p[e].cap = 0; p[e].cost = - cost;
	p[e].next = head[v]; head[v] = e++;
}
bool spfa(int s,int t, int n)
{
	int u,v;
	queue<int>q;
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	for(int i = 0; i <= n; ++i) 
		dis[i] = inf;
	vis[s] = true;
	dis[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i != -1; i = p[i].next)
		{
			v = p[i].v;
			if(p[i].cap && dis[v] > dis[u] + p[i].cost)
			{
				dis[v] = dis[u] + p[i].cost;
				pre[v] = i;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	if(dis[t] == inf) 
		return false;
	return true;
}
pair<int,int> MCMF(int s,int t,int n)
{
	int flow = 0; // 总流量
	int minflow, mincost;
	mincost=0;
	while(spfa(s,t,n))
	{
		minflow = inf + 1;
		for(int i = pre[t]; i != -1; i = pre[p[i^1].v])
			if(p[i].cap < minflow)
				minflow = p[i].cap;
		flow += minflow;
		for(int i=pre[t];i!=-1;i=pre[p[i^1].v])
		{
			p[i].cap -= minflow;
			p[i^1].cap += minflow;
		}
		mincost += dis[t] * minflow;
	}
	sumFlow = flow; // 最大流
	return {flow, mincost};
}
int n;
pair<int,int> solve(int x,int flag=0){
	init();
	st = 0, en = 4*n+1;
	for(int i=1;i<=n;i++){
		addedge(st, i, 1, 0);
		addedge(3*n+i, en, 1, 0);
		for(int j=1;j<=2*n;j+=2){
			int ai = a[i][j],bi = a[i][j+1];
			if((j+1)/2<=x){
				addedge(i, n+(j+1)/2, 1, ai);
			}
			else addedge(i, n+(j+1)/2, 1, bi);
		}
	}
	for(int i=n+1;i<=2*n;i++){
		addedge(i, i+n, 1, 0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n;j+=2){
			int ai=b[i][j],bi=b[i][j+1];
			if((j+1)/2<=x){
				addedge(2*n+(j+1)/2, 3*n+i, 1, ai);
			}
			else addedge(2*n+(j+1)/2, 3*n+i, 1, bi);
		}
	}
	if(flag==0)return MCMF(st, en, en);
	cout<<MCMF(st, en, en).second<<endl;
	map<int,int>ms;
	for(int i=0;i<e;i++){
		if(p[i].from>=1&&p[i].from<=n&&p[i].v>=n+1&&p[i].v<=2*n&&!p[i].cap){
			ms[p[i].from] = p[i].v;
		}
		if(p[i].from>=2*n+1&&p[i].from<=3*n&&p[i].v>=3*n+1&&p[i].v<=4*n&&!p[i].cap){
			ms[p[i].from-n] = p[i].v-3*n;
		}
	}
	for(int i=1;i<=n;i++){
		int c = ms[i];
		printf("%d %d",i,c-n);
		if(c-n<=x){
			printf("A ");
		}
		else printf("B ");
		printf("%d\n",ms[c]);
	}
	return {0,0};
}
int main(){
	gi(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=2*n;j++)gi(a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=2*n;j++)gi(b[i][j]);
	int ansx = -1;
	int costx = inf;
	for(int x = 0; x<= n;x++){
		auto cur = solve(x);
		if(cur.second<costx){
			ansx = x;
			costx = cur.second;
		}
	}
	solve(ansx,1);
	return 0;
}