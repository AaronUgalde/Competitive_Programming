#include <bits/stdc++.h>
using namespace std;

void solve(){
    string p; cin >> p;
    string s; cin >> s;

    vector<tuple<char, int, int>> soundsAllowed;
    char active = p[0];
    int minNumber = 1, maxNumber = 2;
    for(int i = 1; i<p.size(); i++){
        if(p[i] != active){
            soundsAllowed.emplace_back(active, minNumber, maxNumber);
            active = p[i];
            minNumber = 1;
            maxNumber = 2;
        }else{
            minNumber++;
            maxNumber += 2;
        }
    }
    soundsAllowed.emplace_back(active, minNumber, maxNumber);

    int currentSound = 0;
    int number = 1;
    char currentChar = s[0];

    for(int i = 1; i<s.size(); i++){
        if(s[i] != currentChar){
            if(currentChar != get<0>(soundsAllowed[currentSound]) || number < get<1>(soundsAllowed[currentSound]) || number > get<2>(soundsAllowed[currentSound])){
                cout << "NO" << endl;
                return;
            }
            currentSound++;
            number = 1;
            currentChar = s[i];
        }else{
            number++;
        }
    }

    if(currentChar != get<0>(soundsAllowed[currentSound]) || number < get<1>(soundsAllowed[currentSound]) || number > get<2>(soundsAllowed[currentSound])){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i<t; i++){
        solve();   
    }
}