#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll n;
  cin >> n;

  ll cnt=0;
  cnt += n/3;
  cnt += n/5;
  cnt += n/7;

  cnt -= n/15;
  cnt -= n/35;
  cnt -= n/21;
  cnt += n/105;

  cout << cnt << endl;
}