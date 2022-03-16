/*
Q733. Description: An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

DFS Approach - Recursion
*/

class Solution {
    public void RecursiveFill(int[][]image, int sr, int sc, int prevColor, int newColor)
    {
        if(image[sr][sc] == prevColor)
        {
            image[sr][sc] = newColor;
            // Fill color in North
            if(sr >= 1)
                RecursiveFill(image, sr-1, sc, prevColor, newColor);
            // Fill color in East
            if(sc>=1)
                RecursiveFill(image, sr, sc-1, prevColor, newColor);
            // Fill color in South
            if(sr+1 < image.length)
                RecursiveFill(image, sr+1, sc, prevColor, newColor);
            // Fill color in West
            if(sc+1 < image[0].length)
                RecursiveFill(image, sr, sc+1, prevColor, newColor);
        }
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        // Start filling only if new color is different
        if(prevColor != newColor)
            RecursiveFill(image, sr, sc, prevColor, newColor);
        return image;
    }
}