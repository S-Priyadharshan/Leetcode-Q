class Solution {
    public String longestNiceSubstring(String s) {
        if(s.length()<2)return "";
        for(char c:s.toCharArray()){
            if(s.indexOf(Character.toLowerCase(c))==-1 ||
            s.indexOf(Character.toUpperCase(c))==-1){
                int i=s.indexOf(c);
                String left=longestNiceSubstring(s.substring(0,i));
                String right=longestNiceSubstring(s.substring(i+1));
                return left.length()>=right.length() ? left:right;
            }
        }
        return s;
    }
}