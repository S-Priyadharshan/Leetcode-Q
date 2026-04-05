class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;

        int[][] rowPre = new int[m][n];
        for (int i = 0; i < m; i++) {
            rowPre[i][0] = mat[i][0];
            for (int j = 1; j < n; j++) {
                rowPre[i][j] = rowPre[i][j - 1] + mat[i][j];
            }
        }

        int[][] ans = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = Math.max(0, i - k);
                int r2 = Math.min(m - 1, i + k);
                int c1 = Math.max(0, j - k);
                int c2 = Math.min(n - 1, j + k);
                int sum = 0;
                for (int r = r1; r <= r2; r++) {
                    if (c1 > 0)
                        sum += rowPre[r][c2] - rowPre[r][c1 - 1];
                    else
                        sum += rowPre[r][c2];
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
}