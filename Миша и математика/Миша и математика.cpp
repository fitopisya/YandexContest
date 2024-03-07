#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> GetSigns(vector<int>& nums){
    vector<char> signs;
    signs.reserve(nums.size() - 1);
    int nextNum = nums.back();
    nums.pop_back();
    while(nextNum % 2 == 0) {
        signs.emplace_back('+');
        nextNum = nums.back();
        nums.pop_back();
    }
    while (!nums.empty()) {
        if (nums.back() % 2 == 0) {
            signs.emplace_back('+');
        } else {
            signs.emplace_back('x');
        }
        nums.pop_back();
    } return {signs.rbegin(), signs.rend()};
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }
    vector<char> operations = GetSigns(nums);
    for (const auto el : operations){
        cout << el;
    }
}
