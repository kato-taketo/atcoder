#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353

int main(void) {
  ll N;
  cin >> N;

  N %= mod;
  if(N<0) N += mod;
  cout << N << endl;
}