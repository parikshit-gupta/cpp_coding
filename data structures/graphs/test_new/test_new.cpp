#include<vector>
using namespace std;

class Solution{
private:
    void DFS1(int row, int col,vector<vector<char>>& mat, vector<vector<char>>& copy, vector<vector<bool>>& visited, int& n, int& m, int* arr1, int* arr2)
    {
        for (int x = 0; x < 4; x++) {
            int nrow = row + arr1[x];
            int ncol = col + arr2[x];
            //checking index out of range
            if(nrow<0 || ncol <0 || nrow>n-1 || ncol>m-1)
            {
                continue;
            }
            if(visited[nrow][ncol]==0 && mat[nrow][ncol]=='O')
            {
                visited[nrow][ncol]=1;
                copy[nrow][ncol]='X';
                //the given fucnton must retrun true if the given group of O's is replaceable from all four directions
                DFS1(nrow, ncol, mat, copy, visited, n,m, arr1, arr2);
            }
        }
        
    }
    bool DFS(int row, int col,vector<vector<char>>& mat, vector<vector<bool>>& visited, int& n, int& m, int* arr1, int* arr2)
    {
        /*
            if there is a edge element in the block then that block is not replaceable,
            but we still want to traverse that block and mark it visited, so that no
            future calls are made to that pirticular block.
        */
        
        bool to_replace=0;
        if(row==0 || col==0 || row==n-1 || col==m-1)
        {
            to_replace=0;
        }
        int c=0;
        
        for (int x = 0; x < 4; x++) {
            int nrow = row + arr1[x];
            int ncol = col + arr2[x];
            //checking index out of range
            if(nrow<0 || ncol <0 || nrow>n-1 || ncol>m-1)
            {
                continue;
            }
            if(visited[nrow][ncol]==0 && mat[nrow][ncol]=='O')
            {
                visited[nrow][ncol]=1;
                //the given fucnton must retrun true if the given group of O's is replaceable from all four directions
                to_replace=DFS(nrow, ncol, mat, visited, n,m, arr1, arr2)&& to_replace;
                c=1;
            }
        }
        if(c==0)
        {
            to_replace=1;
        }
        
        return to_replace;
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n, vector<bool>(m,0));
        vector<vector<char>> copy=mat;
        
        int*arr1 = new int[4];
        arr1[0]=0;arr1[1]=-1;arr1[2]=0;arr1[3]=1;
        
        int*arr2 = new int[4];
        arr2[0]=-1;arr2[1]=0;arr2[2]=1;arr2[3]=0;
        
        bool to_replace=0;
        
        
        for (int i=0; i< n;i++)
        {
            for (int j=0; j<m;j++)
            {
                if(visited[i][j]==0 && mat[i][j]=='O')
                {
                    visited[i][j]=1;
                    vector<vector<bool>> visited1=visited;
                    to_replace=DFS(i, j, mat, visited, n, m, arr1, arr2);
                    if(to_replace)
                    {
                        copy[i][j]='X';
                        DFS1(i,j,mat,copy, visited1, n, m, arr1, arr2);
                    }
                }
                visited[i][j]=1;
            }
        }
        return copy;
        
    }
};