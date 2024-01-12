#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int N, z;
vector<pair<int,pair<int,int> > > vec;
int main(void) {
  cin >> N;
  for(int all=0; all<=N; all++) {
    for(int x=0; x<=all; x++) {
      for(int y=0; y<=all-x; y++) {
        z = all-(x+y);
        if(z<0) continue;
        else vec.push_back(make_pair(x,make_pair(y,z)));
      }
    }
  }
  sort(vec.begin(),vec.end());
  rep(i,vec.size()) cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
}