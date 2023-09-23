#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,t;
  cin >> n >> t;
  vector<int> c(n), r(n);
  rep(i,n) cin >> c[i];
  rep(i,n) cin >> r[i];

  bool key=false;
  int res=-1,tmp=-1;
  rep(i,n) if(c[i]==t) key=true;

  if(!key) {t = c[0];}
  rep(i,n) {
    if(c[i]==t) {
      if(tmp<r[i]) tmp=r[i], res=i+1;
    }
  }

    cout << res << endl;
}