#include <iostream>
#include <string>

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

    while (t > 0)
    {
        std::string input;
        std::cin >> input;

        if (input.size() > 10)
        {
            std::cout << input.front() << input.size() - 2 << input.back() << '\n';
        }
        else
        {
            std::cout << input << '\n';
        }

        t--;
    }

    // ---- ----
    return 0;
}