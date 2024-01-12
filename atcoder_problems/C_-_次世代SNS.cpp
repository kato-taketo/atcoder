#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s, tmp;
  //cin >> s;
  getline(cin, s);
  set<string> ans;
  rep(i,s.length()) {
    if(s[i]=='@') {
      string a;
      for(int j=i+1; j<s.length(); j++) {
        if(s[j]==' '||s[j]=='@') {
          i=j-1; break;
        }
        a+=s[j];
      }
      ans.insert(a);
    }
  }
  for(string i: ans) {
    if('a'<=i[0]&&i[0]<='z') cout << i << endl;
  }
}