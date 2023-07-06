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

void Tree::_in_order(node *currNodePtr)
{
    if (currNodePtr)
    {
        _in_order(currNodePtr->left);
        std::cout << currNodePtr->data << " : ";
        _in_order(currNodePtr->right);
    }
}

void Tree::insert(int newData)
{
    _root = _insertUtility(_root, newData);
}

node *
Tree::_insertUtility(node *currNodePtr, int newData)
{
    if (currNodePtr == nullptr)
        return new node(newData);

    else if (newData < currNodePtr->data)
        currNodePtr->left = _insertUtility(currNodePtr->left, newData);
    else
        currNodePtr->right = _insertUtility(currNodePtr->right, newData);

    return currNodePtr;
}

//______SOLUTION_______//

class View_utility : public Tree
{

public:
    void
    left_view_iterative();

    void
    left_view_recursive();

private:
    void
    _left_view_recursive_util(node *, int, int &);
};

void View_utility::left_view_iterative()
{
    list parent = {_root};
    list children;

    std::cout << "Left view : \n";

    while (!parent.empty())
    {
        std::cout << parent.front()->data << "\n";

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left)
                children.push_back((*itr)->left);
            if ((*itr)->right)
                children.push_back((*itr)->right);
        }

        parent.swap(children);
        children.clear();
    }
}

void View_utility::left_view_recursive()
{
    int curr_level = 1;
    int last_printed_level = 0;

    // print the left view
    _left_view_recursive_util(_root, curr_level, last_printed_level);
}

void View_utility::_left_view_recursive_util(node *currNodePtr, int curr_level, int &last_printed_level)
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

    _left_view_recursive_util(currNodePtr->left, curr_level + 1, last_printed_level);
    _left_view_recursive_util(currNodePtr->right, curr_level + 1, last_printed_level);
}

int main()
{

    View_utility obj;

    // CASE - 1
    obj.insert(15);
    obj.insert(5);
    obj.insert(1);
    obj.insert(10);
    obj.insert(14);

    // CASE -2
    // obj.insert(1000);
    // obj.insert(500);
    // obj.insert(700);
    // obj.insert(300);
    // obj.insert(400);
    // obj.insert(360);
    // obj.insert(330);
    // obj.insert(2000);
    // obj.insert(3000);
    // obj.insert(2500);
    // obj.insert(2700);

    // obj.view_in_order();

    // obj.left_view_iterative();

    obj.left_view_recursive();

    return 0;
}