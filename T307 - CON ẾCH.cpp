
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main(){
	ll F[51];
	F[0] = 1; F[1] = 1; F[2] = 2;
	for(int i =3; i <=50; i++){
		F[i] = F[i-1] + F[i-2] + F[i-3];
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << F[n] << endl;
	}
	return 0;
}

