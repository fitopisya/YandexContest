#include <iostream>
using namespace std;

bool CheckParams(unsigned long long m, unsigned long long N){
    return (m++) * m / 2 < N;
}

unsigned long long BinarySearch(unsigned long long N){
    unsigned long long l = 0, r = 10'000'000'000;
    while (l < r){
        unsigned long long m = (l + r) / 2;
        if (CheckParams(m, N)){
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}

int main()
{
    unsigned long long N;
    cin >> N;
    unsigned long long fraction = BinarySearch(N);
    N -= fraction * (fraction - 1) / 2; 
    (fraction & 1) ? cout << N << '/' << (++fraction - N) : cout << (++fraction - N) << '/' << N;
}
