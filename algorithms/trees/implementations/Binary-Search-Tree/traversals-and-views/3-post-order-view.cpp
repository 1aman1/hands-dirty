#include <iostream>
#include <queue>
#include <list>

struct node_t
{
    int data;
    node_t *left;
    node_t *right;

    node_t() = delete;

    node_t(int newData) : data(newData),
                          left(nullptr),
                          right(nullptr) {}
};

class Tree
{
public:
    Tree();

    void
    insert(int);

protected:
    node_t *root;

    virtual node_t *
    _insertUtil(node_t *, int);
};

Tree::Tree() : root(nullptr) {}

void Tree::insert(int newData)
{
    root = _insertUtil(root, newData);
}

node_t *Tree::_insertUtil(node_t *currNodePtr, int newData)
{
    if (!currNodePtr)
        return new node_t(newData);

    if (newData < currNodePtr->data)
        currNodePtr->left = _insertUtil(currNodePtr->left, newData);

    else
        currNodePtr->right = _insertUtil(currNodePtr->right, newData);

    return currNodePtr;
}

//______SOLUTION_______//

class Views : public Tree
{
private:
    void _postOrderView(node_t *);

public:
    void postOrderView();
};

void Views::postOrderView()
{
    _postOrderView(root);
}

void Views::_postOrderView(node_t *currNodePtr)
{
    if (!currNodePtr)
    {
        return;
    }

    _postOrderView(currNodePtr->left);

    _postOrderView(currNodePtr->right);

    std::cout << currNodePtr->data << "\t";
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Views *tobj = new Views();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(5);
    tobj->insert(1);
    tobj->insert(9);
    tobj->insert(10);
    tobj->insert(11);

    tobj->postOrderView();

    return 0;
}
