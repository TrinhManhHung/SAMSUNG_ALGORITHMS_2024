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

const ll MOD = 1e9 + 7;
const int maxn = 10000000;
const int LOG = 18;
const int MAXSZ = 25;

struct Matrix{
    int n, m;
    ll d[MAXSZ+5][MAXSZ+5];

    Matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        memset(d, 0, sizeof(d));
    }

    Matrix operator * (const Matrix o) const{
        int x = n, y = m, z = o.m;
        Matrix res(x, z);

        FOR(i, 0, x-1) FOR(j, 0, z-1)
            FOR(k, 0, m-1){
                res.d[i][j] += d[i][k] * o.d[k][j];
                res.d[i][j] %= MOD;
            }
        return res;
    }
};

Matrix powMod(Matrix o, ll p){
    Matrix res(o.n, o.m);
    FOR(i, 0, o.n-1) res.d[i][i] = 1;

    if(p == 0){
        return res;
    }

    Matrix half = powMod(o, p / 2);
    
    res = half * half;
    if(p & 1) res = res * o;

    return res;
}

ll n;
Matrix V3(1, 6);
Matrix A(6, 6);

void init(){
    V3.d[0][0] = 3;
    V3.d[0][1] = 2;
    V3.d[0][2] = 9;
    V3.d[0][3] = 3;
    V3.d[0][4] = 1;

    A.d[0][0] = 3;
    A.d[1][0] = 2;
    A.d[2][0] = 1;
    A.d[3][0] = 2;
    A.d[4][0] = 2;

    A.d[0][1] = 1;
    A.d[1][1] = 0;
    A.d[2][1] = 0;
    A.d[3][1] = 0;
    A.d[4][1] = 0;

    A.d[0][2] = 0;
    A.d[1][2] = 0;
    A.d[2][2] = 1;
    A.d[3][2] = 2;
    A.d[4][2] = 1;

    A.d[0][3] = 0;
    A.d[1][3] = 0;
    A.d[2][3] = 0;
    A.d[3][3] = 1;
    A.d[4][3] = 1;

    A.d[0][4] = 0;
    A.d[1][4] = 0;
    A.d[2][4] = 0;
    A.d[3][4] = 0;
    A.d[4][4] = 1;
}

void HuyenMay(){  
    cin >> n;
    if(n <= 3){
        cout << n << endl;
        return;
    }

    Matrix Vn = V3 * powMod(A, n-3);
    cout << Vn.d[0][0] << endl;
}

int main(){
    faster();
    init();
    int t = 1;
    cin >> t;
    while(t--){
        HuyenMay();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/

