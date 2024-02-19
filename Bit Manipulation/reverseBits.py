'''

Reverse bits of a given 32 bits unsigned integer.

Note:

1. Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input 
and output will be given as a signed integer type. They should not affect your implementation, as the integer's 
internal binary representation is the same, whether it is signed or unsigned.

2. In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, 
the input represents the signed integer -3 and the output represents the signed integer -1073741825.



------------------- Example ----------------------------

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 
which its binary representation is 00111001011110000010100101000000.
'''







class Solution:
    def reverseBits(self, n: int) -> int:
        end =31
        res = 0
        for i in range(0,32):
            res +=(n>>i&0x01)<<(31-i)
            
        return res