#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> Prices;
    for (int i = 0; i < N; ++i){
        int price;
        cin >> price;
        Prices.emplace_back(price);
    }
    Prices.emplace_back(-1);
    int BestProfit = 0, PricesIndex = 0;
    while(true){
        if (Prices.at(PricesIndex) == -1){
            break;
        } 
        int FishPurchaseDay = Prices.at(PricesIndex);
        for(int i = 1; i <= K; ++i){
            if (Prices.at(PricesIndex + i) == -1){
                break;
            }
            int FishSellDay = Prices.at(PricesIndex + i);
            if (FishSellDay - FishPurchaseDay > BestProfit){
                BestProfit = FishSellDay - FishPurchaseDay;
            } 
        }
        ++PricesIndex;
    } cout << BestProfit;
}
