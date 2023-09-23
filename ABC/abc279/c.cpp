#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int H,W;
  cin >> H >> W;
  vector<string> S(H),T(H);
  rep(i,H) cin >> S[i];
  rep(i,H) cin >> T[i];

  vector<string> s(W, ""), t(W, "");
  rep(j,W)  {
    rep(i,H) s[j]=s[j]+S[i][j], t[j]=t[j]+T[i][j];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  //bool key=true;
  //rep(i,W) {
  //  if(s[i]!=t[i]) {
  //    key=false; break;
  //  }
  //}
  //if(key) cout << "Yes" << endl;
  //else cout << "No" << endl;
  if(s==t) cout << "Yes" << endl;
  else cout << "No" << endl;
}