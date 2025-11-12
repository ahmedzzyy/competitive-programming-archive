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

    int t;
    std::cin >> t;

    int numOfSolutions = 0;

    while (t > 0)
    {
        int i, j, k;
        std::cin >> i >> j >> k;

        numOfSolutions += (i + j + k) / 2;

        t--;
    }

    std::cout << numOfSolutions;

    // ---- ----
    return 0;
}