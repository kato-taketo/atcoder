#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  vector<unsigned long long> a(64);
  rep(i,64) cin >> a[i];

  unsigned long long res=0, v=1;
  rep(i,64) {
    //cout << v << endl;
    if(a[i]==1) res += v;
    if(i!=63) v *= 2LL;
  }
  cout << res << endl;
}