#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


struct TreeNode *
insrtToBST(struct TreeNode *root, struct TreeNode *node)
{

  struct TreeNode *temp = root;

  if (temp == NULL) return node;

  if (temp->right || temp->left)
    {

      if(node->val < temp->val)
	{
	  temp = temp->left;
	}

      if (node->val > temp->val)
	{
	  temp = temp->right;
	}

      return insrtToBST(temp, node);
    }

  
  if(node->val < temp->val)
    {
      temp->left = node;
    }
  
  if (node->val > temp->val)
    {
      temp->right = node;
    }
  
    
  return root;
}

struct TreeNode *
bstFromPreorder(int *preorder, int preorderSize)
{
  struct TreeNode *root = NULL, *node;
  
  for (int i = 0; i < preorderSize; i++)
    {
      printf("%d\n", i);
      node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      node->val = preorder[i];
      node->right = NULL;
      node->left = NULL;
      root = insrtToBST(root, node);
    }

  return root;  

}


void
printBST(struct TreeNode *root)
{
  //
}


int
main()
{

  int preorder[6] = {8, 5, 1, 7, 10, 12};


  struct TreeNode *root = bstFromPreorder(preorder, 6);

}

