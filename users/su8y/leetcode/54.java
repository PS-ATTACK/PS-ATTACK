class Solution {
    public List<Integer> spiralOrder(int[][] map) {

        List<Integer> list = new ArrayList<>();
        int[][] move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // 복사 개체
        int x = 0;
        int y = 0;
        int i = 0;
        int count =0;

        list.add(map[0][0]);
        map[0][0] = -111;
        while (count < (map.length * map[0].length)-1) {
            int moveX = move[i][0];
            int moveY = move[i][1];
            if (x + moveX < 0 || x + moveX >= map.length || y + moveY < 0 || y + moveY >= map[0].length || map[x + moveX][y + moveY] == -111 ) {
                i++;
                if (i > 3) i = 0;
            } else {
                x += moveX;
                y += moveY;
                list.add(map[x][y]);
                map[x][y] = -111;
                count++;
            }

        } //while end
 

        return list;
    }
}