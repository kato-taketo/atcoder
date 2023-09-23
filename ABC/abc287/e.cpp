#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int find(string x, string y) {
  int len=min(x.length(), y.length());
  int cnt=0;
  rep(i,len) if(x[i]==y[i]) cnt++;
  else return cnt;
  return cnt;
}
int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vector<pair<string,int> > vec(n);
  rep(i,n) vec[i] = make_pair(s[i],i);
  sort(vec.begin(), vec.end());
  vector<int> tmp(n), res(n);
  rep(i,n) {
    if(i==0) {
      tmp[i] = find(vec[i].first,vec[i+1].first);
    } else if(i==n-1) {
      tmp[i] = find(vec[i].first,vec[i-1].first);
    } else {
      tmp[i] = max(find(vec[i].first,vec[i+1].first), find(vec[i].first,vec[i-1].first));
    }
  }
  rep(i,n) res[vec[i].second] = tmp[i];
  rep(i,n) cout << res[i] << endl;
}