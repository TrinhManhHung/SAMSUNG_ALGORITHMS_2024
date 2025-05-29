//https://www.spoj.com/PTIT/problems/PTIT016B/

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

int countX(string s1, string s2, int X){
	FOR(i, 0, s1.sz-1){
		if(s1[i] != s2[i]){
			return i;
		}
	}
	return s1.sz;
}

void solve(){
	int N, K, M, P, Q; cin >> N >> K >> M >> P >> Q;
	
	vector<vector<string>> bookStore(N);
	FOR(i, 0, N-1){
		FOR(j, 0, K-1){
			string s; cin >> s;
			bookStore[i].pb(s);
		}
	}
	
	vector<string> newBook;
	FOR(i, 1, M){
		string s; cin >> s;
		newBook.pb(s);
	}
	
	while(Q--){
		int X; cin >> X;
		
		vector<string> v;
		FOR(i, 0, K-1){
			int idx; cin >> idx;
			idx--;
			v.pb(newBook[idx]);
		}
		
		int ans = 0;
		FOR(i, 0, N-1){
			int minX = 25;
			FOR(j, 0, K-1){
				if(minX < X) break;
				minX = min(minX, countX(bookStore[i][j], v[j], X));
			}
			if(minX == X) ans++;
		}
		
		cout << ans << endl;
	}
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