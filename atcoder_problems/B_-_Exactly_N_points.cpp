#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,m,res;
int main(void) {
  cin >> N;
  for(m=1; m<=N; m++) {
    if(m*(m+1)/2>N) break;
  }
  m--;
  res = N-(m*(m+1)/2);
  for(int i=1; i<=m+1; i++) {
    if(m+1-res==i) continue;
    else cout << i << endl;
  }
}