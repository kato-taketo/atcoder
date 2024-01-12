#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s;
  cin >> s;
  int len=s.length();
  rep(i,len) {
    if(i!=len-1) cout << s[i];
    else cout << 4 << endl;
  }
}