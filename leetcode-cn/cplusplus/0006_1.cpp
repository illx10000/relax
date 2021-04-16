#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Node {
	int pos_x;
	int pos_y;
	char data;
	Node(){};
	Node(int x, int y, char d) : pos_x(x), pos_y(y), data(d) {};

	static bool sort(const Node& a, const Node& b) {
		return ( (a.pos_x < b.pos_x) || (a.pos_x == b.pos_x && a.pos_y < b.pos_y));
	}
};

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.empty() || numRows <= 1) {
			return s;
		}

		vector<Node> data;
		buildNodeData(s, numRows, data);
		//for (size_t i = 0; i < data.size(); i++) {
		//	cout << "[" << data[i].pos_x << "," << data[i].pos_y << "]" << data[i].data << endl;
		//}

		sort(data.begin(), data.end(), Node::sort);

		string strResult = "";
		for (int i = 0; i < data.size(); i++) {
			strResult += (data[i].data);
		}
		return strResult;
	}


	//通过string 构造出node_data
	void buildNodeData(const std::string& str, int numRows,
		vector<Node>& node_data)
	{
		node_data.clear();

		int cur_x = 0, cur_y = 0, from_top_to_down = 1;
		// from 
		for (size_t i = 0; i < str.size(); i++) {
			node_data.push_back(Node(cur_x, cur_y, str[i]));
			
			if (from_top_to_down) //自上而下
			{
				cur_x ++;
				if (cur_x == numRows) {
					cur_x = numRows - 2;
					cur_y++;
					from_top_to_down = 0;
				}
			}
			else //自下而上
			{
				cur_x--;
				cur_y++;

				if (cur_x == -1) { 
					cur_x = cur_x + 2;
					cur_y --;
					from_top_to_down = 1;
				}
			}
		}
	}
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 4) << endl;
}