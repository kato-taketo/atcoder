#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,q;
  cin >> n >> q;
  vector<string> p(n);
  rep(i,n) cin >> p[i];
  vector<vector<int> > que(q, vector<int>(4));
  rep(i,q) rep(j,4) cin >> que[i][j];

  vector<int> line_num(n,0);
  vector<int> retu_num(n,0);
  vector<int> line_cnt(0);
  ll all_cnt=0;
  ll sum_tmp=0;
  rep(i,n) {
    // i行目
    int tmp=0;
    rep(j,n) if(p[i][j]=='B') tmp++;
    line_num[i]=tmp;
  }
  rep(j,n) {
    int tmp=0;
    rep(i,n) if(p[i][j]=='B') tmp++;
    retu_num[j]=tmp;
  }

  rep(i,q) {
    int a,b,c,d;
    int tmp=0;
    a=que[i][0],b=que[i][1],c=que[i][2],d=que[i][3];
    tmp=a/n;
    a-=tmp*n; c-=tmp*n;
    tmp=b/n;
    b-=tmp*n; d-=tmp*n;

    int ori_a=a, ori_c=c;
    while(a%n!=0&&a<=c) {
      line_cnt[a%n]++;
      a++;
    }
    all_cnt=(c-a+1)/n;
    a+=all_cnt*n;
    for(int j=a; j<=c; j++) line_cnt[j%n]++;

    int ori_b=b;
    while(b%n!=0&&b<=d) {
      // 恥
      for(int k=ori_a; k<min(ori_c, a-all_cnt*n); k++) {
        if(p[k%n][])
      }
      // 複数
      sum_tmp += all_cnt*retu_num[b%n];
      // 恥

    }
  }
}