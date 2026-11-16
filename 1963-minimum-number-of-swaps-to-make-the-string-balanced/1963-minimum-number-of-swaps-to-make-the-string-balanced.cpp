class Solution {
public:
    int minSwaps(string s) {
        int c = 0;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                c++;
            }
            else{
                c--;
            }
            res = max(res,-c);
        }
        return (res+1)/2;
    }

};