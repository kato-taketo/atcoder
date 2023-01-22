#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n+1),b(n+1);
  rep2(i,2,n+1) cin >> a[i];
  rep2(i,3,n+1) cin >> b[i];

  vector<int> dp(n+1,inf);
  vector<int> pre(n+1,-1);
  dp[1]=0;
  dp[2]=a[2];
  pre[2]=1;
  rep2(i,3,n+1) {
    if(dp[i-1]+a[i]>dp[i-2]+b[i]) pre[i]=i-2;
    else pre[i]=i-1;
    dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);
  }

  int index=n;
  vector<int> res;
  while(1) {
    //printf("%d ", index);
    res.push_back(index);
    if(index==1) break;
    index = pre[index];
  }
  reverse(res.begin(),res.end());
  cout << res.size() << endl;
  rep(i,res.size()) {
    if(i==res.size()-1) cout<<res[i]<<endl;
    else cout<<res[i]<<" ";
  }
}