#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void insertion_sort(vector<double> &v, vector<double> &w) { // using quicksort
  for (long i = 1; i < v.size(); i++) {
    double xv = v[i];
    double xw = w[i];
    long j = i - 1;
    while (j >= 0 && (double)v[j]/w[j] < (double)xv/xw) {
      v[j+1] = v[j];
      w[j+1] = w[j];
      j = j - 1;
    }
    v[j+1] = xv;
    w[j+1] = xw;
    // cout << "Sorted array: " << endl;
    // for (int k=0; k<v.size(); k++)
    //   cout << v[k] << ' ' << w[k] << endl;
  }
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  insertion_sort(values, weights);
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
  for (int i = 0; i < n; i++)
    std::cin >> values[i] >> weights[i];

  // for (int k=0; k<values.size(); k++)
  //   cout << values[k] << ' ' << weights[k] << endl;

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
