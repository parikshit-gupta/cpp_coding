#include<vector>
#include<iostream>
using namespace std;

class Solution {
private:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color,
             int orgnl_color) {
        int n = image.size();    // number of rows
        int m = image[0].size(); // number of columns
        if (sr < 0 || sr > n - 1 || sc < 0 || sc > m - 1||image[sr][sc]!=orgnl_color) {
            return;
        }
        
        image[sr][sc]=color;
        DFS(image, sr, sc - 1, color, orgnl_color);
        DFS(image, sr, sc + 1, color, orgnl_color);
        DFS(image, sr - 1, sc, color, orgnl_color);
        DFS(image, sr + 1, sc, color, orgnl_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();    // number of rows
        int m = image[0].size(); // number of columns
        int orgnl_color=image[sr][sc];
        DFS(image, sr, sc, color, orgnl_color);
        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=0;
    int sc=0;
    int color=2;
    image=s.floodFill(image,sr,sc,color);
    for(int i=0;i<image.size();i++)
    {
        for (int j=0;j<image[0].size();j++)
        {
            cout<<image[i][j]<<", ";
        }
    }
    return 0;
}