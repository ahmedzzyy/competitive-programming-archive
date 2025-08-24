#include <iostream>
#include <vector>
#include <algorithm>

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

    long long t;
    std::cin >> t;
    while (t--)
    {
        long long n;
        std::cin >> n;

        std::vector<long long> result;
        long long powerOfTen = 10;
        while ((powerOfTen + 1) <= n)
        {
            if (n % (powerOfTen + 1) == 0)
                result.push_back(n / (powerOfTen + 1));

            powerOfTen *= 10;
        }

        std::sort(result.begin(), result.end());
        std::cout << result.size() << "\n";

        for (auto i : result)
            std::cout << i << " ";

        if (!result.empty())
        {
            std::cout << "\n";
        }
    }

    // ---- ----
    return 0;
}