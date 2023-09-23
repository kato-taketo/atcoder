#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

bool check(char word) {
  if(word>='A' && word<='Z') return true;
  else return false;
}
bool check2(string str) {
  bool res=true;
  for(int i=1; i<=6; i++) {
    if(i==1) {
      if(!(str[i]>='1'&&str[i]<='9')) res=false;
    } else {
      if(!(str[i]>='0'&&str[i]<='9')) res=false;
    }
  }
  return res;
}
int main(void) {
  string s;
  cin >> s;
  if(s.length() != 8) cout << "No" << endl;
  else {
    bool key=false;
    if(check(s[0]) && check(s[7]) && check2(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

  }
}