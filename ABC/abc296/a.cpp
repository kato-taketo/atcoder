#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  char pre='X';
  rep(i,n) {
    if(pre==s[i]) {
      cout << "No" << endl; return 0;
    }
    pre=s[i];
  }
  cout << "Yes" << endl;
}