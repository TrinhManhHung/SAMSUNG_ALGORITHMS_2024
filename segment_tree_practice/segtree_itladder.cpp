// https://oj.vnoi.info/problem/segtree_itladder

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
const int maxn = 1e5;
const ll mi = LLONG_MIN;
const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    ll res = (a % MOD) * (b % MOD) % MOD;
    return res;
}

ll add(ll a, ll b){
    return (a+b) % MOD;
}

ll SUM_INT(int l, int r){
    ll res = 1LL * (r+l)*(r-l+1)/2;
    return res % MOD;
}

struct segmentTree{
	int n;
	vll sum; 
    vector<pair<ll, ll>> lazy;
	
	segmentTree(int _n){
		n = _n;
		sum.assign(4*n+5, 0);
        lazy.assign(4*n+5, make_pair(0, 0));
	}

    void pushDown(int i, int l, int r){
        if(lazy[i].fi == 0 && lazy[i].se == 0) return;

        int mid = (l + r) >> 1;
        sum[2*i] = add(sum[2*i], add( mul(SUM_INT(l, mid), lazy[i].fi), mul(mid -l +1, lazy[i].se) ));
        sum[2*i+1] = add(sum[2*i+1], add( mul(SUM_INT(mid+1, r), lazy[i].fi), mul(r -(mid+1) +1, lazy[i].se) ));
        
        lazy[2*i].fi = add(lazy[2*i].fi, lazy[i].fi); lazy[2*i].se = add(lazy[2*i].se, lazy[i].se);
        lazy[2*i+1].fi = add(lazy[2*i+1].fi, lazy[i].fi); lazy[2*i+1].se = add(lazy[2*i+1].se, lazy[i].se);

        lazy[i].fi = 0; lazy[i].se = 0;
    }

    void update(int i, int l, int r, int L, int R, ll A, ll B){
        if(r < L || l > R || l > r || L > R) return;
        if(L <= l && r <= R){
            ll temp = (B - (L * A) % MOD + MOD) % MOD;
            sum[i] = add(sum[i], add( mul(SUM_INT(l, r), A), mul((r-l+1), temp) ));
            lazy[i].fi += A;
            lazy[i].se += temp;
            return;
        }

        int mid = (l + r) >> 1;
        pushDown(i, l, r);
        update(2*i, l, mid, L, R, A, B);
        update(2*i+1, mid+1, r, L, R, A, B);

        sum[i] = add(sum[2*i], sum[2*i+1]);
    }

    ll getSum(int i, int l, int r, int u, int v){
        if(r < u || l > v || l > r || u > v) return 0;
        if(u <= l && r <= v) return sum[i];

        int mid = (l + r) >> 1;
        pushDown(i, l, r);
        ll sumL = getSum(2*i, l, mid, u, v);
        ll sumR = getSum(2*i+1, mid+1, r, u, v);

        return add(sumL, sumR);
    }
};

void solve(){
	int n, m; cin >> n >> m;
    segmentTree t(n);
    while(m--){
        int type; cin >> type;
        if(type == 1){
            int l, r; ll a, b; cin >> l >> r >> a >> b;
            t.update(1, 1, n, l, r, a, b);
        } else{
            int l, r; cin >> l >> r;
            ll res = t.getSum(1, 1, n, l, r);
            cout << res << endl;
        }
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
5 4
1 1 5 1 1
2 1 5
1 2 3 1 1
2 1 5
**/
