/*
BÀI J. VẪN LÀ TỔNG CÁC CHỮ SỐ (Thời gian: 2s)
Cho hai số nguyên A và B. Xâu S được xây dựng bằng cách viết liền các số từ A, A + 1, …,B
Ví dụ: A = 40 và B = 42, ta có S = 404142. Tổng các chữ số của xâu S bằng 4 + 0 + 4 + 1+ 4 + 2 = 15.
Nhiệm vụ của bạn là hãy tính tổng tất cả các chữ số của xâu S.
Input
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm 2 số nguyên A, B (0 < A < B ≤ 1015).
Output
Với mỗi test, hãy in ra đáp án tìm được trên một dòng
*/
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
#define MOD (ll)(1e9 + 7)
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 100005;

//hàm tính tổng từ 1 đến x
ll sum(ll x){
	return x >= 0? (x+1) * x / 2 : 0;
}

//hàm tính tổng chữ số từ 1 đến x
ll f(ll x){
	ll res = 0;
	
	res += (x/10) * 45 + sum(x % 10);
	
//	SHOW1(res);
	int cnt = 10;
	int last_digit = x % 10;
	int cur_digit = 0;
	ll last_number = x % 10;
	
	x /= 10;
	while(x){
		cur_digit = x % 10;
		x /= 10;
		res += (x)*45*cnt + sum(cur_digit-1) * cnt + (last_number+1) * cur_digit;
		
//		SHOW1((x)*45*cnt);
//		SHOW1(sum(cur_digit-1) * cnt);
//		SHOW1((last_number+1) * cur_digit);
		
		last_number = cur_digit * cnt + last_number;
		last_digit = cur_digit;
		cnt *= 10;
	}
	
	return res;
}
void solve(){
	ll a, b; cin >> a >> b;
	ll res = f(b) - f(a-1);
	cout << res << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.out", "w", stdout);
  	}
    int t; cin >> t;
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