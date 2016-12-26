#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void sort_max_to_min(vector<double> &values, vector<double> &weights, long left, long right) {
// using quicksort
  long i = left;
  long j = right;
  double temp;
  double pivot = ((double)values[left]/weights[left] + (double)values[right]/weights[right])/2;// + 
                      // (double)values[(left + right)/2]/weights[(left + right)/2])/3;
  // cout << "Idhar to bhi aaya bhai" << endl;

  while (i <= j) {
    while ((double)values[i]/weights[i] > pivot)
      i++;

    while ((double)values[j]/weights[j] < pivot)
      j--;

    if (i <= j) {
      temp = values[i];
      values[i] = values[j];
      values[j] = temp;
      temp = weights[i];
      weights[i] = weights[j];
      weights[j] = temp;
      i++;
      j--;
    }

    if (left < j)
      sort_max_to_min(values, weights, left, j);
    if (i < right)
      sort_max_to_min(values, weights, i, right);
  }
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
