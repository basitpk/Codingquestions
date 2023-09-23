'''
Problem Statement :

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


-------------------- Example -----------------
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


'''


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        output=[[1]]
        # index = 1
        for index in range(1, numRows):
            output.append([])
            output[index].insert(0,1)
            output[index].append(1)
            for i in range(1,index):
                val=output[index - 1][i - 1] + output[index - 1][i]
                output[index].insert(i,val)
            # index +=1
        return output
        