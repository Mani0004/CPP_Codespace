#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> dp1,dp2;

int up(int i){
    if(dp1[i]!=-1) return dp1[i];
    int ans=1;
    for(int j=0;j<i;j++){
        if(a[j]<a[i])
            ans=max(ans,1+up(j));
    }
    return dp1[i]=ans;
}

int down(int i){
    if(dp2[i]!=-1) return dp2[i];
    int ans=1;
    for(int j=i+1;j<n;j++){
        if(a[j]<a[i])
            ans=max(ans,1+down(j));
    }
    return dp2[i]=ans;
}

int main(){
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    dp1.assign(n,-1);
    dp2.assign(n,-1);

    int ans=0;

    for(int i=0;i<n;i++){
        int x=up(i);
        int y=down(i);
        if(x>1 && y>1)
            ans=max(ans,x+y-1);
    }

    cout<<ans;
}