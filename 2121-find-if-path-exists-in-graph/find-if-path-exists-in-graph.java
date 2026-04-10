class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        for(int[] e:edges){
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] vis=new boolean[n];
        boolean res=dfs(graph,vis,source,destination);
        return res;
    }
    public boolean dfs(List<List<Integer>> graph,boolean[] vis,int source,int dest){
        if(source==dest)return true;
        vis[source]=true;

        for(int nei:graph.get(source)){
            if(!vis[nei]){
                if(dfs(graph,vis,nei,dest))return true;
            }
        }
        return false;
    }
}