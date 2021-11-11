#include <iostream>
#include <string>

struct Node
{
    std::string description;
    int class_num;

    Node *parent;
    Node *first_child;
    Node *bro;
};

void init(Node **);

void push(Node **, std::string, int);

void update(Node **, std::string);

void delete_tree(Node **);

void postorder(Node *root)
{
    if (root->first_child != nullptr)
        postorder(root->first_child);

    std::cout << root->description << '\n';

    if (root->bro != nullptr)
        postorder(root->bro);
}

void preorder(Node *root)
{
    std::cout << root->description << '\n';

    if (root->first_child != nullptr)
        preorder(root->first_child);

    if (root->bro != nullptr)
        preorder(root->bro);
}

int main()
{
    Node *root = nullptr;
    init(&root);

    int n;
    scanf("%d\n", &n);

    if (n >= 0 && n <= 10000)
    {
        for (int i = 0; i < n; i++)
        {
            std::string description;
            std::getline(std::cin, description);
            std::string numbers;
            std::getline(std::cin, numbers);

            char *pEnd;
            int k = strtol(numbers.c_str(), &pEnd, 10);

            if (k >= 1 && k <= 100)
            {
                Node *temp = root;

                for (int j = 0; j < k; j++)
                {
                    int k_n = strtol(pEnd, &pEnd, 10);

                    bool already_on_level = false;

                    if (temp->first_child != nullptr)
                    {
                        Node *last = temp->first_child;
                        while (last && !already_on_level)
                        {
                            if (last->class_num == k_n)
                            {
                                already_on_level = true;
                                temp = last;
                            }
                            else
                                last = last->bro;
                        }
                    }

                    if (!already_on_level && j == k - 1)
                        push(&temp, description, k_n);
                    else if (already_on_level && j == k - 1)
                        update(&temp, description);
                    else if (temp->description == "X" && j == k - 1)
                        update(&temp, description);
                    else if (!already_on_level)
                        push(&temp, "X", k_n);
                }
            }
        }

        int order;
        scanf("%d", &order);

        if (order == 1)
            preorder(root);
        if (order == 2)
            postorder(root);

        delete_tree(&root);
        root = nullptr;
    }

    return 0;
}

void init(Node **root)
{
    Node *node = new Node;
    node->class_num = 0;
    node->description = "Stan spoczynku";

    node->first_child = nullptr;
    node->bro = nullptr;
    node->parent = nullptr;

    *root = node;
}

void update(Node **start, std::string new_description)
{
    (*start)->description = new_description;
}

void push(Node **start, std::string description, int class_num)
{
    if ((*start)->first_child == nullptr)
    {
        Node *node = new Node;
        node->class_num = class_num;
        node->description = description;

        (*start)->first_child = node;
        node->parent = *start;
        node->bro = nullptr;
        node->first_child = nullptr;

        *start = (*start)->first_child;
    }
    else
    {
        Node *node = new Node;
        node->class_num = class_num;
        node->description = description;

        node->parent = (*start)->first_child->parent;
        node->bro = nullptr;
        node->first_child = nullptr;

        Node *last = (*start)->first_child;
        while (last->bro)
            last = last->bro;
        last->bro = node;

        *start = last->bro;
    }
}

void delete_tree(Node **root)
{
    if (*root == nullptr)
        return;

    delete_tree(&(*root)->first_child);
    delete_tree(&(*root)->bro);

    delete *root;
}