class Solution {
public:
    int maxProduct(int n) {
        int digit;
        int first = 0;
        int sec =0;
        while(n>0){
            digit = n % 10;
            if(digit > first){
                sec = first;
                first = digit;
            }
            else if(digit > sec){
                sec = digit ;
            }
            n = n/10;
        }
        return first * sec;
    }
};