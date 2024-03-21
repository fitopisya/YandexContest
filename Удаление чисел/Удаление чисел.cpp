#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> nums;
    for (int i = 0; i < n; ++i){
        int value;
        cin >> value;
        ++nums[value];
    }
    pair<int, int> maxKeyMaxVal = *nums.begin();
    for (auto [key, value] : nums){
        if (nums.count(key + 1)){
            value += nums.at(key + 1);
        }
        if (value > maxKeyMaxVal.second){
            maxKeyMaxVal = make_pair(key, value);
        }
    }
    int res = 0;
    for (const auto [key, value] : nums){
        if (key - maxKeyMaxVal.first != 1 && key != maxKeyMaxVal.first){
            res += value;
        }
    } cout << res;
}
