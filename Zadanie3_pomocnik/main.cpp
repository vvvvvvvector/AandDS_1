#include <iostream>
#include <cstdio>
#include <cstring>

int binary_search(int *sum, int l, int r, int el)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (sum[mid] == el)
            return mid;

        if (sum[mid] > el)
            return binary_search(sum, l, mid - 1, el);

        return binary_search(sum, mid + 1, r, el);
    }
    return -1;
}

void delete_sum(int *sum, int &n, int el_index)
{
    for (int i = el_index; i < n - 1; i++)
        sum[i] = sum[i + 1];
    n--;
}

struct Plants
{
    char plant_name[31]{'\0'};
    int num;
    Plants *next, *prev;
};

void push_plant(Plants **, char *, int);

void delete_plant(Plants **);

struct List
{
    int plants_list_size;

    Plants *plants_list;
    List *next, *prev;
} *list_head = nullptr, *head = nullptr;

void push_list(List **, List **, Plants *, int);

int calc_sum(List *);

void delete_green_cells(List **, int &);

void delete_list(List **);

void show_plants(List *);

void clear(List **);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 5000)
    {
        for (int i = 0; i < n; i++)
        {
            int plants_list_size;
            scanf("%d", &plants_list_size);
            Plants *plants_list = nullptr;
            for (int j = 0; j < plants_list_size; j++)
            {
                int c;
                char plant_name[31]{'\0'};

                scanf("%30s %d", plant_name, &c);

                if (c >= 1 && c <= 1000)
                {
                    push_plant(&plants_list, plant_name, c);
                }
            }
            push_list(&list_head, &head, plants_list, plants_list_size);
        }

        int n_sum;
        scanf("%d", &n_sum);

        int *sum = new int[n_sum];

        for (int i = 0; i < n_sum; i++)
        {
            int s;
            scanf("%d", &s);
            sum[i] = s;
        }

        int n_signal;
        scanf("%d", &n_signal);

        int current_sum = calc_sum(list_head);

        while (n_sum != 0 || n_signal != 0)
        {
            int sum_index = binary_search(sum, 0, n_sum - 1, current_sum);

            if (sum_index != -1)
            {
                delete_sum(sum, n_sum, sum_index);
                printf("%d ", current_sum);
                show_plants(head);
                delete_green_cells(&list_head, n);
                if (list_head != nullptr)
                    current_sum = calc_sum(list_head);
                else
                    break;
            }

            if (n_signal == 0 && sum_index == -1)
                break;

            if (sum_index == -1)
            {
                int x, y;
                scanf("%d %d", &x, &y);

                if (x >= -10000 && x <= 10000)
                {
                    if (x > 0)
                    {
                        if (x > n)
                            x = x % n;
                        if (x > n / 2.0)
                            for (int i = 0; i < n - x; i++)
                                list_head = list_head->prev;
                        else
                            for (int i = 0; i < x; i++)
                                list_head = list_head->next;
                    }
                    else if (x < 0)
                    {
                        x *= -1;
                        if (x > n)
                            x = x % n;
                        if (x > n / 2.0)
                            for (int i = 0; i < n - x; i++)
                                list_head = list_head->next;
                        else
                            for (int i = 0; i < x; i++)
                                list_head = list_head->prev;
                    }
                }

                current_sum -= list_head->plants_list->num;

                if (y >= -10000 && y <= 10000)
                {
                    if (y > 0)
                    {
                        if (y > list_head->plants_list_size)
                            y = y % list_head->plants_list_size;
                        if (y > list_head->plants_list_size / 2.0)
                            for (int i = 0; i < list_head->plants_list_size - y; i++)
                                list_head->plants_list = list_head->plants_list->prev;
                        else
                            for (int i = 0; i < y; i++)
                                list_head->plants_list = list_head->plants_list->next;
                    }
                    else if (y < 0)
                    {
                        y *= -1;
                        if (y > list_head->plants_list_size)
                            y = y % list_head->plants_list_size;
                        if (y > list_head->plants_list_size / 2.0)
                            for (int i = 0; i < list_head->plants_list_size - y; i++)
                                list_head->plants_list = list_head->plants_list->next;
                        else
                            for (int i = 0; i < y; i++)
                                list_head->plants_list = list_head->plants_list->prev;
                    }
                }

                current_sum += list_head->plants_list->num;

                n_signal--;
            }
        }

        if (list_head != nullptr)
            clear(&list_head);

        delete[] sum;
    }

    return 0;
}

void push_list(List **start, List **head, Plants *list, int plants_list_size) // +
{
    if (*start == nullptr)
    {
        List *new_el = new List;
        new_el->plants_list_size = plants_list_size;
        new_el->plants_list = list;
        new_el->next = new_el->prev = new_el;
        *start = *head = new_el;
    }
    else
    {
        List *new_el = new List;
        new_el->plants_list_size = plants_list_size;
        new_el->plants_list = list;

        List *last_el = (*start)->prev;
        new_el->prev = last_el;
        new_el->next = *start;
        (*start)->prev = new_el;

        last_el->next = new_el;
    }
}

void push_plant(Plants **start, char *name, int num) // +
{
    if (*start == nullptr)
    {
        Plants *new_el = new Plants;
        strcpy(new_el->plant_name, name);
        new_el->num = num;
        new_el->next = new_el->prev = new_el;
        *start = new_el;
    }
    else
    {
        Plants *new_el = new Plants;
        strcpy(new_el->plant_name, name);
        new_el->num = num;

        Plants *last_el = (*start)->prev;
        new_el->prev = last_el;
        new_el->next = *start;
        (*start)->prev = new_el;

        last_el->next = new_el;
    }
}

int calc_sum(List *start) // +
{
    int sum = 0;
    List *q = start->next;
    while (start != q)
    {
        sum += q->plants_list->num;
        q = q->next;
    }
    sum += start->plants_list->num;
    return sum;
}

void show_plants(List *start) // +
{
    printf("%s ", start->plants_list->plant_name);
    List *q = start->next;
    while (start != q)
    {
        printf("%s ", q->plants_list->plant_name);
        q = q->next;
    }
    printf("\n");
}

void delete_green_cells(List **start, int &n)
{
    List *q = (*start)->next;
    while ((*start) != q)
    {
        q->plants_list_size--;
        delete_plant(&(q->plants_list));
        if (q->plants_list == nullptr)
        {
            n--;
            delete_list(&q);
        }
        else
            q = q->next;
    }
    (*start)->plants_list_size--;
    delete_plant(&((*start)->plants_list));
    if ((*start)->plants_list == nullptr)
    {
        n--;
        delete_list(&(*start));
    }
}

void delete_list(List **start)
{
    if ((*start)->next == *start)
    {
        delete *start;
        *start = nullptr;
        head = nullptr;
    }
    else
    {
        if (*start != head)
        {
            List *new_start = (*start)->next;
            (*start)->next->prev = (*start)->prev;
            (*start)->prev->next = (*start)->next;
            delete *start;
            *start = nullptr;
            *start = new_start;
        }
        else
        {
            List *new_start = (*start)->next;
            (*start)->next->prev = (*start)->prev;
            (*start)->prev->next = (*start)->next;
            delete *start;
            *start = nullptr;
            *start = new_start;
            head = new_start;
        }
    }
}

void delete_plant(Plants **start)
{
    if ((*start)->next == *start)
    {
        delete *start;
        *start = nullptr;
    }
    else
    {
        Plants *new_start = (*start)->next;
        (*start)->next->prev = (*start)->prev;
        (*start)->prev->next = (*start)->next;
        delete *start;
        *start = nullptr;
        *start = new_start;
    }
}

void clear(List **start)
{
    List *q = (*start)->next;
    while (q != *start)
    {
        Plants *temp = q->plants_list->next;
        while (temp != q->plants_list)
        {
            delete_plant(&temp);
            temp = temp->next;
        }
        delete_plant(&q->plants_list);
        delete_list(&q);
    }
    Plants *temp = (*start)->plants_list->next;
    while (temp != (*start)->plants_list)
    {
        delete_plant(&temp);
        temp = temp->next;
    }
    delete_plant(&(*start)->plants_list);
    delete_list(&(*start));
}