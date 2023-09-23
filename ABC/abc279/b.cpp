#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string S,T;
  cin >> S >> T;

  if(T.length()>S.length()) {
    cout << "No" << endl; return 0;
  }
  for(int i=0; i<S.length(); i++) {
    // start i
    bool key=true;
    for(int j=0; j<T.length(); j++) {
      if(i+j>=S.length()) {
        key=false; break;
      }
      if(S[i+j]!=T[j]) key=false;
    }
    if(key) {cout << "Yes" << endl;
    return 0;
    }
  }
  cout << "No" << endl;
}