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
vector<int>a1,a2,b1,b2;
int p1,u1;
int p2,u2;
void read(){
	gi2(p1, u1);
	int x;
	for(int i=0;i<p1;i++){
		gi(x);
		a1.push_back(x);
	}
	for(int i=0;i<u1;i++){
		gi(x);b1.push_back(x);
	}
	reverse(b1.begin(), b1.end());
	gi2(p2, u2);
	for(int i=0;i<p2;i++){
		gi(x);
		a2.push_back(x);
	}
	for(int i=0;i<u2;i++){
		gi(x);
		b2.push_back(x);
	}
	reverse(b2.begin(), b2.end());
	return;
}
int solve(vector<int>&a1,vector<int>&a2){
	int ans=0;
	unordered_set<int>s;
	for(auto x:a2)s.insert(x);
	int cnt=0;
	for(int i=0;i<a2.size();i++){
		int t = a2[i];
		while(cnt<a1.size()&&a1[cnt]!=t){
			if(s.find(a1[cnt])!=s.end()){
				ans+=2;
			}
			else ans++;
			cnt++;
		}
		if(cnt==a1.size())break;
		else cnt++;
	}
	while(cnt<a1.size()){
		cnt++;
		ans++;
	}
	return ans;
}
int main(int argc, char *argv[]) {
	read();
	cout<<solve(a1, a2)+solve(b1, b2)<<endl;
	
	
	return 0;
}











