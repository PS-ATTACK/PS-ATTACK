#define ll long long

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    int st, ap;
    int total = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {

        scanf("%d %d", &st, &ap);

        if (st > ap) {
            total += ap;
        } else {
            total += ap % st;
        }
    }
    
    printf("%d", total);

    return 0;
}