#include <iostream>
#include <queue>
#include <list>

/*
node has data, left child, right child & parent ptr too.
*/

struct treeNode
{
    int node_data;

    treeNode *left;
    treeNode *right;

    treeNode *parent;

    treeNode(int newdata) : node_data(newdata),
                            left(nullptr),
                            right(nullptr),
                            parent(nullptr) {}
};

class tree
{
public:
    treeNode *root;

    tree() : root(nullptr){};

    treeNode *insert(int, treeNode *);
    treeNode *remove(int, treeNode *);

    treeNode *findSmallest(treeNode *currPtr);

    // view
    void DepthView(treeNode *);
    std::list<std::list<treeNode *>> DepthViewUtility(treeNode *);
};

void tree::DepthView(treeNode *currPtr)
{
    // call utility that creates a list
    std::list<std::list<treeNode *>> depthViewList = DepthViewUtility(currPtr);

    // then print the list
    for (std::list<std::list<treeNode *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (std::list<treeNode *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data;
            // if ((*nestItr)->parent != nullptr)
            // std::cout << "^parent" << (*nestItr)->parent->node_data << " ";
        }
        std::cout << std::endl;
    }
}

std::list<std::list<treeNode *>> tree::DepthViewUtility(treeNode *root)
{
    // create a new list of parent and current that
    std::list<std::list<treeNode *>> DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    std::list<treeNode *> current;
    current.push_back(root);

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

treeNode *tree::insert(int newdata, treeNode *ptr)
{
    if (!ptr)
    {
        return new treeNode(newdata);
    }
    // ptr here would be the parent of the newNode when put successfully
    // ptr can be assigned as the parent of newNode
    if (newdata < ptr->node_data)
    {

        treeNode *left_child_node = insert(newdata, ptr->left);
        ptr->left = left_child_node;

        left_child_node->parent = ptr;
    }

    else //(newdata > ptr->node_data)
    {
        treeNode *right_child_node = insert(newdata, ptr->right);
        ptr->right = right_child_node;
        right_child_node->parent = ptr;
    }

    return ptr;
}

treeNode *tree::findSmallest(treeNode *currPtr)
{
    // validation for currPtr deals with nullptr also
    while (currPtr && currPtr->left)
        currPtr = currPtr->left;

    return currPtr;
}

treeNode *tree::remove(int item, treeNode *currPtr)
{
    // if it is null
    if (currPtr == nullptr)
        return currPtr;

    // if value to delete is less than current node's value, go left
    else if (item < currPtr->node_data)
        currPtr->left = remove(item, currPtr->left);

    // if value to delete is greater than current node's value, go right
    else if (item > currPtr->node_data)
        currPtr->right = remove(item, currPtr->right);

    // if no condition matches, then
    // it is the currPtr that has to be deleted
    else
    {
        // a leaf node
        if (currPtr->left == nullptr && currPtr->right == nullptr)
        {
            delete currPtr;
            return nullptr;
        }

        // node with a left subtree
        else if (currPtr->left != nullptr && currPtr->right == nullptr)
        {
            treeNode *ptrToLeftSubtree = currPtr->left;
            delete currPtr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (currPtr->left == nullptr && currPtr->right != nullptr)
        {
            treeNode *ptrToRightSubtree = currPtr->right;
            delete currPtr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            treeNode *minNode = findSmallest(currPtr->right);

            // copy its data
            currPtr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            currPtr->right = remove(minNode->node_data, currPtr->right);
        }
    }
    return currPtr;
}

int main()
{
    std::cout << __FILE__ << std::endl;

    tree obj;

    obj.root = obj.insert(5, obj.root);
    obj.root = obj.insert(3, obj.root);
    obj.root = obj.insert(7, obj.root);
    obj.root = obj.insert(4, obj.root);
    obj.root = obj.insert(6, obj.root);
    obj.root = obj.insert(2, obj.root);
    obj.root = obj.insert(8, obj.root);

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    obj.remove(3, obj.root);

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    return 0;
}