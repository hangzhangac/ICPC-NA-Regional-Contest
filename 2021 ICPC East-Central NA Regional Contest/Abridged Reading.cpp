#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
vector<int>G[MAXN];
int num[MAXN];
bool in[MAXN];
int ans = inf;
int dfs(int u,int sum){
	
	if(G[u].size()==0)return num[u];
	vector<int>son;
	int minn = inf;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		int t = dfs(v,sum+num[v]);
		son.push_back(t);
		minn = min(minn,t);
	}
	sort(son.begin(), son.end());
	if(son.size()>=2){
		ans=min(ans,son[0]+son[1]+sum);
	}
	return minn+num[u];
	
}
int main(int argc, char *argv[]) {
	int n,m;
	gi2(n, m);
	for(int i=1;i<=n;i++){
		gi(num[i]);
	}
	while(m--){
		int a,b;
		gi2(a, b);
		G[a].push_back(b);
		in[b]=1;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			G[0].push_back(i);
			//cout<<i<<endl;
		}
	}
	dfs(0,0);
	cout<<ans<<endl;
	
	
	return 0;
}











