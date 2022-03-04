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
const double eps=1e-10; 
typedef long long ll;
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
struct Node{
	double x,y,r,s;
};
int n;
double dis(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
vector<int>G[MAXN];
bool vis[MAXN];
vector<Node>v;
void dfs(int u, double &sumx, double &sumy, double &sp, double &pai,int &num){
	if(vis[u])return;
	vis[u]=true;
	num++;
	sumx+=v[u].x;sumy+=v[u].y;
	pai+=v[u].r*v[u].r;
	sp = max(sp,v[u].s);
	for(int i=0;i<G[u].size();i++){
		int t = G[u][i];
		dfs(t,sumx,sumy,sp,pai,num);
	}
}
int main(int argc, char *argv[]) {
	
	gi(n);
	
	for(int i=1;i<=n;i++){
		Node node;
		cin>>node.x>>node.y>>node.r>>node.s;
		v.push_back(node);
	}
	while(v.size()>1){
		double minn = 1e18;
		for(int i=0;i<v.size();i++){
			G[i].clear();
			vis[i]=false;
		}
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<v.size();j++){
				double d = dis(v[i], v[j]);
				double len = d - v[i].r-v[j].r;
				double t;
				if(len<0)
					t = 0.0;
				//t*s1+t*s2 = len
				else t = len/(v[i].s+v[j].s);
				minn = min(minn,t);
			}
		}
		
		
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<v.size();j++){
				double d = dis(v[i], v[j]);
				double len = d - v[i].r-v[j].r;
				//t*s1+t*s2 = len
				double t = len/(v[i].s+v[j].s);
				if(len<0.0){
					G[i].push_back(j);
					G[j].push_back(i);
				}
				else if(abs(t-minn)<eps){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for(int i=0;i<v.size();i++){
			v[i].r+=v[i].s*minn;
		}
		vector<Node>li;
		for(int i=0;i<v.size();i++){
			double sumx=0.0, sumy=0.0, sp=0.0, pai=0.0;
			int num=0;
			
			dfs(i,sumx,sumy,sp,pai,num);
			//if(li.size()==0)continue;
			if(num==0)continue;
			if(num==1)li.push_back(v[i]);
			else{
				Node ne;
				ne.x = sumx/num;
				ne.y = sumy/num;
				ne.s = sp;
				ne.r = sqrt(pai);
				li.push_back(ne);
			}
		}
		v.clear();
		v = move(li);
	}
	printf("%.10lf %.10lf\n%.10lf\n",v[0].x,v[0].y,v[0].r);
	
	
	return 0;
}











