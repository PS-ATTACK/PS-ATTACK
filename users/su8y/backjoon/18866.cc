#include<iostream>
#define INF 1000000005
#define L 1000005
using namespace std;
struct day {
	int happy;
	int sleepy;
};
day days[L]; //happy, sleepy
day youth[L]; //minHappy, maxSleepy
day old[L]; //maxHappy, minSleepy
int cmp(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	int maxHappy = -1;
	int minHappy = INF;
	int maxSleepy = -1;
	int minSleepy = INF;
	int N; 
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &days[i].happy, &days[i].sleepy);
	}
	//youth
	for (int i = 1; i <= N; i++) {
		if (days[i].happy != 0 && days[i].happy < minHappy) {
			minHappy = days[i].happy;
		}
		if (days[i].sleepy != 0 && days[i].sleepy > maxSleepy) {
			maxSleepy = days[i].sleepy;
		}
		youth[i].happy = minHappy;
		youth[i].sleepy = maxSleepy;
	}
	//old
	for (int i = N; i >= 0; i--) {
		if (days[i].happy != 0 && days[i].happy > maxHappy) {
			maxHappy = days[i].happy;
		}
		if (days[i].sleepy != 0 && days[i].sleepy < minSleepy) {
			minSleepy = days[i].sleepy;
		}
		old[i].happy = maxHappy;
		old[i].sleepy = minSleepy;
	}
	//판별 시작
	int count = -1;
	for (int k = N - 1; k >= 0; k--) { //K는 젊은 날
		int youth_happy = youth[k].happy;
		int youth_sleepy = youth[k].sleepy;
		int old_happy = old[k+1].happy;
		int old_sleepy = old[k+1].sleepy;
		if (youth_happy > old_happy && youth_sleepy < old_sleepy) {
			count = cmp(count, k);
		}
	}
	printf("%d", count);
	return 0;
}