#include <vector>
#include <algorithm>
#include <iostream>
int finding(int, int, int);
int main(void)
{
    int A, B, C;

    std::cin >> A >> B >> C;
    std::cout << finding(A, B, C) << std::endl;
}
int finding(int a, int b, int c)
{
    int res;
    std::vector<int> arr = {a, b, c};
    std::sort(arr.begin(), arr.end());
    res = arr.at(1);
    return res;
}