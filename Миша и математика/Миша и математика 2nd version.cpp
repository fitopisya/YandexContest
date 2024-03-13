#include <iostream>
#include <vector>
using namespace std;
enum class State{
    NO_ODD_SUMMAND,
    LAST_ODD,
    MULTIPLY_EVEN
};

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }
    State state = State::NO_ODD_SUMMAND;
    string res;
    for (const auto el : nums){
        switch(state){
            case State::NO_ODD_SUMMAND:
            if(el % 2 == 0){
                res.push_back('+');
            } else {
                state = State::LAST_ODD;
            }
            break;
            case State::LAST_ODD:
            if(el % 2 == 0){
                res.push_back('+');
                state = State::MULTIPLY_EVEN;
            } else {
                res.push_back('x');
            }
            break;
            case State::MULTIPLY_EVEN:
            res.push_back('x');
            break;
        }
    } cout << res;
}
