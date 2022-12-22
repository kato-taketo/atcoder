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
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vector<vector<int> > vec(10, vector<int>(n));
  rep(i,n) {
    rep(j,10) {
      int val=s[i][j]-'0';
      vec[val][i]=j;
    }
  }
  rep(i,10) sort(vec[i].begin(), vec[i].end());

  int res=2e9;
  rep(i,10) {
    int cnt=0,index;
    vector<int> tmp(10,0);
    rep(j,vec[i].size()) tmp[vec[i][j]]++;
    rep(j,10) if(cnt<=tmp[j]) cnt=tmp[j], index=j;
    res = min(res, 10*(cnt-1)+index);
    //printf("i = %d, res = %d, cnt = %d\n", i, res, cnt);
  }

  cout << res << endl;
}