class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r=image.size(),c=image[0].size(),i,j,scol=image[sr][sc];
        if (scol==newColor)
            return image;
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        image[sr][sc]=newColor;
        while (!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            if (j<c-1 && image[i][j+1]==scol)
            {
                q.push(make_pair(i,j+1));
                image[i][j+1]=newColor;
            }
            if (i>0 && image[i-1][j]==scol)
            {
                q.push(make_pair(i-1,j));
                image[i-1][j]=newColor;
            }
            if (j>0 && image[i][j-1]==scol)
            {
                q.push(make_pair(i,j-1));
                image[i][j-1]=newColor;
            }
            if (i<r-1 && image[i+1][j]==scol)
            {
                q.push(make_pair(i+1,j));
                image[i+1][j]=newColor;
            }
        }
        return image;
    }
};
