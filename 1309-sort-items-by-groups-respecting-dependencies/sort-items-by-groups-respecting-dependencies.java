class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }
        List<List<Integer>> itemGraph = new ArrayList<>();
        List<List<Integer>> groupGraph = new ArrayList<>();

        for(int i=0;i<n;i++)itemGraph.add(new ArrayList<>());
        for(int i=0;i<m;i++)groupGraph.add(new ArrayList<>());

        int[] itemIndegree = new int[n];
        int[] groupIndegree = new int[m];

        for(int i=0;i<n;i++){
            for(int prev:beforeItems.get(i)){
                itemGraph.get(prev).add(i);
                itemIndegree[i]++;

                if(group[prev]!=group[i]){
                    groupGraph.get(group[prev]).add(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        List<Integer> itemOrder = toposort(itemGraph,itemIndegree,n);
        List<Integer> groupOrder = toposort(groupGraph,groupIndegree,m);

        List<List<Integer>> grouped=new ArrayList<>();

        for(int i=0;i<m;i++){
            grouped.add(new ArrayList<>());
        }
        for(int item:itemOrder){
            grouped.get(group[item]).add(item);
        }
        List<Integer> res=new ArrayList<>();
        for(int g:groupOrder){
            res.addAll(grouped.get(g));
        }

        return res.stream().mapToInt(i->i).toArray();
    }

    public static List<Integer> toposort(List<List<Integer>> graph,int[] indegree,int n){
        Queue<Integer> q=new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.offer(i);
        }
        List<Integer> order=new ArrayList<>();
        while(!q.isEmpty()){
            int node=q.poll();
            order.add(node);
            for(int nei:graph.get(node)){
                if(--indegree[nei]==0){
                    q.offer(nei);
                }
            }
        }
        return order.size()==n ? order:new ArrayList<>();
    }
}