#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//to store the number in same flow of digits then we can use the following formula
//num = (num * 10) + digit; where starting value of num is 0

    int reverse(int x) {
        int num = 0,digit;
        while(x != 0){
            digit = x%10;
            if(num > INT_MAX/10 || num < INT_MIN/10) return 0;
            num = (num * 10) + digit;
            x = x/10;
        }
        return num;
    }

//to store the number in reverse flow of digits then we can use the following formula
//num = (digit * 10^i) + num; where starting value of num is 0 and i is 0;

    int decimaltobinary(int x){
        int num = 0,i=0;
        while(x != 0){
            int lastbit = x&1;
            num = (lastbit * pow(10,i)) + num;
            x = x>>1;
            i++;
        }
        return num;
    }

//to make bitwiseComplement of a number we create a mask of all 1s corresponding to the number of bits in the number
//then & the mask with the negation of the number.
//to create the mask we left shift the mask by 1 and then OR with 1.
//for example:- for 101 the mask will be 0000...111 and then it will mask with negation of 11111...010
//which will give us the complement of 101.

    int bitwiseComplement(int n) {
        if(n ==  0){
            return 1;
        }else if(n == 1){
            return 0;
        }
        int m = n;
        int mask = 0;
        while(m != 0){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int res  = (~n) & mask;
        return res;
    }

//to find the number is a power of 2 or not we can use the approach
//the logic is if the number is power of 2 it will give remainder of 0 after dividing by 2 till the number is 1
//if the number is reaches 1 by dividing by 2 then it is a power of 2.

    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }
};


int main(){
    Solution s;
    cout << s.decimaltobinary(100) << endl;
    return 0;
}
