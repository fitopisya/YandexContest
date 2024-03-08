#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    vector<int> lengths;
    lengths.reserve(N);
    for (int i = 0; i < N; ++i){
        int value;
        cin >> lengths.emplace_back(value);
    }
    int longest = lengths[0], tmp = lengths[0];
    for (int i = 1; i < N; ++i){
        if (longest < lengths[i]) {
            longest = lengths[i];
        }
        tmp += lengths[i];
    }
    if(tmp - longest >= longest){
        cout << tmp << endl;
    } else {
        tmp -= longest;
        cout << longest - tmp << endl;
    }
}
