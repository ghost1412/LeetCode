class NumMatrix {
vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        data.resize(matrix.size(), vector<int> (matrix[0].size()));
        for(int i=0; i<matrix.size(); i++){
            int sum = 0;
            for(int j=0; j<matrix[0].size(); j++){
                sum += matrix[i][j];
                data[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1; i<=row2; i++){
            sum += data[i][col2] - (col1 == 0 ? 0 : data[i][col1 - 1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */