#include <iostream>
using namespace std;

bool CheckParams(unsigned long long m, unsigned long long  N){
    unsigned long long  res = 1,  spaces = 0;
    for (unsigned long long  i = 2; i <= m; ++i){
    	spaces = i;
        spaces += ((1 + i) * i) / 2; 
        res += spaces; 
    } return res <= N;
}

unsigned long long BinarySearch(unsigned long long  N){
    if (N < 1){
        return 0;
    } else if (N < 6){
        return 1;
    }
    unsigned long long l = 0, r = 100'000'000;
    while (l < r){
        unsigned long long m = (l + r) / 2;
        if (CheckParams(m, N)){
            l = m + 1;
        } else {
            r = m;
        }
    }
    return --r;
}

int main()
{
    unsigned long long N;
    cin >> N;
    cout << BinarySearch(N) << endl;
}
