// semenInRussia 2024
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, string> book;
  for (int i = 0; i < n; i++) {
    string name;
    int h;
    cin >> name >> h;
    book[h] = name;
  }
  while (!book.empty()) {
    // big
    auto it = --book.end();
    cout << it->second;
    book.erase(it);
    if (!book.empty()) {
      cout << ' ';
    }

    // small
    if (!book.empty()) {
      cout << book.begin()->second;
      book.erase(book.begin());
      if (!book.empty()) {
        cout << ' ';
      }
    }
  }
}
