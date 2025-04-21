#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m; cin >> n >> m;
    long long x = 0;
    for(int i = 0; i <= m; i++){
        x += pow(n, i);
        if(x > 10e9){
            cout << "inf";
            return 0;
        }
    }
    cout << x;
}