#include <iostream>
#include <map>
#include <queue>

//

struct node
{
    int data;
    int h_dist = 0;
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
    void topview();

private:
};

void View_utility::topview()
{
    if (_root == nullptr)
        return;

    std::queue<node *> queue;
    std::map<int, int> map;

    node *currNode = _root;
    int localHDist;

    queue.push(currNode);
    while (!queue.empty())
    {
        localHDist = currNode->h_dist;

        map[localHDist] = currNode->data;

        if (currNode->left != nullptr)
        {
            currNode->left->h_dist = localHDist - 1;
            queue.push(currNode->left);
        }
        if (currNode->right != nullptr)
        {
            currNode->right->h_dist = localHDist + 1;
            queue.push(currNode->right);
        }

        queue.pop();
        currNode = queue.front();
    }

    for (const auto &i : map)
    {
        std::cout << i.second << std::endl;
    }
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
    obj.insert(10);
    obj.insert(5);
    obj.insert(15);
    obj.insert(3);
    obj.insert(7);
    obj.insert(13);
    obj.insert(17);
    obj.insert(1);
    obj.insert(11);
    obj.insert(16);
    // obj.insert(2500);
    // obj.insert(2700);

    // obj.view_in_order();
    obj.topview();

    return 0;
}
