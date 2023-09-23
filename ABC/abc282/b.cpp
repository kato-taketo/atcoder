#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  int cnt=0;
  for(int x=0; x<n; x++) {
    for(int y=x+1; y<n; y++) {
      // s[x], s[y]を考察
      bool key=true;
      for(int i=0; i<m; i++) {
        if(s[x][i]=='x'&&s[y][i]=='x') key=false;
      }
      if(key) cnt++;
    }
  }
  cout << cnt << endl;
}