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
vector<int>cal(int a){
	vector<int>t;
	int cnt = 8;
	while(cnt--){
		t.push_back(a&1);
		a/=2;
	}
	reverse(t.begin(), t.end());
	return t;
}
unordered_map<int, int>ms;
int main(int argc, char *argv[]) {
	int n;
	gi(n);
	for(int j=0;j<n;j++){
		string s;
		cin>>s;
		int i=0;
		vector<int>a;
		while(i<s.size()){
			int cnt=0;
			while(i<s.size()&&s[i]!='.'){
				cnt*=10;
				cnt+=s[i]-'0';
				i++;
			}
			a.push_back(cnt);
			i++;
		}
		vector<int>ans;
		for(int i=0;i<4;i++){
			vector<int>tmp = cal(a[i]);
			for(int k=0;k<tmp.size();k++){
				ans.push_back(tmp[k]);
			}
		}
		for(int i=0;i<ans.size();i++){
			ms[i]+=ans[i];
		}
		//cout<<endl;
	}
	for(int i=0;i<33;i++){
		int output = i+1;
		if(i==32){
			cout<<32<<endl;
			return 0;
		}
		if(ms[i]==n||ms[i]==0)continue;
		if(output-1==0)output=32;
		else output--;
		cout<<output<<endl;
		return 0;
		
	}
	
	
	
	
	return 0;
}











