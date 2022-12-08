#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s,t;
  cin >> s >> t;

  int index=-1;
  rep(i,t.length()-1) {
    if(s[i]!=t[i]) {index =i+1; break; }
  }
  if(index==-1) index=t.length();
  cout << index << endl;
}