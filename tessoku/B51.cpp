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

  deque<int> deq;
  vector<pair<int,int> > res;
  rep(i,s.length()) {
    if(s[i]=='(') deq.push_front(i+1);
    else if(s[i]==')') {
      deq.push_back(i+1);
      int p,q;
      p=deq.front(); q=deq.back();
      deq.pop_back(); deq.pop_front();
      res.push_back(make_pair(p,q));
    }
  }
  rep(i,res.size()) cout << res[i].first << " " << res[i].second << endl;
}