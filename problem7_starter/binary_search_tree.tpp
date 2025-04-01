#include "binary_search_tree.hpp"
#include <vector>
#include <stdexcept>
#include <functional>
// default constructor
template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = nullptr;
}

// copy constructor
// this constructor uses a stack to copy the tree
template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType> &tree_to_copy)
{
    root = nullptr;
    Node<KeyType, ItemType> **this_tree_root = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.node_to_copy = tree_to_copy.root;
    rootvar.this_node_address = this_tree_root;
    s.push(rootvar);

    while (!s.empty())
    {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType> *curr_node_to_copy = currentvar.node_to_copy;
        Node<KeyType, ItemType> **curr_this_node_address = currentvar.this_node_address;

        if (curr_node_to_copy == nullptr)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType> *temp = new Node<KeyType, ItemType>;
        temp->key = curr_node_to_copy->key;
        temp->data = curr_node_to_copy->data;
        temp->left = nullptr;
        temp->right = nullptr;
        *curr_this_node_address = temp; // assigns value using this node address

        // push left subtree
        stackvar<KeyType, ItemType> left_subtree_root;
        left_subtree_root.node_to_copy = curr_node_to_copy->left;
        left_subtree_root.this_node_address = &((*curr_this_node_address)->left);
        s.push(left_subtree_root);

        // push right subtree
        stackvar<KeyType, ItemType> right_subtree_root;
        right_subtree_root.node_to_copy = curr_node_to_copy->right;
        right_subtree_root.this_node_address = &((*curr_this_node_address)->right);
        s.push(right_subtree_root);
    }
}

// copy assignment operator using copy-and-swap idiom
template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType> &BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> tree_to_copy)
{
    swap(tree_to_copy);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType> &tree_to_swap)
{
    std::swap(root, tree_to_swap.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    // push root node to stack
    std::stack<Node<KeyType, ItemType> *> s;
    s.push(root);

    while (!s.empty())
    {
        // pop the top node from the stack
        Node<KeyType, ItemType> *curr = s.top();
        s.pop();

        // push left and right children to the stack
        // and delete the current node
        if (curr != nullptr)
        {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    // set root to nullptr to avoid dangling pointer
    root = nullptr;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType &key, const ItemType &item)
{
    if (isEmpty()) {
        root = new Node<KeyType, ItemType>;
        root->key = key;
        root->data = item;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    Node<KeyType, ItemType> *curr;
    Node<KeyType, ItemType> *curr_parent;
    bool found = search(key, curr, curr_parent);
    if (found) {
        return false;
    }
    Node<KeyType, ItemType> *newNode = new Node<KeyType, ItemType>;
    newNode->key = key;
    newNode->data = item;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (key < curr->key) {
        curr->left = newNode;
    } else {
        curr->right = newNode;
    }
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == nullptr);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType &key, ItemType &item)
{
    Node<KeyType, ItemType> *curr;
    Node<KeyType, ItemType> *curr_parent;
    bool found = search(key, curr, curr_parent);

    if (found)
    {
        item = curr->data;
        return true;
    }

    return false;
}
//cases are node is a leaf, node only has right child, left child and two childs
template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
      return false;
   Node<KeyType, ItemType> *curr;
   Node<KeyType, ItemType> *curr_parent;
   bool found = search(key, curr, curr_parent);
   if (!found)
    return false;
  if (curr->left == nullptr && curr->right == nullptr) {
      if (curr_parent == nullptr) {
          root = nullptr;
      } else {
          if (curr_parent->left == curr)
              curr_parent->left = nullptr;
          else
              curr_parent->right = nullptr;
      }
      delete curr;
      return true;
  }
  else if (curr->left == nullptr) {
      Node<KeyType, ItemType> *child = curr->right;
      if (curr_parent == nullptr) {
          root = child;
      } else {
          if (curr_parent->left == curr)
              curr_parent->left = child;
          else
              curr_parent->right = child;
      }
      delete curr;
      return true;
  }
  else if (curr->right == nullptr) {
      Node<KeyType, ItemType> *child = curr->left;
      if (curr_parent == nullptr) {
          root = child;
      } else {
          if (curr_parent->left == curr)
              curr_parent->left = child;
          else
              curr_parent->right = child;
      }
      delete curr;
      return true;
  }
  else {
      Node<KeyType, ItemType> *inorder;
      Node<KeyType, ItemType> *inorder_parent;
      inorder_successor(curr, inorder, inorder_parent);
      curr->key = inorder->key;
      curr->data = inorder->data;
      if (inorder_parent == curr) {
          inorder_parent->right = inorder->right;
      } else {
          inorder_parent->left = inorder->right;
      }
      delete inorder;
      return true;
  }
}
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int arr_size)
{
    destroy();//fresh start
    for (int i = 0; i < arr_size; i++) {//loop over each element in input,insert method returns false for dupes
        if (!insert(arr[i], arr[i])) {
            throw std::logic_error("Duplicate item found in input array.");
        }
    }
    //this is where functional is used, which does an in order traversal
    std::vector<KeyType> sorted;
    std::function<void(Node<KeyType, ItemType>*)> inorder = [&](Node<KeyType, ItemType>* node) {
        if (!node) return;
            inorder(node->left);
            sorted.push_back(node->key);
            inorder(node->right);
        };
        inorder(root);
        for (int i = 0; i < arr_size; i++) {
            arr[i] = sorted[i];
        }
    // BONUS TODO: check for duplicate items in the input array (throw an exception if so)

    // BONUS TODO: use the tree to sort the array items
    // 1. first insert all items into the tree
    // 2. then use whatever existing method to traverse the tree
    // 3. retrieve the items in sorted order

    // BONUS TODO: overwrite input array values with sorted values
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder_successor(Node<KeyType, ItemType> *curr,
                                                            Node<KeyType, ItemType> *&inorder,
                                                            Node<KeyType, ItemType> *&inorder_parent)
{
    inorder_parent = curr;
    inorder = curr->right; // start with the right child

    // find the leftmost node in the right subtree, this is the inorder successor
    while (inorder != nullptr && inorder->left != nullptr)
    {
        inorder_parent = inorder;
        inorder = inorder->left;
    }
    // inorder points to the inorder successor at the end of this loop
    // inorder_parent points to the parent of the inorder successor
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::search(KeyType key,
                                                 Node<KeyType, ItemType> *&curr,
                                                 Node<KeyType, ItemType> *&curr_parent)
// last two parameters are passed by reference to allow the caller to modify them
{
    curr = root;
    curr_parent = nullptr;

    if (isEmpty())
        return false;

    while (true)
    {
        if (key == curr->key)
        {
            // found
            return true;
        }
        if (key < curr->key)
        {
            // search left
            if (curr->left != nullptr)
            {
                curr_parent = curr;
                curr = curr->left;
            }
            else
            {
                curr_parent = curr;//added this as my method would fail, so now it updates the parent before returning
                // nowhere further to search
                return false;
            }
        }
        else
        {
            // search right
            if (curr->right != nullptr)
            {
                curr_parent = curr;
                curr = curr->right;
            }
            else
            {
                curr_parent = curr; //same change
                // nowhere further to search
                return false;
            }
        }
    }
}
