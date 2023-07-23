#include <iostream>
#include <queue>
#include <list>
#include <sstream>
#include <fstream>

/*
Each BST node has data, left child, right child.
*/

struct TreeNode
{
    int node_data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int newData) : node_data(newData),
                            left(nullptr),
                            right(nullptr) {}
};

// BST interface
class BSTree
{
public:
    BSTree();
    void insert(int);
    void remove(int);
    void DepthView();
    TreeNode *findSmallest(TreeNode *);

    TreeNode *root;

private:
    virtual TreeNode *insertUtility(int, TreeNode *);
    virtual TreeNode *removeUtility(int, TreeNode *);
    std::list<std::list<TreeNode *>> DepthViewUtility(TreeNode *);
};

BSTree::BSTree() : root(nullptr) {}

/*--------------------------------------------- Insert Element into the tree */
void BSTree::insert(int newData)
{
    root = insertUtility(newData, root);
}

TreeNode *BSTree::insertUtility(int newData, TreeNode *ptr)
{
    if (!ptr) // no node present, create a new and return
    {
        return new TreeNode(newData);
    }

    // go to left subtree
    if (newData < ptr->node_data)
    {
        ptr->left = insertUtility(newData, ptr->left);
    }

    else //(newData > ptr->node_data) // go to right subtree
    {
        ptr->right = insertUtility(newData, ptr->right);
    }

    return ptr;
}

/* ---------------------------------------------Delete element from AVL tree */
void BSTree::remove(int newData)
{
    root = removeUtility(newData, root);
}

TreeNode *BSTree::removeUtility(int data, TreeNode *curr_ptr)
{
    // if curr_ptr is null
    if (curr_ptr == nullptr)
        return curr_ptr;

    // if delete node has less than current node's value, go left
    else if (data < curr_ptr->node_data)
        curr_ptr->left = removeUtility(data, curr_ptr->left);

    // if  delete node has greater than current node's value, go right
    else if (data > curr_ptr->node_data)
        curr_ptr->right = removeUtility(data, curr_ptr->right);

    // if no condition matches, then
    // it is the curr_ptr that has to be deleted
    else
    {
        // a leaf node
        if (curr_ptr->left == nullptr && curr_ptr->right == nullptr)
        {
            delete curr_ptr;
            return nullptr;
        }

        // node with a left subtree
        else if (curr_ptr->left != nullptr && curr_ptr->right == nullptr)
        {
            TreeNode *ptrToLeftSubtree = curr_ptr->left;
            delete curr_ptr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (curr_ptr->left == nullptr && curr_ptr->right != nullptr)
        {
            TreeNode *ptrToRightSubtree = curr_ptr->right;
            delete curr_ptr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            TreeNode *minNode = findSmallest(curr_ptr->right);

            // copy its data
            curr_ptr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            curr_ptr->right = removeUtility(minNode->node_data, curr_ptr->right);
        }
    }
    return curr_ptr;
}

/* ---------------------------------------------bird view utility */
void BSTree::DepthView()
{
    std::cout << std::endl
              << "root=L@1\n";

    // call utility that creates a list
    std::list<std::list<TreeNode *>> depthViewList = DepthViewUtility(root);

    int levelCount = 1;
    // then print the list
    for (std::list<std::list<TreeNode *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        std::cout << "\tL@" << levelCount << " -> ";
        for (std::list<TreeNode *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data << " ";
        }
        std::cout << std::endl;
        ++levelCount;
    }

    std::cout << std::endl;
}

std::list<std::list<TreeNode *>> BSTree::DepthViewUtility(TreeNode *root)
{
    // create a new list of parent and current that
    std::list<std::list<TreeNode *>> DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    std::list<TreeNode *> current;
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        std::list<TreeNode *> parent = current;
        current.resize(0);

        for (std::list<TreeNode *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
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
// params : TreeNode * T
TreeNode *BSTree::findSmallest(TreeNode *curr_ptr)
{
    while (curr_ptr && curr_ptr->left) // validation for curr_ptr deals with nullptr also
        curr_ptr = curr_ptr->left;

    return curr_ptr;
}

class Codec
{
public:
    std::string serialize(TreeNode *root)
    {
        std::stringstream obj;
        encode(root, obj);
        return obj.str();
    }

    void encode(TreeNode *root, std::stringstream &obj)
    {
        if (root == nullptr)
        {
            obj << "NULL ";
            return;
        }

        obj << root->node_data << " ";

        encode(root->left, obj);
        encode(root->right, obj);
    }

    TreeNode *deserialize(std::stringstream &obj)
    {
        return decode(obj);
    }

    TreeNode *decode(std::stringstream &obj)
    {
        std::string currentToken = "";
        obj >> currentToken;

        if (currentToken == "NULL")
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(currentToken));

        root->left = decode(obj);
        root->right = decode(obj);

        return root;
    }
};

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    BSTree *tree = new BSTree();

    // INSERT & BALANCE TEST

    tree->insert(7);
    tree->insert(5);
    tree->insert(3);
    tree->insert(9);
    tree->insert(11);

    // // REMOVE & BALANCE TEST

    tree->insert(1);
    tree->remove(7);

    tree->DepthView();

    // SERIALIZATION & PERSISTENCE

    Codec seder;
    std::ofstream outFile;

    outFile.open("TreeText.txt", std::ios::app);
    outFile << seder.serialize(tree->root);
    outFile.close();

    std::ifstream inFile;
    std::stringstream ss;

    inFile.open("TreeText.txt", std::ios::in);
    ss << inFile.rdbuf();
    std::cout << seder.serialize(seder.deserialize(ss));
    inFile.close();

    std::cout << std::endl;
    return 0;
}
