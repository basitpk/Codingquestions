/**

Problem Statement :

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Examples -

**/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> > &grid) {


        //here we can use 
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        //assign the meaning to the dp matrix 
        //intialise the base cases in the dp matrix
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=grid[i][j];
                if(i==m-1 && j==n-1){
                    continue;
                }else if(i==m-1){
                    dp[i][j]=dp[i][j+1]+grid[i][j];
                }else if(j==n-1){
                    dp[i][j]=dp[i+1][j]+grid[i][j];
                }else{
                    dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        //finally return the answer from the biggest subproblem 
        return dp[0][0];
        
    }
};


int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    int val = s.minPathSum(grid);
    printf("\n Solution = %d", val);
}