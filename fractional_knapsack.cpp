#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void sort_max_to_min(vector<double> &values, vector<double> &weights, long left, long right) {
// using bubble sort
  
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  sort_max_to_min(values, weights, 0, (long)values.size()-1);
  // cout << "Idhar aaya bhai" << endl;

  for (int i=0; i<values.size(); i++) {
    if (capacity == 0)
      return value;

    if (weights[i] <= capacity) {
      value += values[i];
      capacity -= weights[i];
    } else {
      value += capacity * (values[i]/weights[i]);
      capacity = 0;
    }
  }

  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
