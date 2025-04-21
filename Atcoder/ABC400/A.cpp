#include <bits/stdc++.h>
using namespace std;

int main(){
    int A; cin >> A;
    int B = 400 / A;
    if(400 % A) cout << -1;
    else cout << B;
}
