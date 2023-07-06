#include <iostream>
#include <queue>
#include <list>

/*
Each BST node has data, left child, right child.
*/

struct treeNode
{
    int node_data;
    treeNode *left;
    treeNode *right;

    treeNode(int newData) : node_data(newData),
                            left(nullptr),
                            right(nullptr) {}
};

// BST interface
class BSTree
{
public:
    typedef std::list<std::list<treeNode *>> adj_list;
    typedef std::list<treeNode *> list;

public:
    BSTree();

    void
    insert(int);

    void
    remove(int);

    void
    DepthView();

    treeNode *
    find_smallest(treeNode *);

private:
    treeNode *root;

    virtual treeNode *
    _insert_utility(int, treeNode *);

    virtual treeNode *
    _remove_utility(int, treeNode *);

    adj_list
    _depth_view_utility(treeNode *);
};

// AVL interface : extended BST class to provide AVL behaviour
class AVLTree : public BSTree
{
public:
    AVLTree();

private:
    treeNode *
    _insert_utility(int, treeNode *);

    treeNode *
    _remove_utility(int, treeNode *);

    // utilities
    int
    height(treeNode *);

    int
    height_difference(treeNode *);

    treeNode *
    balance(treeNode *);

    treeNode *ll_rotation(treeNode *);
    treeNode *lr_rotation(treeNode *);
    treeNode *rl_rotation(treeNode *);
    treeNode *rr_rotation(treeNode *);
};

BSTree::BSTree() : root(nullptr) {}

AVLTree::AVLTree() {}

/*--------------------------------------------- Insert Element into the tree */
void BSTree::insert(int newData)
{
    root = _insert_utility(newData, root);
}

treeNode *BSTree::_insert_utility(int newData, treeNode *ptr)
{
    if (!ptr) // no node present, create a new and return
    {
        return new treeNode(newData);
    }

    // go to left subtree
    if (newData < ptr->node_data)
    {
        ptr->left = _insert_utility(newData, ptr->left);
    }

    else //(newData > ptr->node_data) // go to right subtree
    {
        ptr->right = _insert_utility(newData, ptr->right);
    }

    return ptr;
}

/* ---------------------------------------------Delete element from AVL tree */
void BSTree::remove(int newData)
{
    root = _remove_utility(newData, root);
}

treeNode *
BSTree::_remove_utility(int data, treeNode *currNodePtr)
{
    // if currNodePtr is null
    if (currNodePtr == nullptr)
        return currNodePtr;

    // if delete node has less than current node's value, go left
    else if (data < currNodePtr->node_data)
        currNodePtr->left = _remove_utility(data, currNodePtr->left);

    // if  delete node has greater than current node's value, go right
    else if (data > currNodePtr->node_data)
        currNodePtr->right = _remove_utility(data, currNodePtr->right);

    // if no condition matches, then
    // it is the currNodePtr that has to be deleted
    else
    {
        // a leaf node
        if (currNodePtr->left == nullptr && currNodePtr->right == nullptr)
        {
            delete currNodePtr;
            return nullptr;
        }

        // node with a left subtree
        else if (currNodePtr->left != nullptr && currNodePtr->right == nullptr)
        {
            treeNode *ptrToLeftSubtree = currNodePtr->left;
            delete currNodePtr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (currNodePtr->left == nullptr && currNodePtr->right != nullptr)
        {
            treeNode *ptrToRightSubtree = currNodePtr->right;
            delete currNodePtr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            treeNode *minNode = find_smallest(currNodePtr->right);

            // copy its data
            currNodePtr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            currNodePtr->right = _remove_utility(minNode->node_data, currNodePtr->right);
        }
    }
    return currNodePtr;
}

/* ---------------------------------------------bird view utility */
void BSTree::DepthView()
{
    std::cout << "\nroot=L@1\n";

    // call utility that creates a list
    adj_list depthViewList = _depth_view_utility(root);

    int levelCount = 1;

    // print the list
    for (auto itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        std::cout << "\tL@" << levelCount << " -> ";
        for (auto nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data << " ";
        }
        std::cout << std::endl;
        ++levelCount;
    }

    std::cout << std::endl;
}

BSTree::adj_list
BSTree::_depth_view_utility(treeNode *root)
{
    // create a new list of parent and current that
    adj_list DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    list current;
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        list parent = current;
        current.resize(0);

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left)
            {
                current.push_back((*itr)->left);
            }
            if ((*itr)->right)
            {
                current.push_back((*itr)->right);
            }
        }
    }
    return DepthViewList;
}

/* ---------------------------------------------to find the minimum value node */
// params : treeNode * T
treeNode *BSTree::find_smallest(treeNode *currNodePtr)
{
    while (currNodePtr && currNodePtr->left) // validation for currNodePtr deals with nullptr also
        currNodePtr = currNodePtr->left;

    return currNodePtr;
}

// AVL members here
/*--------------------------------------------All Rotations for Balancing AVL Tree */
treeNode *AVLTree::rl_rotation(treeNode *parent_ptr)
{
    parent_ptr->right = ll_rotation(parent_ptr->right);

    return rr_rotation(parent_ptr);
}

treeNode *AVLTree::rr_rotation(treeNode *parent_ptr)
{
    treeNode *parents_right_subtree = parent_ptr->right;

    parent_ptr->right = parents_right_subtree->left;

    parents_right_subtree->left = parent_ptr;

    return parents_right_subtree;
}

treeNode *AVLTree::lr_rotation(treeNode *parent_ptr)
{
    parent_ptr->left = rr_rotation(parent_ptr->left);

    return ll_rotation(parent_ptr);
}

treeNode *AVLTree::ll_rotation(treeNode *parent_ptr)
{
    // hold left subtree
    treeNode *parents_left_subtree = parent_ptr->left;

    parent_ptr->left = parents_left_subtree->right;

    parents_left_subtree->right = parent_ptr;

    return parents_left_subtree;
}

/*---------------------------------------------- Balancing AVL Tree */
treeNode *AVLTree::balance(treeNode *currNodePtr)
{
    int balance_factor = height_difference(currNodePtr);

    if (balance_factor > 1) // test which subtree is heavier  left or right
    {
        // left subtree is heavy

        // test whether LL rotation is needed or LR
        if (height_difference(currNodePtr->left) > 0) // LL
            currNodePtr = ll_rotation(currNodePtr);
        else // LR
            currNodePtr = lr_rotation(currNodePtr);
    }
    if (balance_factor < -1)
    {
        // right subtree is heavy
        if (height_difference(currNodePtr->right) > 0)
            currNodePtr = rl_rotation(currNodePtr);
        else
            currNodePtr = rr_rotation(currNodePtr);
    }

    return currNodePtr;
}

/*--------------------------------------------- Height Difference  */
int AVLTree::height_difference(treeNode *ptr)
{
    return (height(ptr->left) - height(ptr->right));
}

/*------------------------------------------ Height of AVL Tree */
int AVLTree::height(treeNode *ptr)
{
    if (!ptr)
        return 0;
    else
    {
        // heights of left and right subtrees
        int leftHeight = (ptr == nullptr ? 0 : height(ptr->left));
        int rightHeight = (ptr == nullptr ? 0 : height(ptr->right));

        return (
            (leftHeight > rightHeight
                 ? leftHeight
                 : rightHeight) +
            1);
    }
}

/*--------------------------------------------- Insert Element into the tree */
// params : value
treeNode *AVLTree::_insert_utility(int newData, treeNode *ptr)
{
    if (!ptr) // no node present, create a new and return
    {
        return new treeNode(newData);
    }

    // go to left subtree
    if (newData < ptr->node_data)
    {
        ptr->left = _insert_utility(newData, ptr->left);
        ptr = balance(ptr);
    }

    else //(newData > ptr->node_data) // go to right subtree
    {
        ptr->right = _insert_utility(newData, ptr->right);
        ptr = balance(ptr);
    }

    return ptr;
}

/* ---------------------------------------------Delete element from AVL tree */
// params : value to remove
treeNode *AVLTree::_remove_utility(int data, treeNode *currNodePtr)
{
    // if currNodePtr is null
    if (currNodePtr == nullptr)
        return currNodePtr;

    // if delete node has less than current node's value, go left
    else if (data < currNodePtr->node_data)
        currNodePtr->left = _remove_utility(data, currNodePtr->left);

    // if  delete node has greater than current node's value, go right
    else if (data > currNodePtr->node_data)
        currNodePtr->right = _remove_utility(data, currNodePtr->right);

    // if no condition matches, then
    // it is the currNodePtr that has to be deleted
    else
    {
        // a leaf node
        if (currNodePtr->left == nullptr && currNodePtr->right == nullptr)
        {
            delete currNodePtr;
            currNodePtr = nullptr;
        }

        // node with a left subtree
        else if (currNodePtr->left != nullptr && currNodePtr->right == nullptr)
        {
            treeNode *tmp = currNodePtr;
            currNodePtr = currNodePtr->left;
            delete tmp;
        }

        // node with a right subtree
        else if (currNodePtr->left == nullptr && currNodePtr->right != nullptr)
        {
            treeNode *tmp = currNodePtr;
            currNodePtr = currNodePtr->right;
            delete tmp;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            treeNode *minNode = find_smallest(currNodePtr->right);

            // copy its data
            currNodePtr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            currNodePtr->right = _remove_utility(minNode->node_data, currNodePtr->right);
        }
    }

    if (currNodePtr)
        currNodePtr = balance(currNodePtr);
    return currNodePtr;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    BSTree *bst_obj = new BSTree();

    // INSERT & BALANCE TEST
    bst_obj = new AVLTree();

    bst_obj->insert(7);
    std::cout << "insert 7";
    bst_obj->DepthView();

    bst_obj->insert(5);
    std::cout << "insert 5";
    bst_obj->DepthView();

    AVLTree *avl_obj = dynamic_cast<AVLTree *>(bst_obj);

    avl_obj->insert(3);
    std::cout << "insert 3";
    avl_obj->DepthView();

    // // REMOVE & BALANCE TEST

    avl_obj->insert(1);
    std::cout << "insert 1";
    avl_obj->DepthView();

    avl_obj->remove(7);
    std::cout << "remove 7";
    avl_obj->DepthView();

    return 0;
}