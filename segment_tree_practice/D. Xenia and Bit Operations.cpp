//https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 2000000;

int a[maxn+1];

struct segmentTree{
	int n;
	vi t;
	
	segmentTree(int _n){
		n = _n;
		t.assign(4*n+5, 0);
	}
	
	void build(int i, int l, int r, int level){
		if(l == r){
			t[i] = a[l];
			return;
		}
		else{
			int mid = (l+r) >> 1;
			build(2*i, l, mid, level-1);
			build(2*i+1, mid+1, r, level-1);
			
			//odd
			if(level & 1){
				t[i] = t[2*i] | t[2*i+1];
			}
			//even
			else{
				t[i] = t[2*i] ^ t[2*i+1];
			}
		}
	}
	
	void update(int i, int l, int r, int pos, int val, int level){
		if(l == r){
			t[i] = val;
			return;
		}
		int mid = (l+r) >> 1;
		if(pos <= mid) update(2*i, l, mid, pos, val, level-1);
		else update(2*i+1, mid+1, r, pos, val, level-1);

			//odd
		if(level & 1){
			t[i] = t[2*i] | t[2*i+1];
		}
		//even
		else{
			t[i] = t[2*i] ^ t[2*i+1];
		}
	}
};

void solve(){
	int n, q; cin >> n >> q;
	int bac = n;
	n = 1 << n;
	segmentTree st(n);
	
	FOR(i, 1, n) cin >> a[i];
	st.build(1, 1, n, bac);
	
	
	while(q--){
		int pos; ll val; cin >> pos >> val;
		st.update(1, 1, n, pos, val, bac);
//		FOR(i, 1, 4*n) cout << st.t[i] << " ";
//		cout << endl;
		cout << st.t[1] << endl;
	}
}

int main() {
    faster();
//    int t; cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/