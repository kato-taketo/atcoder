#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  if (a>0&&d>0&&b==0&&c==0) cout << "No" << endl;
  else if(abs(b-c)<=1) cout << "Yes" << endl;
  else cout << "No" << endl;
}