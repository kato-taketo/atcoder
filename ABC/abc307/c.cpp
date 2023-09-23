#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

vector<string> a,b,c;
int ha,wa, hb,wb, hx,wx;
vector<string> change(vector<string> vec) {
  int l,r;
  l = vec.size(); r = vec[0].size();
  int l1=l, l2=0, r1=r, r2=0;
  for(int i=0; i<l; i++) {
    for(int j=0; j<r; j++) {
      if(vec[i][j]=='#') {
        if(l1>i) l1=i;
        if(l2<i) l2=i;
        if(r1>j) r1=j;
        if(r2<j) r2=j;
      }
    }
  }
  vector<string> nvec;
    for(int i=l1; i<=l2; i++) {
      string tmp="";
      for(int j=r1; j<=r2; j++) {
        tmp += vec[i][j];
      }
      nvec.push_back(tmp);
    }
  return nvec;
}
int main(void) {
  
  cin >> ha >> wa;
  a.resize(ha);
  rep(i,ha) cin >> a[i];
  cin >> hb >> wb;
  b.resize(hb);
  rep(i,hb) cin >> b[i];
  cin >> hx >> wx;
  c.resize(hx);
  rep(i,hx) cin >> c[i];

  a = change(a);
  b = change(b);
  c = change(c);
  ha=a.size(); wa=a[0].size();
  hb=b.size(); wb=b[0].size();
  hx=c.size(); wx=c[0].size();
  //cout << hb << " " << wb << endl;
  //rep(i,hb) {
  //  rep(j,wb) {
  //    cout << b[i][j];
  //  }
  //  cout << endl;
  //}
  int cnt=0, cnta=0, cntb=0;
  rep(i,ha) rep(j,wa) if(a[i][j]=='#') cnta++;
  rep(i,hb) rep(j,wb) if(b[i][j]=='#') cntb++;
  rep(i,hx) rep(j,wx) if(c[i][j]=='#') cnt++;
  //cout << "cnt" << cnt << endl;
  if(ha>hx||hb>hx||wa>wx||wb>wx) {cout << "No" << endl; return 0; }
  //else if(cnta+cntb<cnt) {cout << "No" << endl; return 0; }
  else {
    int cnttmp=0;
    set<pair<int,int> > sets;
    sets.clear();
    int sets_size=0;
    for(int i=0; i+ha<=hx; i++) {
      for(int j=0; j+wa<=wx; j++) {
        //cout << "i" << i << "j" << j << endl;
        for(int k=0; k+hb<=hx; k++) {
          for(int l=0; l+wb<=wx; l++) {
            //cout << "k" << k << "l" << l << endl;
            sets.clear();
            bool key=true;
            for(int x=i; x<i+ha; x++) {  
              for(int y=j; y<j+wa; y++) {
                if(a[x-i][y-j]=='#'&&c[x][y]=='#') {
                  sets.insert(make_pair(x,y));
                }else if(a[x-i][y-j]=='#') { key=false; }
              }
            }
            for(int x=k; x<k+hb; x++) {
              for(int y=l; y<l+wb; y++) {
                if(b[x-k][y-l]=='#'&&c[x][y]=='#') {
                  sets.insert(make_pair(x,y));
                }else if(b[x-k][y-l]=='#') { key=false; }
              }
            }
            if(!key) continue;
            if(cnt==sets.size()) {
              cout << "Yes" << endl; return 0;
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}