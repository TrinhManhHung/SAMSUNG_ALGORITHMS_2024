//Tap con ke tiep
#include<bits/stdc++.h>
using namespace std;

void Solve(){
	int n, k; cin >> n >> k;
	int a[k+1];
	for(int i=1; i<=k; i++) cin >> a[i];
	int idx = k;
	while(idx >= 1 && a[idx] == n - k + idx){
		idx--;
	}
	if(idx == 0){
		for(int i=1; i<= k; i++) a[i] = i;
	}
	else if(idx >= 1){
		a[idx]++;
		for(int j=idx+1; j<=k; j++) a[j] = a[j-1] + 1;
	}
	
	for(int i=1; i<=k; i++) cout << a[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
