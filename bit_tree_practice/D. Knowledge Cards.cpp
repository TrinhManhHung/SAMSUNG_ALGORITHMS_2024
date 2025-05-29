//https://codeforces.com/contest/1740/problem/D

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 1e5+5;
const ll inf = LLONG_MAX;

struct FenwickTree{
	int n;
	vi bit; //bit[i] so cac cap nghich the
	
	FenwickTree(int _n){
		n = _n;
		bit.assign(n+5, 0);
	}
	
	void update(int val){
		for(; val >= 1; val -= (val & -val)){
			bit[val]++;
		}
	}
	
	int get(int val){
		int res = 0;
		for(; val <= n; val += (val & -val)){
			res += bit[val];
		}
		return res;
	}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	
	FenwickTree f(k);
	vector<pair<int, pii>> v; //<a[i], <i, bit[i]>>
	FOR(i, 1, k){
		int x; cin >> x;
		v.pb({x, {i, f.get(x)}});
		f.update(x);
	}
	
	sort(v.begin(), v.end());
	
	ll numBlankCell = 1ll * n * m - 2;
	for(auto x : v){
		int idx = x.se.fi;
		int used = x.se.se;
		if(idx -used >= numBlankCell){
			cout << "TIDAK\n";
			return;
		}
	}
	
	cout << "YA\n";
	
}

int main() {
    faster();
    if(fopen("HungHot.inp", "r")){
    	freopen("HungHot.inp", "r", stdin);
    	freopen("HungHot.out", "w", stdout);
	}
    int t = 1; 
	cin >> t;
    while (t--) {
    	solve();
	}
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/