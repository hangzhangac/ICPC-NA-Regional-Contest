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
void output(int a,int b){
	cout<<"We need "<<a;
	if(a!=1)cout<<" trucks";
	else cout<<" truck";
	cout<<" and "<<b;
	if(b!=1){
		cout<<" boats."<<endl;
	}
	else cout<<" boat."<<endl;
	
	
}
//We need 101 trucks and 1 boat.
//We need 101 trucks and 1 boat.
int main(int argc, char *argv[]) {
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int x=c;x<=20000000;x++){
		if((d+x)%a==0&&x%b==0){
			output((d+x)/a, x/b);
			return 0;
		}
	}
	cout<<"No solution."<<endl;
	
	
	return 0;
}











