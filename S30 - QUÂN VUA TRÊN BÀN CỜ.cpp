#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main(){
	int s1, s2, f1, f2; cin >> s1 >> s2 >> f1 >> f2;
	cout << max(abs(f1-s1), abs(f2 - s2));
	return 0;
}
