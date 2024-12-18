class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        //take transpose
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse each row
        for(int i=0; i<n; i++) {
            int start=0;
            int end= matrix[i].size()-1;
            while(start<end){
            
            swap(matrix[i][start],matrix[i][end]);;
            start++;
            end--;
        }
        }
    }
};