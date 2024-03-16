#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<set<string>> songs_vec(n);
    for (int i = 0; i < n; ++i){
        int songsNum;
        cin >> songsNum;
        for (int j = 0; j < songsNum; ++j){
            string song;
            cin >> song;
            songs_vec[i].insert(song);
        }
    }
    
    if (n == 1){
        cout << songs_vec[0].size() << endl;
        for (const auto& el : songs_vec[0]){
            cout << el << ' ';
        } return 0;
    }

    set<string> common_songs;
    set_intersection(songs_vec[0].begin(), songs_vec[0].end(), songs_vec[1].begin(), songs_vec[1].end(), inserter(common_songs, common_songs.begin()));
    for (int i = 2; i < n; ++i){
        set<string> tmp;
        set_intersection(songs_vec[i].begin(), songs_vec[i].end(), common_songs.begin(), common_songs.end(), inserter(tmp, tmp.begin()));
        common_songs.swap(tmp);
    }

    cout << common_songs.size() << endl;
    for (const auto& el : common_songs){
        cout << el << ' ';
    }
    cout << endl;
}
