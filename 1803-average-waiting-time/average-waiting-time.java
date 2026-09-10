class Solution {
    public double averageWaitingTime(int[][] customers) {
        int curr=0;
        double sum=0;
        for(int[] t:customers){
            curr=Math.max(curr,t[0]);
            curr+=t[1];
            sum+=(double)(curr-t[0]);
        }
        return sum/(double)customers.length;
    }
}