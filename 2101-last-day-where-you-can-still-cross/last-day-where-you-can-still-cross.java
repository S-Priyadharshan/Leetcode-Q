class Solution {
    static int rows;
    static int cols;
    static int[] d={0,1,0,-1,0};

    public int latestDayToCross(int row, int col, int[][] cells) {
        int low=1,high=cells.length,ans=0;
        rows=row;
        cols=col;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(pos(mid,cells)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }

    public static boolean pos(int mid,int[][] cells){
        int[][] graph=new int[rows][cols];
        for(int i=0;i<mid;i++){
            graph[cells[i][0]-1][cells[i][1]-1]=1;
        }
        Queue<int[]>q=new LinkedList<>();
        boolean[][] vis=new boolean[rows][cols];
        for(int i=0;i<cols;i++){
            if(graph[0][i]==0){
                q.offer(new int[]{0,i});
                vis[0][i]=true;
            }
        }
        while(!q.isEmpty()){
            int[] curr=q.poll();
            int r=curr[0];
            int c=curr[1];
            if(r==rows-1)return true;
            for(int i=0;i<4;i++){
                int nr=r+d[i];
                int nc=c+d[i+1];
                if(nr<0 || nc<0 || nr>=rows || nc>=cols || graph[nr][nc]==1 || vis[nr][nc])continue;
                vis[nr][nc]=true;
                q.offer(new int[]{nr,nc});
            }
        }
        return false;
    }
}