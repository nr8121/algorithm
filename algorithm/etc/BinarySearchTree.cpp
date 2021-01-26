#include <iostream>

struct BNode
{
    BNode* right = nullptr;
    BNode* left = nullptr;
    int value;
};


struct BinaryTree
{
    BNode* root = nullptr;
};

BNode* find(BinaryTree* tree, int n)
{
    if(tree->root == nullptr) return nullptr;
    BNode* cur = tree->root;
    while(1)
    {
        if(cur->value == n)
        {
            return cur;
        }
        else if(cur->value < n)
        {
            if(cur->right != nullptr)
            {
                cur = cur->right;
            }
            else
            {
                return nullptr;
            }
            
        }
        else
        {
            if(cur->left != nullptr)
            {
                cur = cur->left;
            }
            else
            {
                return nullptr;
            }
        }
    }
}
void insertBTNode(BinaryTree* tree, int n)
{
    BNode* node = new BNode;
    node->value = n;
    if(tree->root == nullptr)
    {
        tree->root = node;
    }
    else
    {
        BNode* cur = tree->root;
        
        while(1)
        {
            if(cur->value <= node->value)
            {
                if(cur->right != nullptr)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = node;
                    break;
                }
                
            }
            else
            {
                if(cur->left != nullptr)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = node;
                    break;
                }
            }
        }
    }
}
bool deleteBTNode(BinaryTree* tree, int n)
{
    BNode* fNode;
    BNode* parentNode = nullptr;
    if(tree->root != nullptr)
    {
        BNode* cur = tree->root;
        parentNode = nullptr;
        //find
        while(1)
        {
            if(cur->value == n)
            {
                fNode = cur;
                break;
            }
            else if(cur->value < n)
            {
                if(cur->right != nullptr)
                {
                    parentNode = cur;
                    cur = cur->right;
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                if(cur->left != nullptr)
                {
                    parentNode = cur;
                    cur = cur->left;
                }
                else
                {
                    return false;
                }
            }
        }
        // printf("find %d\n", fNode->value);

        if(fNode->right != nullptr && fNode->left != nullptr)
        {
            cur = fNode->left;
            BNode* parentNode2 = nullptr;
            while(cur->right)
            {
                parentNode2 = cur;
                cur = cur->right;
            }

            fNode->value = cur->value;
            if(parentNode2)
            {
                parentNode2->right = nullptr;
            }
            else
            {
                parentNode2->left = nullptr;
            }
            
            

        }
        else if(fNode->right == nullptr && fNode->left == nullptr)
        {
            if(!parentNode)
            {
                tree->root = nullptr;
            }
            else if(parentNode->right == fNode)
            {
                parentNode->right = nullptr;
            }
            else
            {
                parentNode->left = nullptr;
            }
        }
        else if(fNode->right != nullptr)
        {
            if(!parentNode)
            {
                tree->root = fNode->right;
            }
            else if(parentNode->right == fNode)
            {
                parentNode->right = fNode->right;
            }
            else
            {
                parentNode->left = fNode->right;
            }
            
        }
        else
        {
            if(!parentNode)
            {
                tree->root = fNode->left;
            }
            else if(parentNode->right == fNode)
            {
                parentNode->right = fNode->left;
            }
            else
            {
                parentNode->left = fNode->left;
            }
        }
    }
    delete fNode;
    return true;

}
void inorder(BNode* node)
{
    if(node->left != nullptr)
        inorder(node->left);
    printf("%d ",node->value);
    if(node->right != nullptr)
        inorder(node->right);
}
void printBinaryTree(BinaryTree* tree)
{
    if(tree->root != nullptr)
        inorder(tree->root);
    printf("\n");
}



int main(){
	BinaryTree bt;
    insertBTNode(&bt, 3);
    insertBTNode(&bt, 1);
    insertBTNode(&bt, 34);
    insertBTNode(&bt, 315);
    insertBTNode(&bt, 55);
    insertBTNode(&bt, 3262);
    insertBTNode(&bt, 326);
    insertBTNode(&bt, 567);
    insertBTNode(&bt, 333);
    deleteBTNode(&bt, 1);
    deleteBTNode(&bt, 3262);
    deleteBTNode(&bt, 3);

    
    
    
    printBinaryTree(&bt);
	return 0;
}
