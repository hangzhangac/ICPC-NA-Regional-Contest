#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define base 360
using namespace std;
const double eps=1e-8; 
typedef long long ll;

using namespace std;


const int MAXN=100005;
const int inf=0x3f3f3f3f;
int a1,a2;
int angle[1005][1005];
class Dijkstra{
public:
	int d[MAXN*11];
	struct edge{
		int to,cost,a;
	};
	typedef pair<int,int>P;
	vector<edge>G[MAXN];
	int n;
	void dijkstra(int s,vector<pair<int,int>>ansd = vector<pair<int,int>>()){
		priority_queue<P, vector<P>, greater<P> >que;
		fill(d, d+n+1, inf);
		if(ansd.size()==0){
			for(int i=0;i<G[s].size();i++){
				auto e = G[s][i];
				int to=e.to,cost = e.cost,a = e.a;
				int des = to*1000+angle[s][to]+base;
				que.push({cost,des});
				d[des]=cost;
			}
		}
		else{
			for(auto &x:ansd){
				que.push({x.first,x.second});
				d[x.second] = x.first;
			}
		}
		
		while(!que.empty()){
			P p=que.top();que.pop();
			int state=p.second;
			if (d[state]<p.first)continue;
			int v = state/1000;
			int cur_a = (state%1000)-base;
			for(int i=0;i<G[v].size();i++){
				edge e=G[v][i];
				int a = e.a;
				int turn1 = a-cur_a;
				if(turn1<0)turn1+=360;
				int turn2 = cur_a-a;
				if(turn2<0)turn2+=360;
				if(turn1<=a1||turn2<=a2){
					int des = e.to*1000+base+angle[v][e.to];
					if(d[des]>d[state]+e.cost){
						d[des]=d[state]+e.cost;
						que.push(P(d[des],des));
					}
				}
			}
		}
		return;
	}
	void add(int x,int y, int c,int a){
		G[x].push_back({y,c,a});
	}
};

int main(int argc, char *argv[]) {
	int n,d;
	Dijkstra dij;
	cin>>n>>d>>a1>>a2;
	dij.n = MAXN*11-1;
	memset(angle, -1, sizeof angle);
	for(int i=1;i<=n;i++){
		int m;gi(m);
		for(int j=1;j<=m;j++){
			int d1,t,a;
			cin>>d1>>t>>a;
			dij.add(i, d1, t, a);
			angle[d1][i] = (a+180)%360;
		}
	}
	
	dij.dijkstra(1);
	int v = d*1000;
	vector<pair<int,int>>ansd;
	for(int i=v;i<v+1000;i++){
		if(dij.d[i]!=inf){
			ansd.push_back({dij.d[i],i});
		}
	}
	if(ansd.size()==0){
		printf("impossible\n");
		return 0;
	}
	dij.dijkstra(1,ansd);
	v = 1*1000;
	int ans = inf;
	for(int i=v;i<v+1000;i++){
		ans=min(ans,dij.d[i]);
	}
	if(ans==inf)printf("impossible\n");
	else printf("%d\n",ans);
	
	
	
	
	return 0;
}











