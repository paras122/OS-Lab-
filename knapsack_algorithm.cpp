// 0/1 knapsack

#include <algorithm>
#include <iostream>

struct Item {
  int weight;
  int profit;
};

int fillKnapsack(Item *items, int knapsack_capacity, int n) {
  int *profit_array =
      static_cast<int *>(calloc(knapsack_capacity + 1, sizeof(int)));

  for (int i = 1; i <= n; i++) {
    for (int j = knapsack_capacity; j >= items[i - 1].weight; j--) {
      profit_array[j] =
          std::max(profit_array[j],
                   profit_array[j - items[i - 1].weight] + items[i - 1].profit);
    }
  }

  return profit_array[knapsack_capacity];
}

int main() {
  Item items[5] = {{2, 5}, {2, 7}, {5, 10}, {4, 3}, {6, 15}};
  std::cout << "Max Profit: " << fillKnapsack(items, 10, 5) << std::endl;

  return 0;
}
