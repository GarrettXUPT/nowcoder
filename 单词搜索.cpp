#include<iostream>
#include<vector>

using namespace std;


/*
	深度搜索
	checkBoard是为了检验从网格的(i, j)出发，是否可以找到word[k, ...]
	该种方法是从每一个(i, j)出发，只要有一处可以找到，则直接返回true
	为了防止重复遍历一个位置，需要额外的维护一个visited数组，用来记录该位置是否已经被访问过了，每次在遍历相邻位置
	就会检测相邻位置是否会被重复遍历
*/

// 需要注意的是这里传入的应该是引用，这里对外面的数组会有严格的改变
bool checkBoard(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& word, int k) {
	if (board[i][j] != word[k]) {
		return false;
	}
	else if (k == word.length() -1) {
		return true;
	}
	visited[i][j] = true;
	vector<pair<int, int>> dirctions{ {0, 1}, {0, -1}, {1, 0},{-1, -0} };
	bool result = false;
	for (const auto& dir : dirctions) {
		int newi = i + dir.first, newj = j + dir.second;
		if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
			if (!visited[newi][newj]) {
				bool flag = checkBoard(board, visited, newi, newj, word, k + 1);
				if (flag) {
					result = true;
					break;
				}
			}			
		}
	}
	/*
		每次尝试以后 都要对位置进行重置，防止对下一个位置造成影响
	*/
	visited[i][j] = false;
	return result;
}

bool exist(vector<vector<char>>& board, string word) {
	int rows = board.size(), colunms = board[0].size();
	vector<vector<int>> visited(rows, vector<int>(colunms, 0));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colunms; ++j) {
			bool flag = checkBoard(board, visited, i, j, word, 0);
			if (flag) {
				return true;
			}
		}
	}
	return false;

}