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
unordered_map<char,string>ms;

int main(int argc, char *argv[]) {
//	for(char c='A';c<='Z';c++){
//		cout<<"ms[\'"<<c<<"\']="<<"\"\";"<<endl;
//	}
	ms['A']="01";
	ms['B']="1000";
	ms['C']="1010";
	ms['D']="100";
	ms['E']="0";
	ms['F']="0010";
	ms['G']="110";
	ms['H']="0000";
	ms['I']="00";
	ms['J']="0111";
	ms['K']="101";
	ms['L']="0100";
	ms['M']="11";
	ms['N']="10";
	ms['O']="111";
	ms['P']="0110";
	ms['Q']="1101";
	ms['R']="010";
	ms['S']="000";
	ms['T']="1";
	ms['U']="001";
	ms['V']="0001";
	ms['W']="011";
	ms['X']="1001";
	ms['Y']="1011";
	ms['Z']="1100";
	ms['1']="01111";
	ms['2']="00111";
	ms['3']="00011";
	ms['4']="00001";
	ms['5']="00000";
	ms['6']="10000";
	ms['7']="11000";
	ms['8']="11100";
	ms['9']="11110";
	ms['0']="11111";
	string s;
	getline(cin,s);
	//cout<<s<<endl;
	string t="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]-=32;
		}
		if(s[i]>='A'&&s[i]<='Z'){
			t+=ms[s[i]];
		}
		else if(s[i]>='0'&&s[i]<='9'){
			t+=ms[s[i]];
		}
	}
	//cout<<s<<endl;
	int n = t.size();
	if(n==0){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0,j=n-1;i<j;i++,j--){
		if(t[i]!=t[j]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	//cout<<str<<endl;
	
	
	return 0;
}











