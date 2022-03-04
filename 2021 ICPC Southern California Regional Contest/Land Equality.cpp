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
typedef unsigned long long ll;
const int MAXN=65;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
unordered_map<unsigned int,int>ms;
unsigned int a[MAXN][MAXN];
int n,m;
ll solve(){
	if(n==1){
		ll ans = 1ULL<<63;
		//cout<<ans<<endl;
		ll pre = 1;
		for(int i=0;i<m-1;i++){
			pre*=a[0][i];
			ll suf = 1;
			for(int j=i+1;j<m;j++){
				suf*=a[0][j];
			}
			if(suf>pre) ans=min(ans,suf-pre);
			else ans=min(ans,pre-suf);
		}
		return ans;
	}
	if(ms[0]>=2) return 0;
	if(ms[0]==1){
		if(ms[1])return 1;
		else return 2;
	}
	else{//no 0
		//if(ms[2]==0)return 0;
		if(ms[2]%2==0)return 0;
		int t = ms[2]/2;
		return 1ULL<<t;
	}
}
int main(int argc, char *argv[]) {
	
	cin>>n>>m;
	if(m==1)swap(n, m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			ms[a[i][j]]++;
		}
	}
	cout<<solve()<<endl;
	
	
	
	
	return 0;
}











