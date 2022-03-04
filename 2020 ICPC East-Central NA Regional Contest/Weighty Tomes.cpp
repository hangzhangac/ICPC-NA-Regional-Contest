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
const int MAXN=200005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;

int main(int argc, char *argv[]) {
	int n,m;
	cin>>n>>m;
	m = min(n, m);
	int dp[n+1][m+1];
	mem(dp,0);
	for(int i=1;i<=n;i++){
		dp[i][1] = i;
	}
	for(int i=1;i<=m;i++){
		dp[1][i] = 1;
	}
	if(m==1){
		cout<<n<<' '<<1<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			int l = 1, r = i;
			while(l<=r){
				int x = (l+r)/2;
				if(dp[x-1][j-1]>=dp[i-x][j]){
					r = x - 1;
				}
				else l = x + 1;
			}
			
			if(l==i+1){
				dp[i][j] = dp[0][j] + 1;
			}
			else{
				int x = l;
				dp[i][j] = dp[x-1][j-1] + 1;
				x--;
				if(x>=0){
					dp[i][j]=min(dp[i][j],dp[i-x][j] + 1);
				}
			}
		}
	}
	
	
	int ans = dp[n][m];
	int t1 = -1,t2 = -1;
	for(int x = 1;x<=n;x++){
		int t = max(dp[n-x][m],dp[x-1][m-1]);
		if(t==ans-1){
			t1 = x;break;
		}
	}
	for(int x = 1;x<=n;x++){
		int t = max(dp[n-x][m],dp[x-1][m-1]);
		if(t==ans-1){
			t2 = x;
		}
	}
	if(t1==t2){
		cout<<ans<<' '<<t1<<endl;
	}
	else cout<<ans<<' '<<t1<<'-'<<t2<<endl;
	return 0;
}











