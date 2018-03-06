class Solution {
private:
    struct cell{
        int16_t v;
        int16_t possible;
        bitset<10> constraint;
        cell(): v(0), possible(9), constraint() {};
    };
    array<array<cell, 9>, 9> grid;
    
    // Add constraint num to grid[i][j]
    bool updateCell(int i, int j, int16_t num){
        cell& c = grid[i][j];
        if (num == c.v)
            return false;
        if (c.constraint[num])
            return true;
        c.constraint.set(num);
        --c.possible;
        if (c.possible > 1)
            return true;
        for (int16_t k = 1; k < 10; ++k)
        {
            if (!c.constraint[k]){
                return initCell(i, j, k);
            }
        }
    }
    
    // Initialize grid[i][j] to num;
    bool initCell(int i, int j, int16_t num){
        cell& c = grid[i][j];
        int ix, jx, k;
        if (num == c.v)
            return true;
        if (c.constraint[num])
            return false;
        c.constraint = bitset<10>(0x3FE);
        c.constraint.reset(num);
        c.v = num;
        c.possible = 1;
        
        for (k = 0; k < 9; ++k){
            if (k != i && !updateCell(k, j, num))
                return false;
            if (k != j && !updateCell(i, k, num))
                return false;
            ix = i / 3 * 3 + k / 3;
            jx = j / 3 * 3 + k % 3;
            if (ix != i && jx != j && !updateCell(ix, jx, num))
                return false;
        }
        return true;
    }

    bool initGrid(vector<vector<char>>& board){
        int i, j, num;
        for (i = 0; i < 9; ++i){
            for (j = 0; j < 9; ++j){
                if ('.' != board[i][j]){
                    num = board[i][j] - '0';
                    if (!initCell(i, j, num))
                        return false;;
                }
            }
        }
        return true;
    }
    
    vector<pair<int, int>> req;
    
    bool backtract(int ind){
        if (ind == req.size())
            return true;
        int i = req[ind].first;
        int j = req[ind].second;
        cell& c = grid[i][j];
        if (c.v)
            return backtract(ind + 1);
        array<array<cell, 9>, 9> temp(grid);
        
        for(uint64_t k = 1; k < 10; ++k){
            if (!c.constraint[k]){
                if (initCell(i, j, k)){
                    if (backtract(ind + 1))
                        return true;
                }
                grid = temp;
            }
        }
        return false;
    }
    
    bool findRequire(){
        req.clear();
        int i, j;
        for (i = 0; i < 9; ++i){
            for (j = 0; j < 9; ++j){
                if (!grid[i][j].v){
                    req.push_back(make_pair(i, j));
                }
            }
        }
        sort(req.begin(), req.end(), [this](const pair<int, int>& p1, const pair<int, int>& p2){
            return grid[p1.first][p1.second].possible < grid[p2.first][p2.second].possible;
        });
        return backtract(0);
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (!initGrid(board))
            return;
        if (!findRequire())
            return;
        int i, j;
        for (i = 0; i < 9; ++i){
            for (j = 0; j < 9; ++j){
                if (grid[i][j].v){
                    board[i][j] = '0' + grid[i][j].v;
                }
            }
        }
    }
};
