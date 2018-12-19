/* @file binarytree.hpp
* @description BST Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "TreeException.hpp"

typedef void (*FunctionType)(TreeItemType& anItem);

class BinaryTree
{
public:
// constructors and destructor:
   BinaryTree();
   BinaryTree(const TreeItemType& rootItem);
   BinaryTree(const TreeItemType& rootItem,
              BinaryTree& leftTree,
              BinaryTree& rightTree);
   BinaryTree(const BinaryTree& tree);
   virtual ~BinaryTree();

// binary tree operations:
   virtual bool isEmpty() const;
   virtual TreeItemType rootData() const
      throw(TreeException);
   virtual void setRootData(const TreeItemType& newItem)
      throw (TreeException);
   virtual void attachLeft(const TreeItemType& newItem)
      throw(TreeException);
   virtual void attachRight(const TreeItemType& newItem)
      throw(TreeException);
   virtual void attachLeftSubtree(BinaryTree& leftTree)
      throw(TreeException);
   virtual void attachRightSubtree(BinaryTree& rightTree)
      throw(TreeException);
   virtual void detachLeftSubtree(BinaryTree& leftTree)
      throw(TreeException);
   virtual void detachRightSubtree(BinaryTree& rightTree)
      throw(TreeException);
   virtual BinaryTree leftSubtree() const;
   virtual BinaryTree rightSubtree() const;
   virtual void preorderTraverse(FunctionType visit);
   virtual void inorderTraverse(FunctionType visit);
   virtual void postorderTraverse(FunctionType visit);

// overloaded operator:
   virtual BinaryTree& operator=(const BinaryTree& rhs);

protected:
   BinaryTree(TreeNode *nodePtr); // constructor
   void copyTree(TreeNode *treePtr,
   TreeNode* & newTreePtr) const;
   // Copies the tree rooted at treePtr into a tree rooted
   // at newTreePtr. Throws TreeException if a copy of the
   // tree cannot be allocated.

   void destroyTree(TreeNode * &treePtr);
   // Deallocates memory for a tree.
   // The next two functions retrieve and set the value
   // of the private data member root.

   TreeNode *rootPtr() const;
   void setRootPtr(TreeNode *newRoot);

   // The next two functions retrieve and set the values
   // of the left and right child pointers of a tree node.
   void getChildPtrs(TreeNode *nodePtr,
                     TreeNode * &leftChildPtr,
                     TreeNode * &rightChildPtr) const;
   void setChildPtrs(TreeNode *nodePtr,
                     TreeNode *leftChildPtr,
                     TreeNode *rightChildPtr);

   void preorder(TreeNode *treePtr, FunctionType visit);
   void inorder(TreeNode *treePtr, FunctionType visit);
   void postorder(TreeNode *treePtr, FunctionType visit);

private:
   TreeNode *root; // pointer to root of tree
}; // end class
// End of header file.ortefore the node referenced by iter. If iter == end(),

#endif // BINARYTREE_HPP