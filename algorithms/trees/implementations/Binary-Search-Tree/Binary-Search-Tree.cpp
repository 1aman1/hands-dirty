#include <iostream>
#include <queue>
#include <list>

/*
Each BST Node has data, left child, right child.
*/
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int newData) : data(newData),
                        left(nullptr),
                        right(nullptr) {}
};

typedef Node treeNode;
typedef std::list<treeNode *> listOfPNode;
typedef std::list<listOfPNode> listOflistOfPNode;

// BST interface
class BSTree
{
public:
    BSTree();
    void Insert(int);
    void Remove(int);
    void DepthView();
    treeNode *FindSmallest(treeNode *);
    int height();
    int size();

private:
    treeNode *_root;

    virtual treeNode *_InsertUtility(int, treeNode *);
    virtual treeNode *_RemoveUtility(int, treeNode *);
    int _SizeUtility(treeNode *);
    int _HeightUtility(treeNode *currNodePtr);
    listOflistOfPNode _DepthViewUtility(treeNode *);
};

BSTree::BSTree() : _root(nullptr) {}

/*--------------------------------------------- Insert Element into the tree */
void BSTree::Insert(int newData)
{
    _root = _InsertUtility(newData, _root);
}

treeNode *BSTree::_InsertUtility(int newData, treeNode *ptr)
{
    if (!ptr) // no treeNode present, create a new and return
    {
        return new treeNode(newData);
    }

    if (newData < ptr->data) // go to left subtree
    {
        ptr->left = _InsertUtility(newData, ptr->left);
    }

    else //(newData > ptr->data) // go to right subtree
    {
        ptr->right = _InsertUtility(newData, ptr->right);
    }

    return ptr;
}

/* ---------------------------------------------Delete element from tree */
void BSTree::Remove(int newData)
{
    _root = _RemoveUtility(newData, _root);
}

treeNode *BSTree::_RemoveUtility(int data, treeNode *currNodePtr)
{
    if (currNodePtr == nullptr) // if currNodePtr is null
    {
        return currNodePtr;
    }

    else if (data < currNodePtr->data) // if target is less than current treeNode's value, go left
    {
        currNodePtr->left = _RemoveUtility(data, currNodePtr->left);
    }

    else if (data > currNodePtr->data) // if target is greater than current treeNode's value, go right
    {
        currNodePtr->right = _RemoveUtility(data, currNodePtr->right);
    }

    // if no condition matches, meaning it's the currNodePtr that has to be deleted
    else
    {
        // a leaf treeNode
        if (currNodePtr->left == nullptr && currNodePtr->right == nullptr)
        {
            delete currNodePtr;
            return nullptr;
        }

        // treeNode with a left subtree
        else if (currNodePtr->left != nullptr && currNodePtr->right == nullptr)
        {
            treeNode *hookToLeftSubtree = currNodePtr->left;
            delete currNodePtr;
            return hookToLeftSubtree;
        }

        // treeNode with a right subtree
        else if (currNodePtr->left == nullptr && currNodePtr->right != nullptr)
        {
            treeNode *hookToRightSubtree = currNodePtr->right;
            delete currNodePtr;
            return hookToRightSubtree;
        }

        else
        {
            treeNode *mintreeNode = FindSmallest(currNodePtr->right);

            currNodePtr->data = mintreeNode->data;

            // reecursively call mintreeNode deletion in its subtree
            currNodePtr->right = _RemoveUtility(mintreeNode->data, currNodePtr->right);
        }
    }

    return currNodePtr;
}

/* ---------------------------------------------bird view utility */
void BSTree::DepthView()
{
    std::cout << std::endl
              << "_root=L@1\n";

    listOflistOfPNode depthViewList = _DepthViewUtility(_root);

    int levelCount = 1;

    for (listOflistOfPNode::iterator itrRow = depthViewList.begin();
         itrRow != depthViewList.end();
         ++itrRow)
    {
        std::cout << "\tL@" << levelCount << " -> ";

        for (listOfPNode::iterator itrCol = (*itrRow).begin();
             itrCol != (*itrRow).end();
             ++itrCol)
        {
            std::cout << (*itrCol)->data << " ";
        }

        ++levelCount;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

listOflistOfPNode BSTree::_DepthViewUtility(treeNode *_root)
{
    // create a new list of parent and current that
    listOflistOfPNode DepthViewList;

    // utility list to stash level treeNodes and then push into
    // DepthViewList before moving to next level
    std::list<treeNode *> current;
    current.push_back(_root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        std::list<treeNode *> parent = current;
        current.resize(0);

        for (std::list<treeNode *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
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

/* ---------------------------------------------to find the minimum value treeNode */
treeNode *BSTree::FindSmallest(treeNode *currNodePtr)
{
    while (currNodePtr && currNodePtr->left)
        currNodePtr = currNodePtr->left;

    return currNodePtr;
}

int BSTree::height()
{
    return _HeightUtility(_root);
}

int BSTree::_HeightUtility(treeNode *currNodePtr)
{
    if (currNodePtr == nullptr)
        return 0;

    int left = _HeightUtility(currNodePtr->left);
    int right = _HeightUtility(currNodePtr->right);

    return std::max(left, right) + 1;
}

int BSTree::size()
{
    return _SizeUtility(_root);
}

int BSTree::_SizeUtility(treeNode *ptr)
{
    if (ptr != nullptr)
    {
        return _SizeUtility(ptr->left) +
               _SizeUtility(ptr->right) + 1;
    }
    return 0;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    BSTree *bst_obj = new BSTree();

    // INSERT & BALANCE TEST

    bst_obj->Insert(7);
    bst_obj->DepthView();

    bst_obj->Insert(5);
    bst_obj->DepthView();

    bst_obj->Insert(3);
    bst_obj->DepthView();

    bst_obj->Insert(9);
    bst_obj->DepthView();

    bst_obj->Insert(11);
    bst_obj->DepthView();

    // REMOVE & BALANCE TEST

    bst_obj->Insert(1);
    bst_obj->DepthView();

    bst_obj->Remove(7);
    bst_obj->DepthView();

    std::cout << "height " << bst_obj->height() << std::endl;
    std::cout << "size " << bst_obj->size() << std::endl;

    return 0;
}