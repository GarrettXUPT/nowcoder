#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
	vector<int> retVec;
	if (matrix.empty()) return retVec;
	
	int top = 0, bottom = matrix.size() - 1;
	int left = 0, right = matrix[0].size() - 1;
	while (top < (matrix.size() + 1) / 2 && left < (matrix[0].size() + 1) / 2) {
		// ���� ������
		for (int i = left; i <= right; ++i) {
			retVec.push_back(matrix[top][i]);
		}
		// �ұ� ���ϵ���
		for (int i = top + 1; i <= bottom; ++i) {
			retVec.push_back(matrix[i][right]);
		}
		// ���� ���ҵ���
		for (int i = right - 1; i >= left && top != bottom; --i) {
			retVec.push_back(matrix[bottom][i]);
		}
		// ��� ���µ���
		for (int i = bottom - 1; i >= top + 1 && right != left; --i){
			retVec.push_back(matrix[i][left]);
		}
		++top; --bottom; ++left; --right;
	}
	return retVec;
}