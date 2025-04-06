//https://oj.vnoi.info/problem/codetour24_c1_c

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
#define pii pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 2e6;

struct BIT{
	int n;
	vi bit;
	
	BIT(int _n){
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
	int n, q; cin >> n >> q;
	vi a(n), query(q), all;
	
	FOR(i, 0, n-1) cin >> a[i];
	FOR(i, 0, q-1){
		cin >> query[i];
		all.pb(query[i]);
	}
	
	//nen so
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	
	auto getPos = [&](int x){
		return upper_bound(all.begin(), all.end(), x) -all.begin() +1;
	};
	
    //solve
	BIT bit(all.sz);
	for(auto x : query){
		int idx = upper_bound(a.begin(), a.end(), x) - a.begin() +1;
		int add = bit.get(getPos(x));
//		SHOW2(idx, add);
		cout << idx + add << endl;
		bit.update(getPos(x));
	}
}	


int main() {
    faster();
    int t = 1; 
//	cin >> t;
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
