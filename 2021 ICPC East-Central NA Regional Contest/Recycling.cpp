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
const int MAXN=100005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
unsigned long long a[MAXN];
int lef[MAXN];
int righ[MAXN];
int main(int argc, char *argv[]) {
	int n;
	gi(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	a[0]=0;
//	a[n+1]=0;
	stack<int>s;
	//s.push(0);
	for(int i=1;i<=n;i++){
		while(!s.empty()&&a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty())lef[i] = 0;
		else
			lef[i] = s.top();
		s.push(i);
	}
	while(s.size())s.pop();
	//s.push(n+1);
	for(int i=n;i>=1;i--){
		while(!s.empty()&&a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty())righ[i]=n+1;
		else righ[i]=s.top();
		s.push(i);
	}
	unsigned long long ans = 0;
	int ss=n,ee=n;
	for(int i=1;i<=n;i++){
		int l = lef[i]+1;
		int r = righ[i]-1;
		unsigned long long cur = 1ULL*(r-l+1)*a[i];
		if(cur>ans){
			ss = l;ee=r;
			ans=cur;
		}
		else if(cur==ans){
			if(ss>l){
				ss = l;ee=r;
			}
		}
	}
	cout<<ss<<' '<<ee<<' '<<ans<<endl;
	
	
	
	return 0;
}











