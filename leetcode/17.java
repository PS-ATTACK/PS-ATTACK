class Solution {
    private List<String> result = new ArrayList<>();
    private String[] digits;
    private static KeyPad keyPad = new KeyPad();

    static class KeyPad {
        private static String[][] letters = {{" "}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}, {"+"}, {"#"}};
        private List<Key> keyList;

        KeyPad() {
            keyList = new ArrayList<>();
            for (int i = 0; i < letters.length; i++) {
                Key key = new Key();
                for (String letter : letters[i]) {
                    key.addLetter(letter);
                }
                keyList.add(key);
            }
        }

        public List<String> puttingKey(String digit) {
            if (digit.equals("#")) return keyList.get(11).getLetterList();
            if (digit.equals("*")) return keyList.get(10).getLetterList();
            return keyList.get(Integer.parseInt(digit)).getLetterList();
        }


    }

    static class Key {
        private List<String> letterList = new ArrayList<>();

        public List<String> getLetterList() {
            return letterList;
        }

        public void addLetter(String letter) {
            letterList.add(letter);
        }
    }

    public List<String> letterCombinations(String digits) {
        this.digits = digits.split("");

        if (digits.length() == 0) return new ArrayList<>();
        Stack<String> str = new Stack<>();
        for (var letter : keyPad.puttingKey(this.digits[0])) {
            str.add(letter);
            solve(str);
            str.pop();
        }

        return result;
    }

    public void solve(Stack<String> input) {
        int index = input.size();
        if(index >= this.digits.length){
            Iterator<String> iterator = input.iterator();
            StringBuilder builder = new StringBuilder();
            while(iterator.hasNext()){
                builder.append(iterator.next());
            }
            System.out.println(builder.toString());
            result.add(builder.toString());
            return;
        }
        List<String> strings = keyPad.puttingKey(this.digits[index]);
        for (var letter : strings) {
            input.add(letter);
            solve(input);
            input.pop();
        }
    }

}


