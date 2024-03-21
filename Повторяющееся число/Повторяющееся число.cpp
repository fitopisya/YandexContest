#include <iostream>
#include <deque>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    deque<int> nums;
    set<int> seto;
    for (int i = 0; i < n; ++i){
        int value;
        cin >> value;
        nums.push_back(value);
        if (seto.count(value)){
            cout << "YES";
            return 0;
        }
        if (nums.size() >= k) {
            seto.erase(nums.front());
            nums.pop_front();
        }
        seto.insert(value);
    } cout << "NO";
}
