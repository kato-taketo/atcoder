#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  int Q;
  cin >> Q;
  int all_changed=-1;  //何回目の変更かを入れる
  vector<int> AC(N,-1);  //何回目の変更を受け入れたか
  int all_num;

  vector<ll> res;
  rep(i,Q) {
    int num;
    cin >> num;
    if(num==1) {
      int x; cin >> x;
      all_changed=i; all_num=x;
    } else if(num==2) {
      ll index,value;
      cin >> index >> value;
      index--;
      if(all_changed==-1) A[index] += value;
      else if (all_changed!=AC[index]) A[index]=all_num+value, AC[index]=all_changed;
      else if (all_changed==AC[index]) A[index]+=value;
    } else if(num==3) {
      int index;
      cin >> index;
      index--;
      //cout << A[index] << endl;
      if(all_changed!=AC[index]) A[index]=all_num,AC[index]=all_changed;
      res.push_back(A[index]);
    }
  }

  rep(i,res.size()) cout << res[i] << endl;
}