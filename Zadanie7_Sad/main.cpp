#include <iostream>

int find_max(int *);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int **rows = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        rows[i] = new int[m];
    }

    for (int x = 0; x < m; x++)
        std::cin >> rows[0][x];

    for (int y = 0; y < n - 1; y++)
    {
        for (int x = 0; x < m; x++)
        {
            std::cin >> rows[1][x];

            int above_left = 0, above_right = 0;
            if (x - 1 >= 0)
                above_left = rows[0][x - 1];
            if (x + 1 < m)
                above_right = rows[0][x + 1];

            int numbers[] = {above_left, rows[0][x], above_right};

            int max = find_max(numbers);

            rows[1][x] += max;
        }
        for (int x = 0; x < m; x++)
            rows[0][x] = rows[1][x];
    }

    int max = rows[0][0];
    int max_index = 0;

    for (int i = 1; i < m; i++)
    {
        if (max < rows[0][i])
        {
            max = rows[0][i];
            max_index = i;
        }
    }

    std::cout << max_index << " " << max << '\n';

    for (int i = 0; i < 2; i++)
    {
        delete[] rows[i];
    }
    delete[] rows;

    return 0;
}

int find_max(int *numbers)
{
    int max = numbers[0];
    for (int i = 1; i < 3; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    return max;
}