#include <cstdio>
#include <iostream>

#define N_MIN 1
#define N_MAX 1000000

struct Warzywa
{
    char name[20]{'\0'};
    float z;
    int d;
    int m;
};

bool func123(Warzywa el, float z, int d, int m)
{
    return el.z < z || (el.z == z && el.d < d) || (el.z == z && el.d == d && el.m < m);
}

bool func132(Warzywa el, float z, int d, int m)
{
    return el.z < z || (el.z == z && el.m < m) || (el.z == z && el.m == m && el.d < d);
}

bool func213(Warzywa el, float z, int d, int m)
{
    return el.d < d || (el.d == d && el.z < z) || (el.d == d && el.z == z && el.m < m);
}

bool func231(Warzywa el, float z, int d, int m)
{
    return el.d < d || (el.d == d && el.m < m) || (el.d == d && el.m == m && el.z < z);
}

bool func312(Warzywa el, float z, int d, int m)
{
    return el.m < m || (el.m == m && el.z < z) || (el.m == m && el.z == z && el.d < d);
}

bool func321(Warzywa el, float z, int d, int m)
{
    return el.m < m || (el.m == m && el.d < d) || (el.m == m && el.d == d && el.z < z);
}

void insertion_sort(Warzywa *arr, int n, bool (*func)(Warzywa, float, int, int))
{
    Warzywa key = arr[n];
    int m = arr[n].m;
    float z = arr[n].z;
    int d = arr[n].d;
    int j = n - 1;
    while (j >= 0 && func(arr[j], z, d, m))
    {
        arr[j + 1] = arr[j];
        --j;
    }
    arr[j + 1] = key;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, p_1, p_2, p_3;
    bool (*func)(Warzywa, float, int, int);
    scanf("%d", &n);
    scanf("%d %d %d", &p_1, &p_2, &p_3);

    switch (p_1)
    {
    case 1:
        if (p_2 == 2)
            func = &func123;
        else
            func = &func132;
        break;
    case 2:
        if (p_2 == 1)
            func = &func213;
        else
            func = &func231;
        break;
    case 3:
        if (p_2 == 1)
            func = &func312;
        else
            func = &func321;
        break;
    }

    if (n >= N_MIN && n <= N_MAX)
    {
        Warzywa *korzeniowe = new Warzywa[n];
        Warzywa *niekorzeniowe = new Warzywa[n];

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                scanf("%s %f %d %d", korzeniowe[i].name, &korzeniowe[i].z, &korzeniowe[i].d, &korzeniowe[i].m);
            else
            {
                scanf("%s %f %d %d", korzeniowe[i].name, &korzeniowe[i].z, &korzeniowe[i].d, &korzeniowe[i].m);
                insertion_sort(korzeniowe, i, func);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                scanf("%s %f %d %d", niekorzeniowe[i].name, &niekorzeniowe[i].z, &niekorzeniowe[i].d, &niekorzeniowe[i].m);
            else
            {
                scanf("%s %f %d %d", niekorzeniowe[i].name, &niekorzeniowe[i].z, &niekorzeniowe[i].d, &niekorzeniowe[i].m);
                insertion_sort(niekorzeniowe, i, func);
            }
        }

        for (int i = 0; i < n; i++)
        {
            printf("%s-%s ", korzeniowe[i].name, niekorzeniowe[i].name);
        }

        printf("\n");

        delete[] niekorzeniowe;
        delete[] korzeniowe;
    }
}