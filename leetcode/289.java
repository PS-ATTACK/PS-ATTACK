package leetcode.com;

public class LeetCode_289_Game_of_Life {
	private int[] dy = {0, 0, -1, 1, 1, 1, -1, -1};
	private int[] dx = {1, -1, 0, 0, -1, 1, 1, -1};

	public void gameOfLife(int[][] board) {
		int[][] newBoard = new int[board.length][board[0].length];

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == 1) {
					if (isAlive(i, j, board)) {
						newBoard[i][j] = 1;
					}
				} else {
					if (isNew(i, j, board)) {
						newBoard[i][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				board[i][j] = newBoard[i][j];
			}
		}

	}

	private boolean isAlive(int y, int x, int[][] board) {
		int count = 0;
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= board.length
					|| nx < 0 || nx >= board[0].length) {
				continue;
			}
			if (board[ny][nx] == 1) {
				count++;
			}
		}
		return count == 2 || count == 3;
	}

	private boolean isNew(int y, int x, int[][] board) {
		int count = 0;
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= board.length
					|| nx < 0 || nx >= board[0].length) {
				continue;
			}
			if (board[ny][nx] == 1) {
				count++;
			}
		}
		return count == 3;
	}
}
