#include <iostream>

#define MAX 2147483647

bool solve(int, const int *, int, int, int, int &);

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        int *data = new int[2 * n];

        int min_cost = MAX;

        for (int i = 0; i < n; i++)
            scanf("%d %d", &data[i * 2], &data[i * 2 + 1]);

        if (solve(0, data, n, 0, 0, min_cost))
            printf("%d\n", min_cost);
        else
            printf("NIE\n");

        delete[] data;
    }

    return 0;
}

bool solve(int begin, const int *data, int n, int level_sum, int cost_sum, int &min_cost)
{
    if (level_sum == 0 && cost_sum < min_cost && cost_sum != 0)
    {
        min_cost = cost_sum;
        return true;
    }

    bool result = false;
    for (int i = begin; i < n; i++)
    {
        level_sum += data[i * 2];
        cost_sum += data[i * 2 + 1];

        if (cost_sum < min_cost)
            result = solve(i + 1, data, n, level_sum, cost_sum, min_cost) || result;

        level_sum -= data[i * 2];
        cost_sum -= data[i * 2 + 1];
    }

    return result;
}