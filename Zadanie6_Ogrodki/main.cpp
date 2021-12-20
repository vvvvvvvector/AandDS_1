#include <iostream>
#include <algorithm>

struct Building
{
    int coordinates[4]; // x_1, y_1, x_2, y_2
};

bool compare_x1(const Building &building1, const Building &building2)
{
    return building1.coordinates[0] < building2.coordinates[0];
}

bool compare_y1(const Building &building1, const Building &building2)
{
    return building1.coordinates[1] < building2.coordinates[1];
}

bool algorithm(Building *, int, int);

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        Building *buildings = new Building[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &buildings[i].coordinates[0], &buildings[i].coordinates[1], &buildings[i].coordinates[2], &buildings[i].coordinates[3]);
        }

        if (algorithm(buildings, 0, n))
            printf("TAK\n");
        else
            printf("NIE\n");

        delete[] buildings;
    }

    return 0;
}

bool algorithm(Building *buildings, int begin, int end)
{
    if (end - begin < 2)
        return true;
    else
    {
        std::sort(buildings + begin, buildings + end, compare_x1);

        int building_end_x = buildings[begin].coordinates[2];

        for (int i = begin + 1; i < end; i++)
        {
            if (building_end_x <= buildings[i].coordinates[0])
            {
                if (algorithm(buildings, begin, i) && algorithm(buildings, i, end)) // left && right
                    return true;
                else
                    return false;
            }
            else if (building_end_x < buildings[i].coordinates[2])
                building_end_x = buildings[i].coordinates[2];
        }

        std::sort(buildings + begin, buildings + end, compare_y1);

        int building_end_y = buildings[begin].coordinates[3];

        for (int i = begin + 1; i < end; i++)
        {
            if (building_end_y <= buildings[i].coordinates[1])
            {
                if (algorithm(buildings, begin, i) && algorithm(buildings, i, end)) // bottom && top
                    return true;
                else
                    return false;
            }
            else if (building_end_y < buildings[i].coordinates[3])
                building_end_y = buildings[i].coordinates[3];
        }

        return false;
    }
}