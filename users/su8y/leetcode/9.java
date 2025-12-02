class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        String number = String.valueOf(x);
        int left = 0, right = number.length() - 1;
        System.out.println(number.length() == 3);
        while(left < right){
            if (number.charAt(left) != number.charAt(right)) {
                return false;
            }
            right--;
            left++;
        }
        return true;

    }
}