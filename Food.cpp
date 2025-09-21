#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
        if (a.first != b.first) return a.first < b.first; // max by rating
        return a.second > b.second; // lex smaller first
    }
};

class FoodRatings {
private:
    unordered_map<string, pair<string,int>> food_to_info;
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, cmp>> cuisine_heaps;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            food_to_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_heaps[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = food_to_info[food].first;
        food_to_info[food].second = newRating;
        cuisine_heaps[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto &pq = cuisine_heaps[cuisine];
        while(true) {
            auto [rating, food] = pq.top();
            if(food_to_info[food].second == rating) return food;
            pq.pop();
        }
    }
};

int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9,12,8,15,14,7};

    FoodRatings fr(foods, cuisines, ratings);

    cout << fr.highestRated("korean") << endl;   // kimchi
    cout << fr.highestRated("japanese") << endl; // ramen

    fr.changeRating("sushi", 16);
    cout << fr.highestRated("japanese") << endl; // sushi

    fr.changeRating("ramen", 16);
    cout << fr.highestRated("japanese") << endl; // ramen

    return 0;
}
