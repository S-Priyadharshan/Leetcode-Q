class Solution {
public:
    static constexpr int dirs[] = {0,1,0,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if (org == color) return image; // Early exit prevents infinite loops without extra vis array

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = color; // Recolor directly

        while (!q.empty()) {
            auto [x, y] = q.front(); // Copy by value before popping
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = x + dirs[i];
                int nc = y + dirs[i + 1];

                // Check bounds FIRST, then check value
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == org) {
                    image[nr][nc] = color;
                    q.emplace(nr, nc);
                }
            }
        }
        return image;
    }
};