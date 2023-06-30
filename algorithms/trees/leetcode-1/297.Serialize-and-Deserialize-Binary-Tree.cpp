class Codec
{
public:
    string serialize(TreeNode *root)
    {
        stringstream obj;
        encode(root, obj);
        return obj.str();
    }

    void encode(TreeNode *root, stringstream &obj)
    {
        if (root == nullptr)
        {
            obj << "NULL ";
            return;
        }

        obj << root->val << " ";

        encode(root->left, obj);
        encode(root->right, obj);
    }

    TreeNode *deserialize(string data)
    {
        stringstream obj(data);
        return decode(obj);
    }

    TreeNode *decode(stringstream &obj)
    {
        string currentToken = "";
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