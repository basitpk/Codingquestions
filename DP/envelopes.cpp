/** You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

**/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

 bool cmp(vector<int> &a, vector<int> &b)
    {
        // If the widths are equal, sort in descending order of heights
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }

        // Sort in ascending order of widths
        return a[0] < b[0];
    }

int solveBS(int n,vector<vector<int>>& nums)
    {
            std :: sort(nums.begin(),nums.end(),cmp);

            vector<int> ans;
            ans.push_back(nums[0][1]);

            for(int i=1;i<n;i++)
            {
                if(nums[i][1]>ans.back()) ans.push_back(nums[i][1]);
                else
                {
                    //find index of just bada element in ans
                    int index=lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin();
                    ans[index]=nums[i][1];
                }
            }
            return ans.size();
    }       

    int main() {
        vector<vector<int>> envelopes {{5,4},{6,4},{6,7},{2,3}};
        int n=envelopes.size();
        
        cout << solveBS(n,envelopes)<< endl;

        for (auto k : envelopes)
        {
            for(auto l : k)
              cout << l ;
            cout << endl;
        }     
    }
