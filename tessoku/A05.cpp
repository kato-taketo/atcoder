#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;

  int cnt=0;
  rep2(i,1,n+1) {
    rep2(j,1,n+1) {
      int white=k-i-j;
      if(white>=1 && white<=n) cnt++;
    }
  }
  cout << cnt << endl;
}