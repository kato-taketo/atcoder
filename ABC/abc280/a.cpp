#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  int cnt=0;
  rep(i,h) rep(j,w) if(s[i][j]=='#') cnt++;
  cout << cnt << endl;
}