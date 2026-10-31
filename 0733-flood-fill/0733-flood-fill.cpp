class Solution {
public:
    void dfs(vector<vector<int>>&image,int i,int j,int newColor,int originalColor){
        int n = image.size();
        int m = image[0].size();
        if(i < 0 || j < 0|| i >= n ||j >= m || image[i][j] != originalColor || image[i][j] == newColor){
            return;
        }
        image[i][j] = newColor;
        dfs(image,i+1,j,newColor,originalColor);
        dfs(image,i-1,j,newColor,originalColor);
        dfs(image,i,j+1,newColor,originalColor);
        dfs(image,i,j-1,newColor,originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};