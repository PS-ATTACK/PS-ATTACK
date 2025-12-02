 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
class Pair<T,U> implements Comparable<Pair<T,U>> {
    private T first;
    private U second;

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }

    @Override
    public int compareTo(Pair<T, U> o) {
        return (int) this.first - (int)o.first;
    }
}

public class Main {
    static int N;
    static int M;
    static List<List<Pair>> adj;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for(int i = 0 ; i<= N;i++){
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            //first cost second endvertax
            adj.get(start).add(new Pair(cost, end));
        }

        long[] dist =spfa(1);
        if (dist!= null){
            for(int i = 2; i <= N ; i++){
                System.out.println(dist[i]);
            }
        }else{
            System.out.println(-1);
        }
    }
    public static long[] spfa(int start){
        boolean[] inq = new boolean[N+1];
        long[] dist = new long[N+1];
        Arrays.fill(dist,Long.MAX_VALUE);
        int[] visited = new int[N+1];
        Queue<Integer> q = new LinkedList<>();

        q.offer(start);
        inq[start] = true;
        dist[start] = 0;
        visited[start] = 1;

        while (!q.isEmpty()) {
            int here = q.peek(); q.poll();
            inq[here] = false;
            for(Pair i : adj.get(here)){
                int there = (int) i.getSecond();
                int thereCost = (int) i.getFirst();
                if(dist[there] > dist[here] + thereCost){
                    dist[there] = dist[here] + thereCost;
                    if(!inq[there]){
                        visited[there]++;
                        if(visited[here] >= N){
                            return null;
                        }
                        q.offer(there);
                        inq[there] = true;
                    }
                }
            }
        }
        for(int i = 2; i <=N; i++){
            dist[i] =dist[i] == Long.MAX_VALUE ? -1 :dist[i];
        }

        return dist;

    }
}
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 510;
const int MAXM = 6010;
const int INF = 1 << 30;

#define fi first
#define se second
#define eb emplace_back

vector<pii> ed[MAXN];
int d[MAXN];
bool inq[MAXN];			// queue에 해당 정점이 들어가있는지 여부
int cnt[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;

	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].eb(b, c);
	}

	for(int i = 2; i <= N; i++) d[i] = INF;
	queue<int> q;
	q.push(1);
	inq[1] = true;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		inq[t] = false;
		if(++cnt[t] >= N || d[t] < -INF) {	// 음수 사이클
			cout << "-1\n";
			return 0;
		}
		for(auto a : ed[t]) if(d[t] + a.se < d[a.fi]) {
			d[a.fi] = d[t] + a.se;
			if(!inq[a.fi]) {		// queue에 없을 경우 추가
				q.push(a.fi);
				inq[a.fi] = true;
			}
		}
	}

	for(int i = 2; i <= N; i++) cout << (d[i] == INF ? -1 : d[i]) << "\n";
	return 0;
}