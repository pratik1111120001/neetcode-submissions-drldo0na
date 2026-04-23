class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9,0);
        bool ok = true;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) row[j]=0;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                row[board[i][j] - '1']++;
            }
            for(int j=0;j<9;j++) ok&=(row[j]<=1);
            if(!ok) return ok; 
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) row[j]=0;
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                row[board[j][i] - '1']++;
            } 
            for(int j=0;j<9;j++) ok&=(row[j]<=1);
            if(!ok) return ok; 
        }
        for(int i1=0;i1<9;i1+=3){
            for(int j1=0;j1<9;j1+=3){
                for(int i=0;i<9;i++) row[i]=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[i1+i][j1+j] == '.') continue;
                        row[board[i1+i][j1+j]-'1']++;
                    }
                }
                for(int i=0;i<9;i++) ok&=(row[i]<=1);
                if(!ok) return ok;
            }
        }
        return ok;
    }
};
