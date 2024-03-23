#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums;
    nums.reserve(N);
    for (int i = 0; i < N; ++i){
        int value;
        cin >> value;
        nums.push_back(value);
    }
    sort(nums.begin(), nums.end());
    int K;
    cin >> K;
    vector<pair<int, int>> pairs;
    pairs.reserve(K);
    for (int i = 0; i < K; ++i){
        int key, value;
        cin >> key >> value;
        pairs.push_back({key,value});
    }
    for (int j = 0; j < K; ++j){
        cout << distance(
            lower_bound(nums.begin(), nums.end(), pairs[j].first), 
            upper_bound(lower_bound(nums.begin(), nums.end(), pairs[j].first), nums.end(), pairs[j].second)
            ) << ' ';
    }
}
