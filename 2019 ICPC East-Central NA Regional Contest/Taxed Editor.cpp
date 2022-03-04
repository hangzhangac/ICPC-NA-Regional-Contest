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
int n,m;
vector<pair<int,int>>a;
bool C(ll mid){
	priority_queue<ll>q;
	ll sum = 0;
	int cnt=0;
	for(int i=0;i<a.size();i++){
		ll d = a[i].first;
		ll l = a[i].second;
		ll all = d*mid;
		if(all>=sum+l){
			sum+=l;
			q.push(l);
		}
		else{
			cnt++;
			if(cnt>m)return false;
			if(q.empty()||q.top()<=l){
				//sum+=l;
				//q.push(l);
			}
			else if(q.top()>l){
				sum-=q.top();
				q.pop();
				sum+=l;
				q.push(l);
			}
		}
	}
	return true;
	
}
int main(int argc, char *argv[]) {
	
	gi2(n, m);
	for(int i=1;i<=n;i++){
		int l,d;
		gi2(l, d);
		a.push_back({d,l});
	}
	sort(a.begin(),a.end());
	ll l=1,r=1e14+10;
	while(l<=r){
		ll mid = (l+r)/2;
		if(C(mid)){
			r = mid-1;
		}
		else l = mid+1;
	}
	
	printf("%lld\n",l);
	
	
	
	return 0;
}











