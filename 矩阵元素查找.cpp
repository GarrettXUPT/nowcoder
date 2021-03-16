#include<iostream>
#include<vector>

using namespace std;

/*
    œﬂ–‘≤È’“
*/

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    // write code here
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    int rows = matrix.size(), columns = matrix[0].size();
    int row = 0, column = columns - 1;
    while (row < rows && column >= 0) {
        int num = matrix[row][column];
        if (num == target) {
            return true;
        }
        else if (num >= target)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

