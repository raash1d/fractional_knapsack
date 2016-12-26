#include <iostream>
#include <vector>
// #include <tuple>

using std::vector;
// using std::tuple;
using std::cout;
using std::cin;
using std::endl;

void insertion_sort(vector<int> &v) { // using quicksort
  for (int i=1; i<v.size(); i++) {
    // int x = v[i];
    int j = i;
    while (j>0 && v[j-1]<v[j] ) {
      int temp = v[j];
      v[j] = v[j-1];
      v[j-1] = temp;
      j--;
    }
    // v[j+1] = x;
    cout << "Sorted array: ";
    for (int k=0; k<v.size(); k++)
      cout << v[k] << ' ';
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i=0; i<n; i++)
    cin >> v[i];

  insertion_sort(v);
  for (int i=0; i<v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;

  return 0;
}