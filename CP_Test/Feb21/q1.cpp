#include <bits/stdc++.h>
using namespace std;

int n;
long long p;
vector<int> a;
map<pair<int,long long>,int> dp;

int go(int i,long long money){
    if(i>=n) return 0;
    if(dp.count({i,money})) return dp[{i,money}];

    int ans=0;

    if(money>=a[i])
        ans=max(ans,1+go(i+1,money-a[i]));

    if(i+1<n && money>=a[i+1])
        ans=max(ans,2+go(i+2,money-a[i+1]));

    return dp[{i,money}]=ans;
}

int main(){
    cin>>n>>p;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    cout<<go(0,p);
}