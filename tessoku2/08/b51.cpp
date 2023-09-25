// 17:25~33

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
  stack<int> stackl, stackr;
  vector<pair<int,int> > vec;
  rep(i,s.size()) {
    if(s[i]=='(') stackl.push(i);
    else if(s[i]==')') {
      vec.push_back(make_pair(stackl.top()+1, i+1));
      stackl.pop();
    }
  }
  rep(i,vec.size()) {
    cout << vec[i].first << " " << vec[i].second << endl;
  }
}