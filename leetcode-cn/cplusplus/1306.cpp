#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		if (arr.empty()) {
			return false;
		}
		vector<int> visited(arr.size(), 0);
		queue<int> q; q.push(start);

		while (!q.empty()) {
			int pos = q.front(); q.pop();
			visited[pos] = 1;

			if (arr[pos] == 0) {
				return true;
			}
			else {
				for (int num = -1; num <= 1; num += 2) { // 符号
					int next_pos = pos + num * arr[pos];
					if (next_pos >= 0 && next_pos < arr.size()) {
						if (0 == visited[next_pos]) {
							q.push(next_pos);
						}
					}
				}
			}
		}

		return false;
	}
};
