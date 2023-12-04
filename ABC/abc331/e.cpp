#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,M,L;
vector<ll> cur,b;
vector<pair<int,int> > a_index,b_index;
map<pair<int,int>, bool> mp_cd;
priority_queue<pair<int,int> > pq;  // value, index of b
int main(void) {
  cin >> N >> M >> L;
  a_index.resize(N); b_index.resize(M);
  b.resize(M);
  rep(i,N) {
    int a; cin >> a;
    a_index[i]=make_pair(a,i);
  }
  rep(i,M) {
    cin >> b[i];
    //int b; cin >> b;
    //b_index[i]=make_pair(b,i);
  }
  rep(i,L) {
    int c,d;
    cin >> c >> d;
    mp_cd[make_pair(c,d)]=true;
  }
  cur.resize(M,0);  // cur[i] := 副菜iは、主菜cur[i]までみた
  sort(a_index.rbegin(), a_index.rend()); 
  sort(b_index.rbegin(), b_index.rend());
  rep(i,M) pq.push(make_pair(a_index[0].first+b[i],i));

  // search
  while(!pq.empty()) {
    pair<int,int> node=pq.top();
    pq.pop();
    int b_now,a_now;
    b_now=node.second;
    a_now=a_index[cur[b_now]].second;
    //cout << "a: " << a_now+1 << " b: " << b_now+1 << endl;
    if(mp_cd[make_pair(a_now+1,b_now+1)]==false) {
      cout << node.first << endl; return 0;
    }
    if(cur[b_now]!=N-1) {
      cur[b_now]++;
      pq.push(make_pair(a_index[cur[b_now]].first+b[b_now], b_now));
    }
  }
}