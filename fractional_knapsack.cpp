#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void sort_max_to_min(vector<double> &values, vector<double> &weights, long left, long right) {
// using bubble sort
  long n = right;
  cout << n << endl;
  for (int i=0; i<n; i++)
    cout << values[i] << ' ' << weights[i] << endl;
  while (n != 0) {
    long newn = 0;
    for (int i=1; i<n-1; i++) {
      if (values[i-1] > values[i]) {
        double temp = values[i-1];
        values[i-1] = values[i];
        values[i] = temp;
        temp = weights[i-1];
        weights[i-1] = weights[i];
        weights[i] = temp;
        newn = i;
      }
      n = newn;
    }
  }
  cout << "-------" << endl;
  for (int i=0; i<right; i++)
    cout << values[i] << ' ' << weights[i] << endl;
  // procedure bubbleSort( A : list of sortable items )
  //   n = length(A)
  //   repeat
  //      newn = 0
  //      for i = 1 to n-1 inclusive do
  //         if A[i-1] > A[i] then
  //            swap(A[i-1], A[i])
  //            newn = i
  //         end if
  //      end for
  //      n = newn
  //   until n = 0
  // end procedure
  
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  sort_max_to_min(values, weights, 0, (long)values.size());
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
