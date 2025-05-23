#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int n;

void rotate(int &i, int &j){
    int t = i;
    i = j;
    j = n - 1 - t;
}

void solve(int testcase){
    cin >> n;
    vector<vector<char>> S(n, vector<char>(n)), T(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> S[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> T[i][j];
        }
    }

    vector<int> ans = {0, 1, 2, 3};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int t_i = i, t_j = j;
            for(int rot = 0; rot < 4; rot++){
                if(S[i][j] != T[t_i][t_j]) ans[rot]++;
                rotate(t_i, t_j);
            }
        }
    }

    cout << *min_element(all(ans)) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}