//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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
struct Node{
	string s[7];
}node[17];
vector<int>seq;
int S;
string cal(int last,int j,string x,int id){
	
	string ans = "";
	for(int cur=last;cur<=j;cur++){
		if(cur!=last){
			for(int k=0;k<S;k++){
				ans+="  ";
			}
		}
		int qq = seq[cur];
		for(int i=0;i<node[qq].s[id].size();i++){
			char cur_c = node[qq].s[id][i];
			for(int k=0;k<S;k++){
				ans.push_back(cur_c);
			}
		}
	}
	return ans;
}
int main(int argc, char *argv[]) {
	
	node[0].s[0]="XXX";
	node[0].s[1]="X X";
	node[0].s[2]="X X";
	node[0].s[3]="   ";
	node[0].s[4]="X X";
	node[0].s[5]="X X";
	node[0].s[6]="XXX";
	
	node[1].s[0]="   ";
	node[1].s[1]="  X";
	node[1].s[2]="  X";
	node[1].s[3]="   ";
	node[1].s[4]="  X";
	node[1].s[5]="  X";
	node[1].s[6]="   ";
	
	node[2].s[0]="XXX";
	node[2].s[1]="  X";
	node[2].s[2]="  X";
	node[2].s[3]="XXX";
	node[2].s[4]="X  ";
	node[2].s[5]="X  ";
	node[2].s[6]="XXX";
	
	node[3].s[0]="XXX";
	node[3].s[1]="  X";
	node[3].s[2]="  X";
	node[3].s[3]="XXX";
	node[3].s[4]="  X";
	node[3].s[5]="  X";
	node[3].s[6]="XXX";
	
	node[4].s[0]="   ";
	node[4].s[1]="X X";
	node[4].s[2]="X X";
	node[4].s[3]="XXX";
	node[4].s[4]="  X";
	node[4].s[5]="  X";
	node[4].s[6]="   ";
	
	node[5].s[0]="XXX";
	node[5].s[1]="X  ";
	node[5].s[2]="X  ";
	node[5].s[3]="XXX";
	node[5].s[4]="  X";
	node[5].s[5]="  X";
	node[5].s[6]="XXX";
	
	node[6].s[0]="XXX";
	node[6].s[1]="X  ";
	node[6].s[2]="X  ";
	node[6].s[3]="XXX";
	node[6].s[4]="X X";
	node[6].s[5]="X X";
	node[6].s[6]="XXX";
	
	node[7].s[0]="XXX";
	node[7].s[1]="  X";
	node[7].s[2]="  X";
	node[7].s[3]="   ";
	node[7].s[4]="  X";
	node[7].s[5]="  X";
	node[7].s[6]="   ";
	
	node[8].s[0]="XXX";
	node[8].s[1]="X X";
	node[8].s[2]="X X";
	node[8].s[3]="XXX";
	node[8].s[4]="X X";
	node[8].s[5]="X X";
	node[8].s[6]="XXX";
	
	node[9].s[0]="XXX";
	node[9].s[1]="X X";
	node[9].s[2]="X X";
	node[9].s[3]="XXX";
	node[9].s[4]="  X";
	node[9].s[5]="  X";
	node[9].s[6]="XXX";
	
	node[10].s[0]="XXX";
	node[10].s[1]="X X";
	node[10].s[2]="X X";
	node[10].s[3]="XXX";
	node[10].s[4]="X X";
	node[10].s[5]="X X";
	node[10].s[6]="   ";
	
	node[11].s[0]="   ";
	node[11].s[1]="X  ";
	node[11].s[2]="X  ";
	node[11].s[3]="XXX";
	node[11].s[4]="X X";
	node[11].s[5]="X X";
	node[11].s[6]="XXX";
	
	node[12].s[0]="XXX";
	node[12].s[1]="X  ";
	node[12].s[2]="X  ";
	node[12].s[3]="   ";
	node[12].s[4]="X  ";
	node[12].s[5]="X  ";
	node[12].s[6]="XXX";
	
	node[13].s[0]="   ";
	node[13].s[1]="  X";
	node[13].s[2]="  X";
	node[13].s[3]="XXX";
	node[13].s[4]="X X";
	node[13].s[5]="X X";
	node[13].s[6]="XXX";
	
	node[14].s[0]="XXX";
	node[14].s[1]="X  ";
	node[14].s[2]="X  ";
	node[14].s[3]="XXX";
	node[14].s[4]="X  ";
	node[14].s[5]="X  ";
	node[14].s[6]="XXX";
	
	
	node[15].s[0]="XXX";
	node[15].s[1]="X  ";
	node[15].s[2]="X  ";
	node[15].s[3]="XXX";
	node[15].s[4]="X  ";
	node[15].s[5]="X  ";
	node[15].s[6]="   ";
	
	node[16].s[0]="   ";
	node[16].s[1]="   ";
	node[16].s[2]="   ";
	node[16].s[3]="   ";
	node[16].s[4]="   ";
	node[16].s[5]="   ";
	node[16].s[6]="   ";
	
	string tmp = "111011101001001011101110110101011101101011111101101001011111111110111101111111111010101001111111001011011001101111101110100100101110111011010101110110101111110110100101111111111011110111111111101010100111111100101101100110111110111010010010111011101101";
	while(tmp.size()%7!=0){
		tmp = "0" +tmp;
	}
	cin>>S;
	string s;
	cin>>s;
	//cout<<s.size()<<endl;
	while(s.size()%7!=0){
		s="0"+s;
	}
	//cout<<s<<endl;
	int j = 0;
	unordered_map<string, int>ms;
	for(int cnt=0;cnt<16;cnt++){
		string x = tmp.substr(j,7);
		ms[x]=cnt;
		j+=7;
		//cout<<x<<' '<<cnt<<endl;
		//if(cnt==0)cout<<x<<endl;
	}
	j=0;
	
	while(j<s.size()){
		string x = s.substr(j,7);
		//seq.push_back(ms[x]);
		if(ms.find(x)==ms.end())seq.push_back(16);
		else seq.push_back(ms[x]);
		j+=7;
	}

	j=0;
	while(j<seq.size()){
		int cur = seq[j];
		int last = j;
		int col = S*3;
		while(j+1<seq.size()&&col+S*5<=80){
			col+=S*3+S*2;
			j++;
		}
		//node[j].s[0];
		int len = 0;
		string ans="";
		for(int i=0;i<7;i++){
			for(int k=0;k<S;k++){
				cout<<cal(last,j, ans,i)<<endl;
			}
		}
		j++;
		if(j!=seq.size()){
			for(int i=0;i<S;i++){
				cout<<endl;
			}
		}
		
	}
	//cout<<"\b";
	

	
	
	return 0;
}











