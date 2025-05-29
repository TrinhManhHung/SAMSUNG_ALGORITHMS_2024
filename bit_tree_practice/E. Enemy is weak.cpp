//https://codeforces.com/problemset/problem/61/E

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct MaxFenwickTree{
	int n;
	vi bit;
	
	MaxFenwickTree(int _n){
		n = _n;
		bit.assign(n+5, 0);
	}
	
	void update(int val){
		for(; val >=1; val -= (val & - val)){
			bit[val]++;
		}
	}
	
	int get(int val){
		int res = 0;
		for(; val <=n; val += (val & - val)){
			res += bit[val];
		}
		return res;
	}
};

struct MinFenwickTree{
	int n;
	vi bit;
	
	MinFenwickTree(int _n){
		n = _n;
		bit.assign(n+5, 0);
	}
	
	void update(int val){
		for(; val <=n; val += (val & - val)){
			bit[val]++;
		}
	}
	
	int get(int val){
		int res = 0;
		for(; val >=1; val -= (val & - val)){
			res += bit[val];
		}
		return res;
	}
};

void solve(){
	int n; cin >> n;
	int a[n+1];
	set<int> se;
	FOR(i, 1, n){
		cin >> a[i];
		se.insert(a[i]);
	}
	
	//compress
	int cnt = 1;
	map<int, int> mp;
	for(auto x : se){
		mp[x] = cnt;
		cnt++;
	}
	FOR(i, 1, n){
		a[i] = mp[a[i]];
	}
	
	//process
	ll res = 0;
	int cntMaxLeft[n+1] = {0};
	int cntMinRight[n+1] = {0};
	
	MaxFenwickTree fmax(n);
	MinFenwickTree fmin(n);
	
	FOR(j, 1, n){
		cntMaxLeft[j] = fmax.get(a[j]);
		fmax.update(a[j]);
	}
	
	FOD(j, n, 1){
		cntMinRight[j] = fmin.get(a[j]);
		fmin.update(a[j]);
	}
	
	FOR(j, 1, n){
		res += 1ll * cntMaxLeft[j] * cntMinRight[j];
	}
	
	cout << res << endl;
}

int main(){
    faster();
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/