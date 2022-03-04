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
int f[MAXN];
void solve(int n,int f[],int flag=1){
    for(int i=1;i<=n;i++)f[i]=i;
    f[1]=1;
    f[11]=2;
    f[111]=3;
    f[1111]=4;
    f[11111]=5;
    for(int i=1;i<=n;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                f[i] = min(f[i],f[j]+f[i/j]);
            }
        }
        if(flag){
            for(int k=1,j=i-1;k<=j;k++,j--){
                f[i]=min(f[i],f[k]+f[j]);
            }
        }
        
        string s = to_string(i);
        for(int j=0;j+1<s.size();j++){
            string s1 = s.substr(0,j+1);
            string s2 = s.substr(j+1);
            if(s2[0]!='0'){
                f[i]=min(f[i],f[stoi(s1)]+f[stoi(s2)]);
            }
        }
    }
}
int main(int argc, char *argv[]) {
    int n;gi(n);
    for(int i=1;i<=n;i++)f[i]=inf;
    f[1]=1;
    f[11]=2;
    f[111]=3;
    f[1111]=4;
    f[11111]=5;
//  for(int i=0;i<tmp.size();i+=2){
//      f[tmp[i]] = tmp[i+1];
//  }
    if(f[n]!=inf){
        cout<<f[n]<<endl;
        //cout<<1<<endl;
        return 0;
    }
    solve(n, f);
    cout<<f[n]<<endl;
    
    
    
    return 0;
}