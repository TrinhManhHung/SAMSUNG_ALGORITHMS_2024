// LIỆT KÊ XÂU KÝ TỰ

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

char c; int n;
int sz;
int X[100];

void Display(){
    for(int i =1; i <=n; i++){
        cout << char(X[i] +'A' -1);
    }
    cout << '\n';
}
void Try(int i){
    for(int j = X[i-1]; j <=sz; j++){
        X[i] = j;
        if(i == n){
            Display();
        }
        else Try(i+1);
    }
}
int main(){
    cin >> c >> n;
    sz = c - 'A' + 1;
    X[0] = 1;
    Try(1);
}


