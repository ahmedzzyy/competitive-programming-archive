#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    // ---- CODE ----

    int w;
    std::cin >> w;

    // w: 1, ...100
    // Invalid: 1, 2, 3;
    // Valid: if ans = even num + another or same even num
    // even + even = even . Therefore w has to be even

    if (w <= 3 || w % 2 != 0)
    {
        std::cout << "NO";
    }
    else if (w % 2 == 0)
    {
        std::cout << "YES";
    }

    // ---- ----
    return 0;
}