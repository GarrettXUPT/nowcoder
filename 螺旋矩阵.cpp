#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
	vector<int> retVec;
	if (matrix.empty()) return retVec;
	
	int top = 0, bottom = matrix.size() - 1;
	int left = 0, right = matrix[0].size() - 1;
	while (top < (matrix.size() + 1) / 2 && left < (matrix[0].size() + 1) / 2) {
		// 上面 从左到右
		for (int i = left; i <= right; ++i) {
			retVec.push_back(matrix[top][i]);
		}
		// 右边 从上到下
		for (int i = top + 1; i <= bottom; ++i) {
			retVec.push_back(matrix[i][right]);
		}
		// 下面 从右到左
		for (int i = right - 1; i >= left && top != bottom; --i) {
			retVec.push_back(matrix[bottom][i]);
		}
		// 左边 从下到上
		for (int i = bottom - 1; i >= top + 1 && right != left; --i){
			retVec.push_back(matrix[i][left]);
		}
		++top; --bottom; ++left; --right;
	}
	return retVec;
}