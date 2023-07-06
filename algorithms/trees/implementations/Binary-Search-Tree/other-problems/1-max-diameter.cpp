#include <iostream>
#include <list>

struct node
{
    int data;
    node *left;
    node *right;

    node(int v) : data(v),
                  left(nullptr),
                  right(nullptr){};

    node() = delete;
};

class Tree
{
public:
    typedef std::list<std::list<node *>> _adj_list_t;
    typedef std::list<node *> _list_t;

private:
    node *_root;

    node *_insertUtility(node *, int);
    node *_removeUtility(node *, int);
    void inOrder(node *);

    _adj_list_t _build_adj_list();

public:
    Tree() { _root = nullptr; };

    void insert(int);

    void remove(int);

    node *findMin(node *);

    void print_inOrder();

    void max_diameter_level();
};

void Tree::inOrder(node *currNodePtr)
{
    if (currNodePtr)
    {
        inOrder(currNodePtr->left);
        std::cout << currNodePtr->data << " : ";
        inOrder(currNodePtr->right);
    }
}

void Tree::print_inOrder()
{
    std::cout << "\nin-order-view -> ";
    inOrder(_root);
}

node *Tree::_insertUtility(node *currNodePtr, int value)
{
    if (!currNodePtr)
    {
        return new node(value);
    }

    else if (value < currNodePtr->data)
    {
        currNodePtr->left = _insertUtility(currNodePtr->left, value);
    }

    else // if (value > currNodePtr->data)
    {
        currNodePtr->right = _insertUtility(currNodePtr->right, value);
    }

    return currNodePtr;
}

void Tree::insert(int value)
{
    _root = _insertUtility(_root, value);
}

node *Tree::_removeUtility(node *currNodePtr, int value)
{
    if (!currNodePtr)
    {
        return nullptr;
    }

    if (value < currNodePtr->data)
    {
        currNodePtr->left = _removeUtility(currNodePtr->left, value);
    }

    else if (value > currNodePtr->data)
    {
        currNodePtr->right = _removeUtility(currNodePtr->right, value);
    }

    else
    {
        if (currNodePtr->left == nullptr && currNodePtr->right == nullptr)
        {
            delete currNodePtr;
            return nullptr;
        }

        else if (currNodePtr->left != nullptr && currNodePtr->right == nullptr)
        {
            node *left_sub_tree = currNodePtr->left;
            delete currNodePtr;
            return left_sub_tree;
        }

        else if (currNodePtr->left == nullptr && currNodePtr->right != nullptr)
        {
            node *right_sub_tree = currNodePtr->right;
            delete currNodePtr;
            return right_sub_tree;
        }

        else
        {
            node *nextMin = findMin(currNodePtr->right);
            currNodePtr->data = nextMin->data;
            currNodePtr->right = _removeUtility(currNodePtr->right, nextMin->data);
        }
    }
}

void Tree::remove(int value)
{
    _root = _removeUtility(_root, value);
}

node *Tree::findMin(node *currNodePtr)
{
    while (currNodePtr && currNodePtr->left)
    {
        currNodePtr = currNodePtr->left;
    }
    return currNodePtr;
}

void Tree::max_diameter_level()
{
    if (!_root)
        std::cout << "\ninsufficient data in tree\n";

    _adj_list_t list = _build_adj_list();

    int max = -9999;

    for (auto l_itr = list.begin(); l_itr != list.end(); ++l_itr)
    {
        max = std::max((int)(*l_itr).size(), max);
    }

    if (max != -9999)
        std::cout << "Max Diamter is:" << max;
}

Tree::_adj_list_t Tree::_build_adj_list()
{
    _adj_list_t resultant_adj_list;

    _list_t plist;
    _list_t list;

    plist.push_back(_root);

    while (!plist.empty())
    {
        for (auto itr = plist.begin(); itr != plist.end(); ++itr)
        {
            if ((*itr)->left != nullptr)
                list.push_back((*itr)->left);

            if ((*itr)->right != nullptr)
                list.push_back((*itr)->right);
        }

        resultant_adj_list.push_back(plist);
        plist.swap(list);
        list.clear();
    }

    return resultant_adj_list;
}

int main()
{
    Tree obj;

    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    // obj.print_inOrder();

    // obj.remove(3);
    // obj.print_inOrder();

    // obj.insert(3);
    obj.insert(11);
    obj.insert(2);
    obj.insert(4);
    obj.max_diameter_level();

    // obj.insert(6);
    // obj.print_inOrder();

    // obj.remove(7);
    // obj.print_inOrder();

    // obj.insert(7);
    // obj.print_inOrder();

    // obj.remove(3);
    // obj.remove(5);
    // obj.remove(6);
    // obj.print_inOrder();

    // obj.remove(7);
    // obj.remove(11);
    // obj.print_inOrder();

    return 0;
}