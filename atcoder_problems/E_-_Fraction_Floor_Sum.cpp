#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
ll N,ans,k;
int main(void) {
  cin >> N;

  for(ll i=1; i<=N; i++) {
    if(i*i <= N) k=i;
    else break;
  }
  ans=0;
  for(ll i=1; i<=k; i++) {
    ans += ((N/i)-(N/(i+1)))*i;
  }
  for(ll i=1; i<=N/(k+1); i++) {
    ans += (N/i);
  }
  cout << ans << endl;
}