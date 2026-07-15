class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>list;
        long  val = 1;
        for(int star = 0;star<=rowIndex ; star++){
            list.push_back((int)val);
            val = val *(rowIndex - star)/(star+1);
        }
        return list;
    }
};