#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int getMaxScore(int n) {
  priority_queue<int> pq;
  pq.push(n);
  int score = 0;

  while (!pq.empty()) {
    int largest = pq.top();
    pq.pop();

    if (largest == 1) {
      continue;
    }

    int a = largest / 2;
    int b = largest - a;

    score += a * b;

    pq.push(a);
    pq.push(b);
  }

  return score;
}

int main() {
  int T;
  cin >> T;

  vector<int> results;
  for (int i = 0; i < T; ++i) {
    int n;
    cin >> n;
    results.push_back(getMaxScore(n));
  }

  for (int result : results) {
    cout << result << endl;
  }

  return 0;
}
