/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v1;
    vector<int>v2;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        inorder1(p);
        inorder2(q);
        vector<int>::iterator it1;
        vector<int>::iterator it2;
        // compare both vectors
        for(it1=v1.begin(),it2=v2.begin(); it1!=v1.end(),it2!=v2.end();it1++,it2++)
        {
            if(*it1!=*it2)
            {
                return false;
            }
        }
        return true;
    }
    void inorder1(TreeNode *p)// do inorder of tree 1 and put -1 where we get null
    {
        if(p!=NULL)
        {
            v1.push_back(p->val);
            inorder1(p->left);
            inorder1(p->right);
        }
        else
        {
            v1.push_back(-1);
        }
        
    }
    void inorder2(TreeNode *q)// do inorder of tree 2 and put -1 where we get null
    {
        if(q!=NULL)
        {
            v2.push_back(q->val);
            inorder2(q->left);
            inorder2(q->right);
        }
        else
        {
            v2.push_back(-1);
        }
        
    }
};
