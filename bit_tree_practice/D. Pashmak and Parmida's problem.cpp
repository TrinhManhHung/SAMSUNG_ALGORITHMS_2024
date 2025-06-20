// https://codeforces.com/contest/459/problem/D

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
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct FenwickTree{
	int n;
	vi bit;
	
	FenwickTree(int _n){
		n = _n + 5;
		bit.assign(n, 0);
	}
	void update(int pos){
		for(; pos <=n; pos += (pos&-pos)){
			bit[pos]++;
		}
	}
	int get(int pos){
		int res = 0;
		for(; pos > 0; pos -= (pos&-pos)){
			res += bit[pos];
		}
		return res;
	}
};

void solve(){
	int n; cin >> n;
	
	int a[n+1];
	FOR(i, 1, n) cin >> a[i];
	
	map<int, int> mp1, mp2;
	int F1[n+1] = {0}, F2[n+1] = {0}; 
	
	FOR(i, 1, n){
		mp1[a[i]]++;
		F1[i] = mp1[a[i]];
	}
	
	FOD(i, n, 1){
		mp2[a[i]]++;
		F2[i] = mp2[a[i]];
	}
	
	FenwickTree fen(n);
	ll res = 0;
	FOD(i, n, 1){
		res += fen.get(F1[i]-1);
		fen.update(F2[i]);
	}
	
	cout << res << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
    	freopen("HungHot.inp", "r", stdin);
    	freopen("HungHot.out", "w", stdout);
	}
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