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
    node_t *_root;

    virtual node_t *
    _insertUtil(node_t *, int);
};

Tree::Tree() : _root(nullptr) {}

void Tree::insert(int newData)
{
    _root = _insertUtil(_root, newData);
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
public:
    void level_list_view();
};

void Views::level_list_view()
{
    std::queue<node_t *> queue;

    node_t *tmp = _root;
    queue.push(tmp);

    while (!queue.empty())
    {
        tmp = queue.front();
        queue.pop();

        std::cout << tmp->data << "\t";

        if (tmp->left)
            queue.push(tmp->left);

        if (tmp->right)
            queue.push(tmp->right);
    }
    std::cout << std::endl;

    clear(queue);
}

void clear(std::queue<node_t *> &q)
{
    std::queue<node_t *> empty;
    std::swap(q, empty);
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Views *tobj = new Views();

    tobj->insert(7);
    tobj->insert(5);
    tobj->insert(3);
    tobj->insert(9);
    tobj->insert(11);

    tobj->level_list_view();

    return 0;
}
