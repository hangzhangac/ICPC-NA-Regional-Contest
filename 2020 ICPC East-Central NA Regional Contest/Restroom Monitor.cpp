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
vector<int>need;
vector<int>noneed;
int main(int argc, char *argv[]) {
	int m,n;
	
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int x;string y;
		cin>>x>>y;
		if(y[0]=='y'){
			need.push_back(x);
		}
		else{
			noneed.push_back(x);
		}
	}
	sort(need.begin(),need.end());
	sort(noneed.begin(),noneed.end());
	int flag=1;
	for(int i=0;i<need.size();i++){
		//cout<<need[i]<<' '<<i+1<<endl;
		if(need[i]<i+1){
			flag=0;
			break;
		}
	}
	if(flag==0){
		printf("No\n");
		return 0;
	}
	int div = need.size()+1;
	int num = m - 1;
	int i=0;
	int cur_time = 1;
	while(i<noneed.size()){
		if(cur_time==div)num = m;
		int t = num;
		while(t>0&&i<noneed.size()){
			if(noneed[i]<cur_time){
				flag=0;
				break;
			}
			i++;
			t--;
		}
		if(flag==0)break;
		cur_time++;
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	
	
	
	
	return 0;
}











