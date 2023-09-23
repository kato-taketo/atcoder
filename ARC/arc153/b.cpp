#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w;
  cin >> h >> w;
  vector<string> A(h);
  rep(i,h) cin >> A[i];
  int q;
  cin >> q;
  vector<int> a(q),b(q);
  rep(i,q) cin >> a[i] >> b[i];


  vector<vector<pair<int,int> > > vec(h+2,vector<pair<int,int> >(w+2));
  rep(i,h+2) rep(j,w+2) vec[i][j] = make_pair(0,0);
    rep(i,q) {
      if((i+1)%2 == q%2) {
        vec[1][1].first+=a[i]; vec[1][1].second+=b[i];
        vec[a[i]+1][b[i]+1].first+=a[i]; vec[a[i]+1][b[i]+1].second+=b[i];
        vec[a[i]+1][1].first-=a[i]; vec[a[i]+1][1].second-=b[i];
        vec[1][b[i]+1].first-=a[i]; vec[1][b[i]+1].second-=b[i];

        vec[1][b[i]+1].first+=a[i]; vec[1][b[i]+1].second+=w+b[i];
        vec[a[i]+1][w+1].first+=a[i]; vec[a[i]+1][w+1].second+=w+b[i];
        vec[1][w+1].first-=a[i]; vec[1][w+1].second-=w+b[i];
        vec[a[i]+1][b[i]+1].first-=a[i]; vec[a[i]+1][b[i]+1].second-=w+b[i];

        vec[a[i]+1][1].first+=h+a[i]; vec[a[i]+1][1].second+=b[i];
        vec[h+1][b[i]+1].first+=h+a[i]; vec[h+1][b[i]+1].second+=b[i];
        vec[a[i]+1][b[i]+1].first-=h+a[i]; vec[a[i]+1][b[i]+1].second-=b[i];
        vec[h+1][1].first-=h+a[i]; vec[h+1][1].second-=b[i];

        vec[a[i]+1][b[i]+1].first+=h+a[i]; vec[a[i]+1][b[i]+1].second+=w+b[i];
        vec[h+1][w+1].first+=h+a[i]; vec[h+1][w+1].second+=w+b[i];
        vec[a[i]+1][w+1].first-=h+a[i]; vec[a[i]+1][w+1].second-=w+b[i];
        vec[h+1][b[i]+1].first-=h+a[i]; vec[h+1][b[i]+1].second-=w+b[i];

      } else {
        vec[1][1].first-=a[i]; vec[1][1].second-=b[i];
        vec[a[i]+1][b[i]+1].first-=a[i]; vec[a[i]+1][b[i]+1].second-=b[i];
        vec[a[i]+1][1].first+=a[i]; vec[a[i]+1][1].second+=b[i];
        vec[1][b[i]+1].first+=a[i]; vec[1][b[i]+1].second+=b[i];

        vec[1][b[i]+1].first-=a[i]; vec[1][b[i]+1].second-=w+b[i];
        vec[a[i]+1][w+1].first-=a[i]; vec[a[i]+1][w+1].second-=w+b[i];
        vec[1][w+1].first+=a[i]; vec[1][w+1].second+=w+b[i];
        vec[a[i]+1][b[i]+1].first+=a[i]; vec[a[i]+1][b[i]+1].second+=w+b[i];

        vec[a[i]+1][1].first-=h+a[i]; vec[a[i]+1][1].second-=b[i];
        vec[h+1][b[i]+1].first-=h+a[i]; vec[h+1][b[i]+1].second-=b[i];
        vec[a[i]+1][b[i]+1].first+=h+a[i]; vec[a[i]+1][b[i]+1].second+=b[i];
        vec[h+1][1].first+=h+a[i]; vec[h+1][1].second+=b[i];

        vec[a[i]+1][b[i]+1].first-=h+a[i]; vec[a[i]+1][b[i]+1].second-=w+b[i];
        vec[h+1][w+1].first-=h+a[i]; vec[h+1][w+1].second-=w+b[i];
        vec[a[i]+1][w+1].first+=h+a[i]; vec[a[i]+1][w+1].second+=w+b[i];
        vec[h+1][b[i]+1].first+=h+a[i]; vec[h+1][b[i]+1].second+=w+b[i];
      }
    }

  // emos整理
  rep(i,h+2) {
    rep(j,w+1) {
      vec[i][j+1].first += vec[i][j].first;
      vec[i][j+1].second += vec[i][j].second;
    }
  }
  rep(i,h+1) {
    rep(j,w+2) {
      vec[i+1][j].first += vec[i][j].first;
      vec[i+1][j].second += vec[i][j].second;
    }
  }
  // index is add if (q%2==0) else remove
  rep2(i,1,h+1) {
    rep2(j,1,w+1) {
      if(q%2==0) vec[i][j].first+=i, vec[i][j].second+=j;
      else vec[i][j].first-=i, vec[i][j].second-=j;
    }
  }
  rep2(i,0,h+2) {
    rep2(j,0,w+2) {
      printf("(%d %d)", vec[i][j].first,vec[i][j].second);
    }
     cout << endl;
  }
  vector<vector<char> > res(h,vector<char>(w));
  rep2(i,1,h+1) {
    rep2(j,1,w+1) {
      res[vec[i][j].first][vec[i][j].second]=A[i-1][j-1];
    }
  }
  //cout << "Yes" << endl;
  rep(i,h) {
    rep(j,w) printf("%c", res[i][j]);  
    cout << endl;
  }
  
}