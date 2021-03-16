#include<iostream>
#include<vector>

using namespace std;


/*
	�������
	checkBoard��Ϊ�˼���������(i, j)�������Ƿ�����ҵ�word[k, ...]
	���ַ����Ǵ�ÿһ��(i, j)������ֻҪ��һ�������ҵ�����ֱ�ӷ���true
	Ϊ�˷�ֹ�ظ�����һ��λ�ã���Ҫ�����ά��һ��visited���飬������¼��λ���Ƿ��Ѿ������ʹ��ˣ�ÿ���ڱ�������λ��
	�ͻ�������λ���Ƿ�ᱻ�ظ�����
*/

// ��Ҫע��������ﴫ���Ӧ�������ã�������������������ϸ�ĸı�
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
		ÿ�γ����Ժ� ��Ҫ��λ�ý������ã���ֹ����һ��λ�����Ӱ��
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