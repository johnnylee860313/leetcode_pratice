class FoodRatings {
 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    for (int i = 0; i < foods.size(); ++i) {
      cuisineToRatingAndFoods[cuisines[i]].insert({-ratings[i], foods[i]});//set 是紅黑數，由小到大
      foodToCuisine[foods[i]] = cuisines[i];
      foodToRating[foods[i]] = ratings[i];
    }
  }

  void changeRating(string food, int newRating) {
    const string cuisine = foodToCuisine[food];
    const int oldRating = foodToRating[food];
    auto& ratingAndFoods = cuisineToRatingAndFoods[cuisine];
    ratingAndFoods.erase({-oldRating, food});//set 才有支援刪除特定元素, pq無法
    ratingAndFoods.insert({-newRating, food});
    foodToRating[food] = newRating;
  }

  string highestRated(string cuisine) {
    return cuisineToRatingAndFoods[cuisine].begin()->second;
  }

 private:
  unordered_map<string, set<pair<int, string>>> cuisineToRatingAndFoods;
  unordered_map<string, string> foodToCuisine;
  unordered_map<string, int> foodToRating;
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */