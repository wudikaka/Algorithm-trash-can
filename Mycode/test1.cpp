#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size(); // 行数
        if (rowSize > 0)
        {
            int colSize = matrix[0].size(); // 列数
            sums.resize(rowSize, vector<int>(colSize + 1));
            for (int i = 0; i < rowSize; i++)
            {
                for (int j = 0; j < colSize; j++) // 给每行都搞个前缀和数组
                {
                    sums[i][j + 1] = sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
        {
            sum += (sums[i][col2 + 1] - sums[i][col1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */