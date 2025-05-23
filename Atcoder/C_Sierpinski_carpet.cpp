#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct pos{
    int x;
    int y;
};

void sierpinski(vector<string> &carpet, int n, pos inicial){
    if(n == 0){
        carpet[inicial.x][inicial.y] = '#';
        return;
    }
    int offset = pow(3, n - 1);
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i != 1 || j != 1){
                sierpinski(carpet, n-1, {inicial.x + offset*i, inicial.y + offset*j});
            }
        }
    }    
}

void solve(int testcase){
    int n; cin >> n;
    vector<string> carpet(pow(3, n), string(pow(3, n), '.'));
    sierpinski(carpet, n, {0, 0});
    for(int i = 0; i<carpet.size(); i++){
        cout << carpet[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}