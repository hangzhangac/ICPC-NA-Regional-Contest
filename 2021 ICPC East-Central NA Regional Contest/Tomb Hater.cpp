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
const int MAXN=55;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
using namespace std;
char a[MAXN][MAXN];
string s[MAXN];
int n,m,k;
struct Node{
	int x,y,i,j;
	int last_dir;
	Node(){
		
	}
	Node(int xx,int yy,int ii,int jj,int last){
		x=xx;y=yy;i=ii;j=jj;last_dir = last;
	}
};
bool vis[MAXN][MAXN][MAXN][MAXN][4];
int bfs(){
	
	queue< pair<Node,pair<int,pair<int,int>>> >que;
	//set<Node>vis;
	for(int j=1;j<=m;j++){
		for(int q=0;q<k;q++){
			if(a[1][j]==s[q][0]){
				Node e = Node(1, j, q, 0, 3);
				que.push({e,{1,{0,0}}});
				//vis.insert(e);
				vis[1][j][q][0][3]=1;
			}
		}
	}
	while(!que.empty()){
		auto xx = que.front();que.pop();
		Node& e = xx.first;
		int step = xx.second.first;
		if(step>n*m)continue;
		if(e.x==n&&e.j+1==s[e.i].size())return step;
		int lastx = xx.second.second.first;
		int lasty = xx.second.second.second;
		int dx[]={1,0,0};
		int dy[]={0,-1,1};
		for(int q = 0;q<3;q++){
			int nx = e.x+dx[q];
			int ny = e.y+dy[q];
			if(nx==lastx&&ny==lasty)continue;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(e.j+1<s[e.i].size()&&s[e.i][e.j+1]==a[nx][ny]){
				Node ne = Node(nx, ny, e.i, e.j+1, q);
				if(vis[nx][ny][e.i][e.j+1][q]==false){
					vis[nx][ny][e.i][e.j+1][q]=true;
					que.push({ne,{step+1,{e.x,e.y}}});
				}
			}
			else if(e.j+1==s[e.i].size()){
				for(int f=0;f<k;f++){
					if(a[nx][ny]==s[f][0]){
						Node ne = Node(nx, ny, f, 0, q);
						if(vis[nx][ny][f][0][q]==false){
							vis[nx][ny][f][0][q]=true;
							//vis.insert(ne);
							que.push({ne,{step+1,{e.x,e.y}}});
						}
					}
				}
			}
		}
	}
	return inf;
	
}
int main(int argc, char *argv[]) {
	gi3(n, m, k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			string t;
			cin>>t;
			a[i][j]=t[0];
		}
	}
	for(int i=0;i<k;i++)cin>>s[i];
	int ans = bfs();
	if(ans==inf)cout<<"impossible"<<endl;
	else cout<<ans<<endl;
	return 0;
}