class Solution {
    public int distinctEchoSubstrings(String text) {
        HashSet<String> set=new HashSet<>();
        int n=text.length();
        for(int i=0;i<n;i++){
            for(int len=2;i+len<=n;len+=2){
                int mid=i+(len/2);
                String a=text.substring(i,mid);
                String b=text.substring(mid,i+len);
                if(a.equals(b))set.add(a);
            }
        }
        return set.size();
    }
}