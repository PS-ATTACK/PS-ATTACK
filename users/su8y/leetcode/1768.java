class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder builder = new StringBuilder();
        int i = 0;
        while(i < word1.length() && i < word2.length()){
            builder.append(word1.charAt(i));
            builder.append(word2.charAt(i));
            i++;
        }
        if(i < word1.length()){
            builder.append(word1.substring(i,word1.length()));
        }
        if(i < word2.length()){
            builder.append(word2.substring(i,word2.length()));
        }
        return builder.toString();
    }
}