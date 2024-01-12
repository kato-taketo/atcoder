#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,Q;
//vector<char> query;
vector<pair<int,int> > vec;
int main(void) {
  cin >> N >> Q;
  //query.resize(Q);
  //rep(i,Q) cin >> query[i];

  for(int i=N; i>0; i--) vec.push_back(make_pair(i,0));
  rep(i,Q) {
    int x; 
    cin >> x;
    if(x==1) {
      char y;
      cin >> y;
      pair<int,int> head=vec[vec.size()-1];
      if(y=='R') {
        head.first++;
      } else if(y=='L') {
        head.first--;
      } else if(y=='U') {
        head.second++;
      } else if(y=='D') {
        head.second--;
      }
      vec.push_back(head);
    } else if(x==2) {
      int y; cin >> y;
      y--;
      cout << vec[vec.size()-1-y].first << " " << vec[vec.size()-1-y].second << endl;
    }
  }
}