#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string a, b; cin >> a >> b;
    int end_a = 0, end_b = 0;
    for(end_a; end_a<a.size(); end_a++){
        if(a[end_a] != '0'){
            break;
        }
    }
    for(end_b; end_b<b.size(); end_b++){
        if(b[end_b] != '0'){
            break;
        }
    }

    int sizea = a.size() - end_a;
    int sizeb = b.size() - end_b;

    if(sizea == 0 && sizeb == 0){
        cout << '=' << endl;
        return;
    }

    if(sizea > sizeb){
        cout << '>' << endl;
        return;
    }else if(sizea < sizeb){
        cout << '<' << endl;
        return;
    }

    for(int i = 0; i<sizea; i++){
        if(a[end_a+i] > b[end_b+i]){
            cout << '>' << endl;
            return;
        }else if(a[end_a+i] < b[end_b+i]){
            cout << '<'<< endl;
            return;
        }
    }

    cout << '=' << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}