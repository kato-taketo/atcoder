#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  string s;
  cin >> n >> m >> s;

  vector<int> vec1,vec2;  // vec1:= sum of 1, vec2 := sum of 2,
  int d1=0,d2=0,res=0;
  rep(i,n) {
    if(s[i]=='1') d1++;
    else if(s[i]=='2') d2++;
    else if(d1>0||d2>0) vec1.push_back(d1),vec2.push_back(d2),d1=0,d2=0;
  }
  if(d1>0||d2>0) vec1.push_back(d1),vec2.push_back(d2);
  rep(i,vec1.size()) {
    if(vec2[i]>res) res = vec2[i];
    if(vec1[i]+vec2[i]>res+m) res = max(res, vec1[i]+vec2[i]-m);
  }
  cout << res << endl;
}