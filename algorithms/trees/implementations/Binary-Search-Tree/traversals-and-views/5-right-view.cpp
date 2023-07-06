#include <iostream>
#include <list>

struct node
{
    int data;
    node *left, *right;

    node() = delete;

    node(int v) : data(v),
                  left(nullptr),
                  right(nullptr){};
};

class Tree
{
protected:
    node *_root;

public:
    typedef std::list<node *> list;

public:
    Tree() : _root(nullptr){};

public:
    void
    view_in_order();

    void
    insert(int newData);

private:
    void
    _in_order(node *);

    node *
    _insertUtility(node *, int newData);
};

void Tree::view_in_order()
{
    _in_order(_root);
}

void Tree::_in_order(node *curr_node)
{
    if (curr_node)
    {
        _in_order(curr_node->left);
        std::cout << curr_node->data << " : ";
        _in_order(curr_node->right);
    }
}

void Tree::insert(int newData)
{
    _root = _insertUtility(_root, newData);
}

node *
Tree::_insertUtility(node *curr_node, int newData)
{
    if (curr_node == nullptr)
        return new node(newData);

    else if (newData < curr_node->data)
        curr_node->left = _insertUtility(curr_node->left, newData);
    else
        curr_node->right = _insertUtility(curr_node->right, newData);

    return curr_node;
}

//______SOLUTION_______//

class View_utility : public Tree
{

public:
    void
    right_view_iterative();

    void
    right_view_recursive();

private:
    void
    _right_view_recursive_util(node *, int, int &);
};

void View_utility::right_view_iterative()
{
    list parent = {_root};
    list current;

    std::cout << "Right view :\n";

    while (!parent.empty())
    {
        std::cout << parent.back()->data << "\n";

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left)
                current.push_back((*itr)->left);
            if ((*itr)->right)
                current.push_back((*itr)->right);
        }

        parent.swap(current);
        current.clear();
    }
}

void View_utility::right_view_recursive()
{
    int curr_level = 1;
    int last_printed_level = 0;

    // print the right view
    _right_view_recursive_util(_root, curr_level, last_printed_level);
}

void View_utility::_right_view_recursive_util(node *currNodePtr, int curr_level, int &last_printed_level)
{
    // if currNodePtr is null, there is nothing to do
    if (currNodePtr == nullptr)
    {
        return;
    }

    if (last_printed_level < curr_level)
    {
        std::cout << currNodePtr->data << " \n";
        last_printed_level = curr_level;
    }

    _right_view_recursive_util(currNodePtr->right, curr_level + 1, last_printed_level);
    _right_view_recursive_util(currNodePtr->left, curr_level + 1, last_printed_level);
}

int main()
{

    View_utility obj;

    // CASE - 1
    // obj.insert(15);
    // obj.insert(5);
    // obj.insert(1);
    // obj.insert(10);
    // obj.insert(14);

    // CASE -2
    obj.insert(1000);
    obj.insert(500);
    obj.insert(700);
    obj.insert(300);
    obj.insert(400);
    obj.insert(360);
    obj.insert(330);
    obj.insert(2000);
    obj.insert(3000);
    obj.insert(2500);
    obj.insert(2700);

    // obj.view_in_order();

    obj.right_view_iterative();

    obj.right_view_recursive();

    return 0;
}