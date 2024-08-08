// XÂU NHỊ PHÂN XEN KẼ

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main(){
	int n; cin >> n;
	for(int i =1; i <=n; i++){
		if(i % 2 == 1) cout << 0 << " ";
		else cout << 1 << " ";
	}
	cout << endl;
	for(int i =1; i <=n; i++){
		if(i % 2 == 0) cout << 0 << " ";
		else cout << 1 << " ";
	}
	return 0;
}
