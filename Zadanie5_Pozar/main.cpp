#include <iostream>
#include <queue>
#include <vector>

int d_y[] = {-1, 1, 0, 0}; // {-1, 0} up; {1, 0} down - row direction vectors
int d_x[] = {0, 0, 1, -1}; // {0, 1} right; {0, -1} left - column direction vectors

struct Border_Min_Cell
{
    int x, y, value;
};

void bfs_algorithm_m(char **, int **, int, int, int, int);

void bfs_algorithm_fire(char **, int **, int, int);

Border_Min_Cell find_min(std::vector<Border_Min_Cell> &);

int main()
{
    int t; // number of tests
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n, m; // n - row, m - column
        scanf("%d %d", &n, &m);

        if ((n <= 1000 && n >= 0) && (m <= 1000 && m >= 0))
        {
            char **map = new char *[n];
            int **m_distances_map = new int *[n];
            int **f_distances_map = new int *[n];

            int m_x, m_y; // Mieszko vertical, horizontal coordinates

            for (int i = 0; i < n; i++)
            {
                map[i] = new char[m];
                m_distances_map[i] = new int[m];
                f_distances_map[i] = new int[m];
            }

            for (int y = 0; y < n; y++) // row
            {
                for (int x = 0; x < m; x++) // column
                {
                    std::cin >> map[y][x];

                    if (map[y][x] == 'M')
                    {
                        m_x = x; // Mieszko x coordinate (vertical)
                        m_y = y; // Mieszko y coordinate (horizontal)
                    }

                    m_distances_map[y][x] = -1;
                    f_distances_map[y][x] = -1;
                }
            }

            bfs_algorithm_m(map, m_distances_map, m_x, m_y, n, m);
            bfs_algorithm_fire(map, f_distances_map, n, m);

            std::vector<Border_Min_Cell> vector;

            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < m; x++)
                {
                    if (y == 0 || x == 0 || x == m - 1 || y == n - 1)
                    {
                        if (m_distances_map[y][x] != -1)
                        {
                            vector.push_back({x, y, m_distances_map[y][x]});
                        }
                    }
                }
            }

            if (!vector.empty())
            {
                Border_Min_Cell min = find_min(vector);

                int y_min = min.y;
                int x_min = min.x;

                bool is_burned = true;

                do
                {
                    if (m_distances_map[y_min][x_min] < f_distances_map[y_min][x_min])
                    {
                        printf("%d\n", m_distances_map[y_min][x_min] + 1);
                        is_burned = false;
                    }
                    else if (f_distances_map[y_min][x_min] == -1 && m_distances_map[y_min][x_min] >= 0)
                    {
                        printf("%d\n", m_distances_map[y_min][x_min] + 1);
                        is_burned = false;
                    }
                    else
                    {
                        if (!vector.empty())
                        {
                            min = find_min(vector);
                            y_min = min.y;
                            x_min = min.x;
                        }
                    }
                } while (!vector.empty() && is_burned);

                if (is_burned)
                    printf("NIE\n");
            }
            else
                printf("NIE\n");

            for (int i = 0; i < n; i++)
            {
                delete[] map[i];
                delete[] m_distances_map[i];
                delete[] f_distances_map[i];
            }

            delete[] map;
            delete[] m_distances_map;
            delete[] f_distances_map;
        }
    }

    return 0;
}

void bfs_algorithm_m(char **map, int **m_distances_map, int m_x, int m_y, int n, int m)
{
    std::queue<int> x_queue;
    std::queue<int> y_queue;

    x_queue.push(m_x); // Mieszko x vertical coordinate
    y_queue.push(m_y); // Mieszko y horizontal coordinate

    m_distances_map[m_y][m_x] = 0; // start position distance = 0

    while (!x_queue.empty() || !y_queue.empty())
    {
        int current_x = x_queue.front();
        int current_y = y_queue.front();

        x_queue.pop();
        y_queue.pop();

        for (int i = 0; i < 4; i++) // 0 - up, 1 - down, 2 - right, 3 - left neighbour
        {
            bool is_neighbour = true;

            if (current_x + d_x[i] >= m || current_x + d_x[i] < 0) // segmentation fault
                is_neighbour = false;
            else if (current_y + d_y[i] >= n || current_y + d_y[i] < 0) // segmentation fault
                is_neighbour = false;
            else if (map[current_y + d_y[i]][current_x + d_x[i]] == '#' || map[current_y + d_y[i]][current_x + d_x[i]] == 'O') // wall or fire can't be a neighbour
                is_neighbour = false;
            else if (m_distances_map[current_y + d_y[i]][current_x + d_x[i]] != -1) // only new element can be a neighbour
                is_neighbour = false;

            if (is_neighbour)
            {
                int new_x = current_x + d_x[i];
                int new_y = current_y + d_y[i];

                m_distances_map[new_y][new_x] = m_distances_map[current_y][current_x] + 1;

                x_queue.push(new_x);
                y_queue.push(new_y);
            }
        }
    }
}

void bfs_algorithm_fire(char **map, int **f_distances_map, int n, int m)
{
    std::queue<int> x_queue;
    std::queue<int> y_queue;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 'O')
            {
                x_queue.push(x);
                y_queue.push(y);

                f_distances_map[y][x] = 0;
            }
        }
    }

    while (!x_queue.empty() || !y_queue.empty())
    {
        int current_x = x_queue.front();
        int current_y = y_queue.front();

        x_queue.pop();
        y_queue.pop();

        for (int i = 0; i < 4; i++)
        {
            bool is_neighbour = true;

            if (current_x + d_x[i] >= m || current_x + d_x[i] < 0) // segmentation fault
                is_neighbour = false;
            else if (current_y + d_y[i] >= n || current_y + d_y[i] < 0) // segmentation fault
                is_neighbour = false;
            else if (map[current_y + d_y[i]][current_x + d_x[i]] == '#' || map[current_y + d_y[i]][current_x + d_x[i]] == 'O') // wall or fire can't be a neighbour
                is_neighbour = false;
            else if (f_distances_map[current_y + d_y[i]][current_x + d_x[i]] != -1) // only new element can be a neighbour
                is_neighbour = false;

            if (is_neighbour)
            {
                int new_x = current_x + d_x[i];
                int new_y = current_y + d_y[i];

                f_distances_map[new_y][new_x] = f_distances_map[current_y][current_x] + 1;

                x_queue.push(new_x);
                y_queue.push(new_y);
            }
        }
    }
}

Border_Min_Cell find_min(std::vector<Border_Min_Cell> &vector)
{
    int min_index = 0;
    int x = vector[0].x;
    int y = vector[0].y;
    int min = vector[0].value;

    for (int i = 0; i < vector.size(); i++)
    {
        if (min > vector[i].value)
        {
            min = vector[i].value;
            x = vector[i].x;
            y = vector[i].y;
            min_index = i;
        }
    }

    vector.erase(vector.begin() + min_index);
    return {x, y, min};
}