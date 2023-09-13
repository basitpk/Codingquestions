'''
Problem Statement:
 
 Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++\'s atoi function).
 
 -----Conditions-----
1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in 
   if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change 
   the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
6. Return the integer as the final result. 

---- Examples-----

Input: s = "-42"
Output: -42
Explanation

'''




int myAtoi(char * s){

   int sign =1, i= 0, num =0;
   while(s[i] == ' ') i++;
   if(s[i] == '-') sign = -1,i++;
   else if(s[i] == '+') sign = 1,i++;
   while (s[i] >='0' && s[i]<='9')
   {
       if(num > INT_MAX / 10 || (num == INT_MAX/10 && s[i] - '0' > 7))
           return sign == 1 ? INT_MAX : INT_MIN;
       num = num * 10 + (s[i] - '0');
       // printf("NUM = %d\n",num);
       i++;
   }
    return num*sign;
    
}