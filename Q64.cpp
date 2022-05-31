#include <iostream>
#include <vector>

using namespace std;

class timer{
public:
    clock_t start;
    clock_t end;
    string name;
    timer(string n){
        start=clock();
        name=n;
    }
    ~timer(){
        end=clock();
        printf("%s time: %f\n", name.c_str(),(end-start)*1.0/CLOCKS_PER_SEC*1000);
    }
    
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;

        int rows=grid.size(),columns=grid[0].size();
        auto dp=vector<vector<int>>(rows,vector<int>(columns));
        dp[0][0]=grid[0][0];

        for(int i=1;i<rows;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        for(int j=1;j<columns;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<columns;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][columns-1];
    }
};

int main(){
    cout<<"main"<<endl;

    vector<vector<int>> grid;

    vector<int> tmp1;

    for(int i=1;i<4;i++){
        tmp1.push_back(i);
    }

    grid.push_back(tmp1);

    vector<int> tmp2;

    for(int i=1;i<4;i++){
        tmp2.push_back(i);
    }

    grid.push_back(tmp2);

    
    Solution sl;
    cout<<sl.minPathSum(grid)<<endl;
   
    return 0;
}