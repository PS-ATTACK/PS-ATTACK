import java.util.Collections.*;
class Solution {
    public String reverseWords(String s) {
        String answers = s.trim();
        String[] splitArr = answers.split("\\s+");

        List<String> splitStrList = new ArrayList();
        for(var str : splitArr){
            System.out.println(str);
            splitStrList.add(str.trim());
        }

        // List<String> splitStrList = Arrays.asList(splitArr);
        Collections.reverse(splitStrList);
        return splitStrList.stream()
        .collect(Collectors.joining(" "));
    }
}