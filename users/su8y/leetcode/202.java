class Solution {
    /**
    test case : 2
                4
                16
                1 + 36 = 37
                9 + 49 = 58
                25 + 64 = 89
                64 + 81 = 145
                1 + 16 + 25 = 42
                16 + 4 = 20
                4  = 4
                순환 되었다.
     */
    public int getNext(int number){
        int sum = 0;
        while(number > 0){
            int oneNumber = number % 10;
            number /= 10;
            sum += oneNumber * oneNumber;
        }
        return sum;
    }
    public boolean isHappy(int n) {
        Set<Integer> hashMap = new HashSet<>();
        
        while(n != 1 && !hashMap.contains(n)){
            hashMap.add(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
}