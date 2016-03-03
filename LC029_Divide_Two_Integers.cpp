/*
29. Divide Two Integers

https://leetcode.com/problems/divide-two-integers/

solution is taken from:
https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
       //edge cases:
       if(divisor == 0 || (dividend == INT_MIN && divisor == -1)  ){
           return INT_MAX;
       }
       long long did = labs(dividend);
       long long dis = labs(divisor);
       int ret = 0;
       int sign = 1;
       if((dividend<0) ^(divisor<0)){
           sign = -1;
       }
       while(did>=dis){
           long long temp = dis;
           int multiple = 1;
           while(did>=(temp<<1)){
               temp <<=1;
               multiple <<=1;
           }
           did -=temp;
           ret +=multiple;
       }
       if(sign == -1){
           return -ret;
       }
       return ret;
    }
};