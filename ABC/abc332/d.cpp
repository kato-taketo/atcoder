#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int minSwaps(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return -1; // 文字列の長さが異なる場合、-1を返す
    }

    int n = s.length();
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            int j = i + 1;
            while (j < n && s[j] != t[i]) {
                ++j;
            }

            if (j == n) {
                return -1; // 文字列sに文字t[i]が含まれていない場合、-1を返す
            }

            while (j > i) {
                std::swap(s[j], s[j - 1]);
                --j;
                ++swaps;
            }
        }
    }

    return swaps; // swap回数を返す
}
int main(void) {
  int h,w;
  cin >> h >> w;
  vector<vector<int> > a(h,vector<int>(w)), b(h,vector<int>(w));
  rep(i,h) rep(j,w) cin >> a[i][j];
  rep(i,h) rep(j,w) cin >> b[i][j];

  vector<int> line(h), retu(w);
  map<vector<int>,vector<int> > a_line,b_line,a_retu,b_retu;
  multiset<vector<int> > a_line_s,b_line_s,a_retu_s,b_retu_s;
  vector<bool> a_line_b(h,false),b_line_b(h,false),a_retu_b(w,false),b_retu_b(w,false);
  rep(i,h) {
    vector<int> tmp(w);
    rep(j,w) tmp[j] = a[i][j];
    sort(tmp.begin(),tmp.end()); 
    a_line[tmp].push_back(i);
    a_line_s.insert(tmp);
    rep(j,w) tmp[j] = b[i][j];
    sort(tmp.begin(),tmp.end()); 
    b_line[tmp].push_back(i);
    b_line_s.insert(tmp);
  }
  rep(j,w) {
    vector<int> tmp(h);
    rep(i,h) tmp[i] = a[i][j];
    sort(tmp.begin(),tmp.end()); 
    a_retu[tmp].push_back(j);
    a_retu_s.insert(tmp);
    rep(i,h) tmp[i] = b[i][j];
    sort(tmp.begin(),tmp.end()); 
    b_retu[tmp].push_back(j);
    b_retu_s.insert(tmp);
  }

  if(a_line_s==b_line_s&&a_retu_s==b_retu_s) {
    int res=0;
    vector<char> a_line_c(h),b_line_c(h),a_retu_c(w),b_retu_c(w);
    char c='a';
    for (const auto& [key, value] : a_line) {
      rep(i,value.size()) a_line_c[value[i]]=c;
      rep(i,b_line[key].size()) b_line_c[b_line[key][i]]=c;
      c++;
    }
    c='a';
    for (const auto& [key, value] : a_retu) {
      rep(i,value.size()) a_retu_c[value[i]] = c;
      rep(i,b_retu[key].size()) b_retu_c[b_retu[key][i]]=c;
      c++;
    }
    string str1(a_line_c.begin(),a_line_c.end());
    string str2(b_line_c.begin(),b_line_c.end());
    string str3(a_retu_c.begin(),a_retu_c.end());
    string str4(b_retu_c.begin(),b_retu_c.end());
    //cout << "str1 " << str1 << endl;
    //cout << "str2 " << str2 << endl;
    //cout << "str3 " << str3 << endl;
    //cout << "str4 " << str4 << endl;
    res += minSwaps(str1, str2);
    res += minSwaps(str3, str4);
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
}