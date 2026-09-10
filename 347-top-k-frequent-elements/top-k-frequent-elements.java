class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp=new HashMap<>();

        for(int i:nums){
            mp.merge(i,1,Integer::sum);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->mp.get(a)-mp.get(b));

        for(int key:mp.keySet()){
            pq.offer(key);
            if(pq.size()>k)pq.poll();
        }

        int[] ans=new int[k];
        for(int i=0;i<k;i++){
            ans[i]=pq.poll();
        }
        return ans;
    }
}