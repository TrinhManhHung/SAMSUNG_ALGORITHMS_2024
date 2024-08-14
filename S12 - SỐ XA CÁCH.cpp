#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[10];

bool check(){
	for(int i =2; i <=n; i++){
		if(abs(a[i] - a[i-1]) == 1) return false;
	}
	return true;
}
int main() {
    int t; cin >> t;
    while(t--){
    	cin >> n;
    	for(int i =1; i <=n; i++){
    		a[i] = i;
		}
		do{
			if(check()){
				for(int i =1; i <=n; i++) cout << a[i];
				cout << "\n";
			}
		}while(next_permutation(a+1, a+n+1));
	}
    return 0;
}
