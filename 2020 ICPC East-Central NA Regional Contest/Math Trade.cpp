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
const int MAXN=105;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
unordered_map<string,int>ms1;
string a[MAXN],b[MAXN],c[MAXN];
int h[MAXN];
int level[MAXN];
int cur[MAXN];
int main(int argc, char *argv[]) {
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		//ms[a[i]] = i;
		ms1[b[i]] = i;
		//ms2[c[i]] = i;
	}
	for(int i=1;i<=n;i++){
		if(ms1[c[i]]){
			h[i] = ms1[c[i]];
		}
	}
	int t = 0;
	int ans = 1;
	for(int j=1;j<=n;j++){
		int i = j;
		if(cur[i]==0){
			t++;
			int q = 1;
			while(i!=0&&cur[i]==0){
				level[i]=q++;
				cur[i] = t;
				i = h[i];
			}
			if(i==0)continue;
			if(cur[i]!=t)continue;
			ans=max(ans,q-1);
		}
	}
	if(ans==1){
		cout<<"No trades possible"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	
	
	
	
	
	return 0;
}











