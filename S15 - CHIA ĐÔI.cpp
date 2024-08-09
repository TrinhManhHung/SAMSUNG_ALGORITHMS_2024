#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

void Catalan(int l, int r, int pt[]){
	for(int i =l; i <=r; i++){
		int tmp = i;
		for(int j =2; j <=sqrt(i); j++){
			while(tmp % j ==0){
				pt[j]++;
				tmp /= j;
			}
		}
		if(tmp != 1) pt[tmp]++;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		//Xem cong thuc tinh so Catalan
		int ptTu[65] = {0};
		int ptMau[65] = {0};
		Catalan(n+2, 2*n, ptTu);
		Catalan(1, n, ptMau);
		//Ket qua
		ll res = 1;
		for(int i =1; i <=60; i++){
			res *= (ll)pow(i, ptTu[i] - ptMau[i]);
		}
		cout << res << endl;
	}
	return 0;
}