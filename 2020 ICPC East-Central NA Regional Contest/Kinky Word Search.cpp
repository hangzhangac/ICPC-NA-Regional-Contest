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
const int MAXN=10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
string s[MAXN];
string w;
int flag=0;
int n,m;
int dx[]={0,0,-1,1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
short dp[10][10][9][101][101];
short dfs(int x,int y,int last_dir,int num,int wi){
	if(dp[x][y][last_dir][num][wi]!=-1){
		return dp[x][y][last_dir][num][wi];
	}
	if(num<0||num+wi+1>w.size())return 0;
	if(wi+1==w.size()){
		if(num==0){
			return 1;
		}
		return 0;
	}
	short t = 0;
	for(int i=0;i<8;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=m||w[wi+1]!=s[nx][ny])continue;
		if(last_dir==0||last_dir==i+1){
			t = t|dfs(nx,ny,i+1,num,wi+1);
		}
		else{
			t = t|dfs(nx,ny,i+1,num-1,wi+1);
		}
		if(t==1)return dp[x][y][last_dir][num][wi]=1;
	}
	return dp[x][y][last_dir][num][wi]=0;
}
int main(int argc, char *argv[]) {
	mem(dp,-1);
	gi2(n, m);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char t = getchar();
			getchar();
			s[i].push_back(t);
		}
		//cout<<s[i]<<endl;
	}
	int k;gi(k);
	cin>>w;
	int len = w.size();
	if(len-1<k){
		printf("No\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==w[0]&&dfs(i,j,0,k,0)){
				flag=1;break;
			}
		}
		if(flag)break;
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;
}











