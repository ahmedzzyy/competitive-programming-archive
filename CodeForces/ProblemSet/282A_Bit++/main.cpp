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

    int t, state = 0;
    std::cin >> t;

    while (t > 0)
    {
        std::string statement;
        std::cin >> statement;

        if (statement == "X++" || statement == "++X")
        {
            state++;
        }
        else if (statement == "X--" || statement == "--X")
        {
            state--;
        }

        t--;
    }

    std::cout << state;

    // ---- ----
    return 0;
}