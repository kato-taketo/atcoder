#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<pair<int,int> > vec(n);
  rep(i,n) vec[i] = make_pair(a[i],i);
  sort(vec.begin(),vec.end());
  int ov, nv=1;
  rep(i,n) {
    if(i==0) ov=vec[i].first, vec[i].first=nv;
    else if(vec[i].first==ov) vec[i].first=nv;
    else ov=vec[i].first, vec[i].first=++nv;
  }

  vector<int> res(n);
  rep(i,n) {
    res[vec[i].second] = vec[i].first;
  }
  rep(i,n) if(i==n-1) cout<<res[i]<<endl; else cout<<res[i]<<" ";
}