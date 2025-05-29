//https://www.spoj.com/PTIT/problems/PTIT016G/

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

//Tinh to hop chia du cho M khong nguyen to
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) return x = 1, y = 0, a;
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) return -1; 
    return (x % m + m) % m;
}

ll C_mod_pe(ll n, ll k, ll p, ll pe) {
    if (n < k) return 0;
    vector<ll> fac(pe, 1);
    for (ll i = 1; i < pe; ++i)
        if (i % p != 0)
            fac[i] = fac[i - 1] * i % pe;
        else
            fac[i] = fac[i - 1];

    function<ll(ll, ll)> C = [&](ll n, ll k) {
        if (k > n) return 0LL;
        if (k == 0 || k == n) return 1LL;

        ll res = 1;
        while (n > 0 || k > 0) {
            ll ni = n % pe, ki = k % pe;
            if (ki > ni) return 0ll;
            res = res * fac[ni] % pe;
            res = res * mod_inv(fac[ki] * fac[ni - ki] % pe, pe) % pe;
            n /= p;
            k /= p;
        }
        return res;
    };
    return C(n, k);
}

ll crt(const vector<ll> &rem, const vector<ll> &mods) {
    ll M = 1;
    for (ll m : mods) M *= m;
    ll result = 0;
    for (size_t i = 0; i < rem.size(); ++i) {
        ll mi = mods[i];
        ll Mi = M / mi;
        ll inv = mod_inv(Mi, mi);
        result = (result + rem[i] * Mi % M * inv % M) % M;
    }
    return result;
}

vector<pair<ll, int>> factorize(ll M) {
    vector<pair<ll, int>> factors;
    for (ll p = 2; p * p <= M; ++p) {
        if (M % p == 0) {
            int count = 0;
            while (M % p == 0) M /= p, ++count;
            factors.emplace_back(p, count);
        }
    }
    if (M > 1) factors.emplace_back(M, 1);
    return factors;
}

ll comb_general(ll n, ll k, ll M) {
    vector<pair<ll, int>> factors = factorize(M);
    vector<ll> rems, mods;
    for (auto x : factors) {
    	ll p = x.fi;
    	int e = x.se;
        ll pe = 1;
        for (int i = 0; i < e; ++i) pe *= p;
        mods.push_back(pe);
        rems.push_back(C_mod_pe(n, k, p, pe));
    }
    return crt(rems, mods);
}

void solve(){
	ll n, k, M; cin >> n >> k >> M;
	ll a[k+1];
	
	ll sum = 0;
	FOR(i, 1, k){
		cin >> a[i];
		sum += a[i];
	}
	
	n -= sum;
	ll total_n = n + k - 1;
	ll total_k = k - 1;
	
//	SHOW2(total_n, total_k);
//	if(total_n < total_k){
//		cout << 0 << endl;
//		return;
//	}
	cout << comb_general(total_n, total_k, M) << endl;
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