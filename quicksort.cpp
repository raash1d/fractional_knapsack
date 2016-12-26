#include <iostream>
#include <vector>
// #include <tuple>

using std::vector;
// using std::tuple;
using std::cout;
using std::cin;
using std::endl;

void sort_max_to_min(vector<int> &values, int left, int right) { // using quicksort
  // vector<int> v=values, w=values;
  int i = left;
  int j = right;
  int temp;
  int pivot = (values[left] + values[right] + values[(left+right)/2]) / 3;
  cout << "Pivot point: " << (left + right)/2 << " Pivot value: " << pivot << endl;

  while (i <= j) {
    while (values[i] < pivot) {
      i++;
    }
    cout << "i = " << i << " Value at " << i << "= " << values[i] << endl;

    while (values[j] > pivot) {
      j--;
      // cout << j << ' ' << values[j] << ' ';
    }
    cout << "j = " << j << " Value at " << j << "= " << values[j] << endl;

    if (i <= j) {
      temp = values[i];
      values[i] = values[j];
      values[j] = temp;
      i++;
      j--;
    }
    
    cout << "Sorted array: ";
    for (int k=0; k<values.size(); k++)
      cout << values[k] << ' ';
    cout << endl;

    if (left < j)
      sort_max_to_min(values, left, j);
    if (i < right)
      sort_max_to_min(values, i, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i=0; i<n; i++)
    cin >> v[i];

  sort_max_to_min(v,0,n-1);
  for (int i=0; i<v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;

  return 0;
}