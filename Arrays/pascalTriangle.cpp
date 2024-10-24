class Solution {
    vector<int>generateRow(int row) {
        vector<int>ansRow;
        long long ans=1;
        ansRow.push_back(1);
        for(int c=1; c<row; c++) {
            ans=ans*(row-c)/c;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int r=1; r<=numRows; r++) {
            vector<int>ansRow= generateRow(r);
            res.push_back(ansRow);
        }
        return res;
    }
};