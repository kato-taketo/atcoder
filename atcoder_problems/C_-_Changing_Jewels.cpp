#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
ll funcr(int n);
ll funcb(int n);

ll N,X,Y;
ll funcr(int n) {
  if(n==1) return 0;
  return funcr(n-1) + funcb(n) * X;
}
ll funcb(int n) {
  if(n==1) return 1;
  return funcr(n-1) + funcb(n-1) * Y;
}
int main(void) {
  //int N,X,Y;
  cin >> N >> X >> Y;

  cout << funcr(N) << endl;
}