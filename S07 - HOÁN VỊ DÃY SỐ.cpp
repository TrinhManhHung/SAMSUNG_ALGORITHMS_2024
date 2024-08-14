#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"
 
int main(){
	int n; cin >> n;
	int a[n];
	for(int i =0; i <n; i++) cin >> a[i];
	sort(a, a+n);
	do{
		for(int i =0; i <n; i++) cout << a[i] << " ";
		cout << "\n";
	}while(next_permutation(a, a+n));
	return 0;
}
