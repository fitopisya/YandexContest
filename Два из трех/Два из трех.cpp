#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<set<int>> nums(3);
    for (int i = 0; i < nums.size(); ++i){
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j){
            int value;
            cin >> value;
            nums[i].insert(value);
        }
    }
    set<int> intersect_1_2, intersect_0_2, intersect_0_1, res;
    set_intersection(nums[0].begin(), nums[0].end(), nums[1].begin(), nums[1].end(), inserter(intersect_0_1, intersect_0_1.begin())); // 1 && 2
    set_intersection(nums[0].begin(), nums[0].end(), nums[2].begin(), nums[2].end(), inserter(intersect_0_2, intersect_0_2.begin())); // 1 && 3
    set_intersection(nums[1].begin(), nums[1].end(), nums[2].begin(), nums[2].end(), inserter(intersect_1_2, intersect_1_2.begin())); // 2 && 3
    res.insert(intersect_0_1.begin(), intersect_0_1.end());
    res.insert(intersect_0_2.begin(), intersect_0_2.end());
    res.insert(intersect_1_2.begin(), intersect_1_2.end());
    for (const auto el : res){
        cout << el << ' ';
    }
    cout << endl;
}
