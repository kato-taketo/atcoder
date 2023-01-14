#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;

  string ans="";
  int r;
  while(n>0) {
    r = n%2;
    n /= 2;
    ans = char('0'+r) + ans;
  }
  //cout << ans << endl;
  int left=10-ans.length();
  rep(i,left) printf("%d",0);
  cout << ans << endl;

}