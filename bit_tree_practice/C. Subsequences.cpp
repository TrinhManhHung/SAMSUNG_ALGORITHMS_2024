//https://codeforces.com/contest/597/problem/C

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

struct BIT{
	int n;
	vector<ll> bit;
	
	BIT(int size){
		n = size;
		bit.assign(n+1, 0);
	}
	void update(int pos, ll val){
		for(; pos <=n; pos += pos & -pos){
			bit[pos] += val;
		}
	}
	//tong cac phan tu dung truoc pos = a[i] va co do dai doan tang la l
	ll get(int pos){
		ll res = 0;
		for(; pos >0; pos -= pos & -pos){
			res += bit[pos];
		}
		return res;
	}
};

void solve(){
	int n, k; cin >> n >> k;
	int a[n+1];
	ll dp[n+1][k+2]; //dp[i][l] so day con tang co do dai l ket thuc o i
	memset(dp, 0, sizeof(dp));
	FOR(i, 1, n){
		cin >> a[i];
		dp[a[i]][1] = 1;
	}
	
	FOR(l, 2, k+1){
		BIT fen(n+1);
		FOR(i, 1, n){
			fen.update(a[i], dp[a[i]][l-1]);
			dp[a[i]][l] = fen.get(a[i]-1);
		}
	}
	
	ll res =0;
	FOR(i, 1, n){
		res += dp[i][k+1];
	}
	
	cout << res << endl;
}

int main(){
    faster();
//    int t; cin >> t;
//    while(t--){
        solve();
//    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/