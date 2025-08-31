#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans;
    for(int i = 0; i < 297; i++){
        cout << "pop" << endl;
        cin >> ans;
        if(ans == -1) break;
    }
    int a = 1, b = 2;
    cout << "push 1" << endl;
    cout << "push 2" << endl;
    cout << "pop" << endl;
    int x; cin >> x;
    if(x == a) cout << "queue" << endl;
    else cout << "stack" << endl;
}