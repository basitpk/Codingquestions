/**
Problem Statement :

You are given a 2D boolean matrix grid.
Return an integer that is the number of right triangles that can be made with the 3 elements of grid such that all of them have a value of 1.

Note:

A collection of 3 elements of grid is a right triangle if one of its elements is in the same row with another element and in the same column with the third element. The 3 elements do not have to be next to each other.




Example:
Input: grid = [[0,1,0],[0,1,1],[0,1,0]]

Output: 2

Explanation:
There are two right triangles.

**/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<int> row(n,0), col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                    
                }
            }
        }
        long long cnt=0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                   
                   cnt+=(row[i]-1) * (col[j]-1);
                    
                    
                    
                }
            }
        }
        return cnt;
        
    }
};
int main()
{
    vector<vector<int>> grid {
                              {1, 0, 1},
                              {1, 1, 0},
                              {1, 0, 0}
                               };
    Solution s ;
    std::cout << "Number of right triangles : "<< s.numberOfRightTriangles(grid);                           
    return 0;
}