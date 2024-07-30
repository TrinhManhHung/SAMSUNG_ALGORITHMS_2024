// MÃ GRAY

#include<bits/stdc++.h>
using namespace std;

int a[15]; int n; 
bool isFinish;
void init(){
    isFinish = false;
    a[0] = 0;
    for(int i =1; i <=n; i++) a[i] = 0;
}
void sinh(){
    int idx = n;
    while(idx >=1 && a[idx] == 1){
        a[idx] = 0;
        idx--;
    }
    if(idx == 0) isFinish = true;
    else a[idx] = 1;
}
void display(){
    for(int i=1; i <=n; i++){
        cout << (a[i-1] + a[i]) % 2;
    }
    cout << " ";
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        init();
        while(!isFinish){
            display();
            sinh();
        }
        cout << endl;
    }
    return 0;
}