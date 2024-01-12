#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int N,Q,cnt;
vector<set<int> > sets;
int main(void) {
  cin >> N >> Q;
  sets.resize(N+1);
  cnt=0;
  rep(i,Q) {
    int n;
    cin >> n;
    if(n==1) {
      int u,v;
      cin >> u >> v;
      if(sets[u].empty()) cnt++;
      if(sets[v].empty()) cnt++;
      sets[u].insert(v);
      sets[v].insert(u);
      cout << N-cnt << endl;
    } else if(n==2) {
      int v;
      cin >> v;
      for(auto iter=sets[v].begin(); iter!=sets[v].end(); iter++) {
        //cout << *iter << endl;
        sets[*iter].erase(v); 
        if(sets[*iter].empty()) cnt--;
      }
      if(!sets[v].empty()) {
        sets[v].clear();
        cnt--;
      }
      cout << N-cnt << endl;
    }
  }
}