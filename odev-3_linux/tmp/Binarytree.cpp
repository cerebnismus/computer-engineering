/* @file binarytree.hpp
* @description BST Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#include <cstddef> // definition of NULL
#include <cassert> // for assert()
#include <binarytree.hpp>
#include <TreeException.hpp>


BinaryTree::BinaryTree() : root(NULL)
{
} // end default constructor

BinaryTree::BinaryTree(const TreeItemType& rootItem)
{
   root = new TreeNode(rootItem, NULL, NULL);
   assert(root != NULL);
} // end constructor

BinaryTree::BinaryTree(const TreeItemType& rootItem,
                       BinaryTree& leftTree,
                       BinaryTree& rightTree)
{
   root = new TreeNode(rootItem, NULL, NULL);
   assert(root != NULL);

   attachLeftSubtree(leftTree);
   attachRightSubtree(rightTree);
} // end constructor

BinaryTree::BinaryTree(const BinaryTree& tree)
{
   copyTree(tree.root, root);
} // end copy constructor

BinaryTree::BinaryTree(TreeNode *nodePtr)
                      : root(nodePtr)
{
} // end protected constructor

BinaryTree::~BinaryTree()
{
   destroyTree(root);
} // end destructor

bool BinaryTree::isEmpty() const
{
   return (root == NULL);
}

TreeItemType BinaryTree::rootData() const
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   return root->item;
}

void BinaryTree::setRootData(const TreeItemType& newItem)
{
   if (!isEmpty())
      root->item = newItem;
   else
   {  root = new TreeNode(newItem, NULL, NULL);
      if (root == NULL)
         throw TreeException(
            "TreeException: Cannot allocate memory");
   } 
}

void BinaryTree::attachLeft(const TreeItemType& newItem)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else if (root->leftChildPtr != NULL)
      throw TreeException(
         "TreeException: Cannot overwrite left subtree");
   else // Assertion: nonempty tree; no left child
   {  root->leftChildPtr = new TreeNode(newItem, NULL, NULL);
      if (root->leftChildPtr == NULL)
         throw TreeException(
            "TreeException: Cannot allocate memory");
   }
}

void BinaryTree::attachRight(const TreeItemType& newItem)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else if (root->rightChildPtr != NULL)
      throw TreeException(
         "TreeException: Cannot overwrite right subtree");
   else // Assertion: nonempty tree; no right child
   {  root->rightChildPtr = new TreeNode(newItem, NULL, NULL);

      if (root->rightChildPtr == NULL)
         throw TreeException(
            "TreeException: Cannot allocate memory");
   } 
} 

void BinaryTree::attachLeftSubtree(BinaryTree& leftTree)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else if (root->leftChildPtr != NULL)
      throw TreeException(
         "TreeException: Cannot overwrite left subtree");
   else // Assertion: nonempty tree; no left child
   {  root->leftChildPtr = leftTree.root;
      leftTree.root = NULL;
   }
} 

void BinaryTree::attachRightSubtree(BinaryTree& rightTree)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else if (root->rightChildPtr != NULL)
      throw TreeException(
         "TreeException: Cannot overwrite right subtree");
   else // Assertion: nonempty tree; no right child
   {  root->rightChildPtr = rightTree.root;
      rightTree.root = NULL;
   } 
} 

void BinaryTree::detachLeftSubtree(BinaryTree& leftTree)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else
   {  leftTree = BinaryTree(root->leftChildPtr);
      root->leftChildPtr = NULL;
   }
} 

void BinaryTree::detachRightSubtree(BinaryTree& rightTree)
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   else
   {  rightTree = BinaryTree(root->rightChildPtr);
      root->rightChildPtr = NULL;
   } 
} 

BinaryTree BinaryTree::leftSubtree() const
{
   TreeNode *subTreePtr;
   if (isEmpty())
      return BinaryTree();
   else
   {  copyTree(root->leftChildPtr, subTreePtr);
      return BinaryTree(subTreePtr);
   } 
} 

BinaryTree BinaryTree::rightSubtree() const
{
   TreeNode *subTreePtr;
   if (isEmpty())
      return BinaryTree();
   else
   {  copyTree(root->rightChildPtr, subTreePtr);
      return BinaryTree(subTreePtr);
   } 
} 

void BinaryTree::preorderTraverse(FunctionType visit)
{
   preorder(root, visit);
} // end preorderTraverse

void BinaryTree::inorderTraverse(FunctionType visit)
{
   inorder(root, visit);
} // end inorderTraverse

void BinaryTree::postorderTraverse(FunctionType visit)
{
   postorder(root, visit);
} // end postorderTraverse

BinaryTree& BinaryTree::operator=(const BinaryTree& rhs)
{
   if (this != &rhs)
   {  destroyTree(root); // deallocate left-hand side
      copyTree(rhs.root, root); // copy right-hand side
   } 
   return *this;
} // end operator=

void BinaryTree::copyTree(TreeNode *treePtr,
                          TreeNode *& newTreePtr) const
{
   // preorder traversal
   if (treePtr != NULL)
   {  // copy node
      newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
      if (newTreePtr == NULL)
         throw TreeException(
            "TreeException: Cannot allocate memory");

      copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
      copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
   }
   else
      newTreePtr = NULL; 
} 

void BinaryTree::destroyTree(TreeNode *& treePtr)
{
   // postorder traversal
   if (treePtr != NULL)
   {  destroyTree(treePtr->leftChildPtr);
      destroyTree(treePtr->rightChildPtr);
      delete treePtr;
      treePtr = NULL;
   } 
} 

TreeNode *BinaryTree::rootPtr() const
{
  return root;
} // end rootPtr

void BinaryTree::setRootPtr(TreeNode *newRoot)
{
   root = newRoot;
} // end setRoot

void BinaryTree::getChildPtrs(TreeNode *nodePtr,
                              TreeNode *& leftPtr,
                              TreeNode *& rightPtr) const
{
   leftPtr = nodePtr->leftChildPtr;
   rightPtr = nodePtr->rightChildPtr;
} // end getChildPtrs

void BinaryTree::setChildPtrs(TreeNode *nodePtr,
                              TreeNode *leftPtr,
                              TreeNode *rightPtr)
{
   nodePtr->leftChildPtr = leftPtr;
   nodePtr->rightChildPtr = rightPtr;
} // end setChildPtrs

void BinaryTree::preorder(TreeNode *treePtr,
                          FunctionType visit)
{
   if (treePtr != NULL)
   {  visit(treePtr->item);
      preorder(treePtr->leftChildPtr, visit);
      preorder(treePtr->rightChildPtr, visit);
   } 
} // end preorder

void BinaryTree::inorder(TreeNode *treePtr,
                         FunctionType visit)
{
   if (treePtr != NULL)
   {  inorder(treePtr->leftChildPtr, visit);
      visit(treePtr->item);
      inorder(treePtr->rightChildPtr, visit);
   } 
} // end inorder

void BinaryTree::postorder(TreeNode *treePtr,
                           FunctionType visit)
{
   if (treePtr != NULL)
   {  postorder(treePtr->leftChildPtr, visit);
      postorder(treePtr->rightChildPtr, visit);
      visit(treePtr->item);
   } 
} // end postorder