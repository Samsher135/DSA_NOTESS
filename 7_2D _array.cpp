// A 2D array is a multi-dimensional array of arrays that stores data in rows and columns.
// behind the scene, a 2D array is stored in linearly in memory where mapping is done using formula: number of columns * row_index + column_index.

// to store and print a 2D array row wise and vice versa for column wise
// for (int row = 0; row < 2; row++){
//     for (int col = 0; col < 3; col++){
//         cout << arr[row][col] << " ";
//     }
//     cout << endl;
// }

// Binary Search in a 2D array row wise sorted array

#include <bits/stdc++.h>
using namespace std;

bool binary2d()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int key = 5;
    int row_size = v.size();
    int col_size = v[0].size();

    int s = 0, e = row_size * col_size - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        // vector<vector<int>> v = {1,2,3,4,5,6,7,8,9};
        // dividing the array index with the column size to get the row index.
        int row = mid / col_size;
        // modulus of the index with the column size to get the column index because it gives how far the element is from the left column size.
        int col = mid % col_size;
        if (v[row][col] == key)
        {
            cout << "Found at " << row << " " << col << endl;
            return true;
        }
        else if (v[row][col] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return;
}

// spiral printing of a 2D array

void spiralprint()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row_size = v.size();
    int col_size = v[0].size();

    int firstrow = 0;
    int lastrow = row_size - 1;
    int firstcol = 0;
    int lastcol = col_size - 1;

    int total = row_size * col_size;
    int count = 0;

    while (count < total)
    {
        for (int i = firstcol; i <= lastcol; i++)
        {
            cout << v[firstrow][i] << " ";
            count++;
        }
        firstrow++;
        for (int i = firstrow; i <= lastrow; i++)
        {
            cout << v[i][lastcol] << " ";
            count++;
        }
        lastcol--;
        for (int i = lastcol; i >= firstcol; i--)
        {
            cout << v[lastrow][i] << " ";
            count++;
        }
        lastrow--;
        for (int i = lastrow; i >= firstrow; i--)
        {
            cout << v[i][firstcol] << " ";
            count++;
        }
        firstcol++;
    }
}

//binary search in a both row and column wise sorted 2D array
//start from the top right corner
//if the element is found then return true
//else if the element is greater than the target element then move to the left column
//else if the element is less than the target element then move to the bottom row

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowindex = 0;
        int colindex = col-1;
        
        while(rowindex < row && colindex >=0){
            if(matrix[rowindex][colindex] == target){
                return 1;
            }
            else if(matrix[rowindex][colindex] > target){
                colindex--;
            }
            else{
                rowindex++;
            }
        }
        return 0;
}