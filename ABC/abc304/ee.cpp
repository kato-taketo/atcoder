#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int N;
class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param N 要素数
	explicit UnionFind(size_t N)
		: m_parentsOrSize(N, -1) {}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parentsOrSize[i] < 0)
		{
			return i;
		}

		// 経路圧縮
		return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (-m_parentsOrSize[a] < -m_parentsOrSize[b])
			{
				std::swap(a, b);
			}

			m_parentsOrSize[a] += m_parentsOrSize[b];
			m_parentsOrSize[b] = a;
		}
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return -m_parentsOrSize[find(i)];
	}

private:

	// m_parentsOrSize[i] は i の 親,
	// ただし root の場合は (-1 * そのグループに属する要素数)
	std::vector<int> m_parentsOrSize;
};
int main(void) {
  int M;
  cin >> N >> M;
  vector<int> u(M),v(M);
  rep(i,M) cin >> u[i] >> v[i];
  int K;
  cin >> K;
  vector<int> x(K),y(K);
  rep(i,K) cin >> x[i] >> y[i];
  int Q;
  cin >> Q;
  vector<int> p(Q),q(Q);
  rep(i,Q) cin >> p[i] >> q[i];

  UnionFind uf(N);
  //uf.init(N);
  rep(i,M) {
    u[i]--; v[i]--;
    uf.merge(u[i],v[i]);
  }
  // 事前check
  bool good=true;
  map<pair<int,int>,int> mp;
  rep(i,K) {
    x[i]--; y[i]--;
    if(uf.connected(x[i],y[i])) good=false;
    pair<int,int> P = make_pair(uf.find(x[i]), uf.find(y[i]));
    mp[P]=1;
  }

  rep(i,Q) {
    p[i]--; q[i]--;
    if(good==false) cout << "No" << endl;
    else {
      if(uf.connected(p[i],q[i])) cout << "Yes" << endl;
      else {
        pair<int,int> P = make_pair(uf.find(p[i]), uf.find(q[i]));
        if(mp[P]==1) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
    }
  }
}