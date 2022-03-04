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
int n;
string s;
unordered_map<char, bool>ms;
unordered_map<char, char>lef;
long long solve(){
	//cout<<n<<endl;
	long long ans=0;
	for(int state = 0; state<(1<<n); state++){
		//vector<bool>v;
		int flag=0;
		for(int j=0;j<n;j++){
			if((1<<j)&state){
				if(s[j]!='?'&&!ms[s[j]]){
					flag=1;break;
				}
				//v.push_back(1);
			}
			else{
				if(s[j]!='?'&&ms[s[j]]){
					flag=1;break;
				}
				//v.push_back(0);
			}
				
		}
		
		if(flag)continue;
		//cout<<state<<endl;
		int k=0;
		stack<int>sta;
		for(int j=0;j<n;j++){
			if((1<<j)&state){
				sta.push(j);
			}
			else{
				if(sta.empty()){
					flag=1;break;
				}
				int id = sta.top();
				sta.pop();
				char l = s[id], r = s[j];
				if(l=='?'&&r=='?'){
					k++;
				}
				else if(l=='?'||r=='?'){
					continue;
				}
				else{
					if(lef[l]!=r){
						flag=1;break;
					}
				}
			}
		}
		if(flag||sta.size())continue;
		ans+=1LL*(1<<k)*(1<<k);
	}
	return ans;
}
int main(int argc, char *argv[]) {
	cin>>s;
	n = s.size();
	ms['('] = true;ms['{'] = true;ms['<'] = true;ms['['] = true;
	lef['(']=')';lef['[']=']';lef['{']='}';lef['<']='>';
	//cout<<1<<endl;
	cout<<solve()<<endl;
	return 0;
}











