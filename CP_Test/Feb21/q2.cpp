#include <bits/stdc++.h>
using namespace std;

int dp[75][75][75];

int go(int r,int c1,int c2,vector<vector<int>>& g,int n,int m){
    if(c1<0 || c2<0 || c1>=m || c2>=m) return -1e9;

    if(r==n-1){
        if(c1==c2) return g[r][c1];
        return g[r][c1]+g[r][c2];
    }

    if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

    int ans=0;
    for(int x=-1;x<=1;x++){
        for(int y=-1;y<=1;y++){
            int v=go(r+1,c1+x,c2+y,g,n,m);
            if(c1==c2) v+=g[r][c1];
            else v+=g[r][c1]+g[r][c2];
            ans=max(ans,v);
        }
    }
    return dp[r][c1][c2]=ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];

    memset(dp,-1,sizeof(dp));
    cout<<go(0,0,m-1,g,n,m);
}