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
  string s;
  cin >> s;

  int num=0;
  for(int i=0; i<s.length(); i++) {
    if(num==0&&s[i]==',') s[i]='.';
    if(s[i]=='"') num++;
    if(num==2) num=0;
  }
  cout << s << endl;
}