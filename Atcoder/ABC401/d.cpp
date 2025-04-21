#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for(int i = 0; i<n; i++){
        if(s[i] == 'o'){
            k--; //Restamos las 'o' que ya tenemos
            if(i - 1 >= 0){
                s[i - 1] = '.';
            }
            if(i + 1 < n){
                s[i + 1] = '.';
            }
        }
    }

    vector<int> subQuestions(n, 0);
    bool isSub = false;
    int currentSub = -1;
    int numberOfSub = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '?'){
            if(isSub == false){
                currentSub++;
                isSub = true;
                numberOfSub++;
            }
            subQuestions[currentSub]++;
        }else{
            isSub = false;
        }
    }


    int numberOfO = 0;
    for(int i = 0; i<numberOfSub; i++){
        numberOfO += subQuestions[i] / 2 + 1;
    }

    int currentSub = -1;
    bool isSub2 = false;
    if(numberOfO == k){
        for(int i = 0; i<n; i++){
            if(s[i] == '?'){
                if(isSub2 == false){
                    currentSub++;
                    isSub2 = true;
                }
            }else{
                isSub2 = false;
            }
        }
    }
}