#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, m;

    std::cin >> n >> k >> m;

    char *safes = new char[n * k];
    char *sorted_safes = new char[n * k];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::cin >> safes[i * k + j];
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        int o_num = 0;
        int x_num = 0;

        for (int j = 0; j < n; j++)
        {
            if (safes[j * k + i] == 'X')
                x_num++;
            else
                o_num++;
        }

        x_num += o_num;

        for (int j = n - 1; j >= 0; j--)
        {
            if (safes[j * k + i] == 'o')
            {
                for (int x = 0; x < k; x++)
                    sorted_safes[(o_num - 1) * k + x] = safes[j * k + x];
                o_num--;
            }
            else
            {
                for (int x = 0; x < k; x++)
                    sorted_safes[(x_num - 1) * k + x] = safes[j * k + x];
                x_num--;
            }
        }

        for (int y = 0; y < n; y++)
            for (int x = 0; x < k; x++)
                safes[y * k + x] = sorted_safes[y * k + x];
    }

    for (int i = n - 1; i >= n - m; i--)
    {
        for (int j = 0; j < k; j++)
        {
            std::cout << safes[i * k + j];
        }
        std::cout << '\n';
    }

    delete[] safes;
    delete[] sorted_safes;

    return 0;
}