#include <iostream>
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

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::string a;
        int m;
        std::string b, c;

        std::cin >> n >> a >> m >> b >> c;

        std::string vlad, dima;

        for (int i = 0; i < m; i++)
        {
            if (c[i] == 'V')
            {
                vlad.push_back(b[i]);
            }
            else
            {
                dima.push_back(b[i]);
            }
        }

        std::reverse(vlad.begin(), vlad.end());
        std::cout << vlad + a + dima << "\n";
    }

    // ---- ----
    return 0;
}