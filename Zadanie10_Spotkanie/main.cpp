#include <iostream>
#include <vector>

struct Person
{
    int num;
    int priority;
};

struct Answer
{
    int first_num;
    int second_num;
};

void push(std::vector<Person> &, int);
void pop(std::vector<Person> &);

void down_swapping(std::vector<Person> &, int);

void swap(Person *, Person *);
bool predicate(Person, Person);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;

        std::vector<Person> persons;

        for (int i = 0; i < n; i++)
        {
            int priority_i;
            std::cin >> priority_i;

            if (priority_i != 0)
            {
                if (i == 0)
                {
                    persons.push_back({i + 1, priority_i});
                }
                else
                {
                    persons.push_back({i + 1, priority_i});

                    push(persons, persons.size() - 1);
                }
            }
        }

        std::vector<Answer> answers;

        while (persons.size() > 1)
        {
            Person first = persons[0];

            pop(persons);

            Person second = persons[0];

            pop(persons);

            if (first.num < second.num)
                answers.push_back({first.num, second.num});
            else
                answers.push_back({second.num, first.num});

            first.priority--;
            second.priority--;

            if (first.priority > 0)
            {
                persons.push_back(first);
                push(persons, persons.size() - 1);
            }

            if (second.priority > 0)
            {
                persons.push_back(second);
                push(persons, persons.size() - 1);
            }
        }

        std::cout << answers.size() << '\n';
        for (int i = 0; i < answers.size(); i++)
            std::cout << answers[i].first_num << ' ' << answers[i].second_num << '\n';
    }

    return 0;
}

void swap(Person *person_1, Person *person_2)
{
    Person temp = *person_1;
    *person_1 = *person_2;
    *person_2 = temp;
}

bool predicate(Person person_1, Person person_2)
{
    return (person_1.priority > person_2.priority) || (person_1.priority == person_2.priority && person_1.num < person_2.num);
}

void push(std::vector<Person> &persons, int i)
{
    if (i != 0)
    {
        int root_index;

        if (i % 2 == 0)
            root_index = (i - 2) / 2;
        else
            root_index = (i - 1) / 2;

        if (predicate(persons[i], persons[root_index]))
        {
            swap(&persons[i], &persons[root_index]);
            push(persons, root_index);
        }
    }
}

void pop(std::vector<Person> &persons)
{
    persons[0] = persons[persons.size() - 1];

    persons.pop_back();

    down_swapping(persons, 0);
}

void down_swapping(std::vector<Person> &persons, int i)
{
    int root_index = i;
    int left_child_index = 2 * root_index + 1;
    int right_child_index = 2 * root_index + 2;

    if (right_child_index < persons.size())
        if (predicate(persons[right_child_index], persons[root_index]))
            root_index = right_child_index;

    if (left_child_index < persons.size())
        if (predicate(persons[left_child_index], persons[root_index]))
            root_index = left_child_index;

    if (root_index != i)
    {
        swap(&persons[i], &persons[root_index]);

        down_swapping(persons, root_index);
    }
}