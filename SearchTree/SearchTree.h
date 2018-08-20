/***********************************************************/
/*    Search Tree
/*
/*    Aidan Clyens
/*    August 20, 2018
/***********************************************************/
#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "Arduino.h"

template <typename Type>
class SearchTree {
  public:
    class SearchNode {
      public:
        SearchNode( Type const & );

        //  Size
        int height() const;

        //  Element Access
        SearchNode *find( Type const & );

        //  Modifers
        bool insert( Type const & );
        bool erase( Type const &, SearchNode *& );
        void clear();

        //  Misc.
        bool is_leaf() const;
        int max( int, int ) const;
        void print( int = 0 );

        Type node_value;
        SearchNode* left_tree;
        SearchNode* right_tree;
        int tree_height;
    };

    SearchTree();
    ~SearchTree();

    //  Size
    bool empty() const;
    int size() const;
    int height() const;

    //  Element Access
    SearchNode *find( Type const & );

    //  Modifiers
    bool insert( Type const & );
    bool erase( Type const & );
    void clear();

    //  Misc.
    void print();

  private:
    SearchNode* root_node;
    int tree_size;
};

/***********************************************/
/***************   SearchTree    ***************/
/***********************************************/
/***************************************
*           Constructors
****************************************/
/*
 * Search Tree Constructor
 */
template <typename Type>
SearchTree<Type>::SearchTree():
root_node( nullptr ),
tree_size( 0 )
{
  //  Empty Constructor
}

/*
 * Search Tree Destructor
 */
template <typename Type>
SearchTree<Type>::~SearchTree() {
  clear();
}

/***************************************
*        Public Size Functions
****************************************/
/*
 * empty
 */
template <typename Type>
bool SearchTree<Type>::empty() const {
  return (tree_size == 0);
}

/*
 * size
 */
template <typename Type>
int SearchTree<Type>::size() const {
  return tree_size;
}

/*
 * height
 */
template <typename Type>
int SearchTree<Type>::height() const {
  return root_node->height();
}

/***************************************
*        Element Access Functions
****************************************/
/*
 * find
 */
template <typename Type>
typename SearchTree<Type>::SearchNode *SearchTree<Type>::find(Type const &obj) {
  if (empty()) return nullptr;

  return root_node->find(obj);
}

/***************************************
*       Public Modifier Functions
****************************************/
/*
 * insert
 */
template <typename Type>
bool SearchTree<Type>::insert(Type const &obj) {
  if (empty()) {
    root_node = new SearchTree::SearchNode(obj);
    tree_size = 1;

    return true;
  } else if (root_node->insert(obj)) {
    ++tree_size;
    return true;
  } else {
    return false;
  }
}

/*
 * erase
 */
template <typename Type>
bool SearchTree<Type>::erase(Type const &obj) {
  if (empty()) return false;

  if (root_node->erase(obj, root_node)) {
    --tree_size;

    return true;
  }
}

/*
 * clear
 */
template <typename Type>
void SearchTree<Type>::clear() {
  root_node->clear();
}

/***************************************
*         Public Misc. Functions
****************************************/
/*
 * print
 */
template <typename Type>
void SearchTree<Type>::print() {
  root_node->print(6*height());
}

/***********************************************/
/***************   SearchNode    ***************/
/***********************************************/
/***************************************
*           Constructors
****************************************/
/*
 * SearchNode Constructor
 */
template <typename Type>
SearchTree<Type>::SearchNode::SearchNode(Type const &obj):
node_value( obj ),
left_tree( nullptr ),
right_tree( nullptr ),
tree_height( 0 )
{
  //  Empty Constructor
}

/***************************************
*        Public Size Functions
****************************************/
/*
 * height
 */
template <typename Type>
int SearchTree<Type>::SearchNode::height() const {
  return (this == nullptr) ? -1 : tree_height;
}

/***************************************
*        Element Access Functions
****************************************/
/*
 * find
 */
template <typename Type>
typename SearchTree<Type>::SearchNode *SearchTree<Type>::SearchNode::find(Type const &obj) {
  if (obj == node_value) {
    return this;
  } else if (obj < node_value) {
    if (left_tree != nullptr) {
      return left_tree->find(obj);
    } else {
      return nullptr;
    }
  } else if (obj > node_value) {
    if (right_tree != nullptr) {
      return right_tree->find(obj);
    } else {
      return nullptr;
    }
  }
}

/***************************************
*       Public Modifier Functions
****************************************/
/*
 * insert
 */
template <typename Type>
bool SearchTree<Type>::SearchNode::insert(Type const &obj) {
  //  If the new object is less than the current value, attempt to insert into the left tree
  if (obj < node_value) {
    //  If there is no left tree, create a new node
    if (left_tree == nullptr) {
      left_tree = new SearchTree::SearchNode(obj);
      tree_height = max(left_tree->height(), right_tree->height()) + 1;

      return true;
    //  If there is a left tree, attempt to insert into it
    } else {
      if (left_tree->insert(obj)) {
        tree_height = max(left_tree->height(), right_tree->height()) + 1;

        return true;
      //  If the new object could not be inserted into the left tree, return false
      } else {
        return false;
      }
    }
  //  If the new object is greater than the current value, attempt to insert into the right tree
  } else if (obj > node_value) {
    //  If there is no right tree, create a new node
    if (right_tree == nullptr) {
      right_tree = new SearchTree::SearchNode(obj);
      tree_height = max(left_tree->height(), right_tree->height()) + 1;

      return true;
    //  If there is a right tree, attempt to insert into it
    } else if (right_tree->insert(obj)) {
      tree_height = max(left_tree->height(), right_tree->height()) + 1;

      return true;
    //  If the new object could not be inserted into the right tree, return false
    } else {
      return false;
    }

  //  If the object is equal to the current value, do nothing and return false
  } else {
    return false;
  }
}

/*
 * erase
 */
template <typename Type>
bool SearchTree<Type>::SearchNode::erase(Type const &obj, SearchNode *&to_this) {
  if (obj < node_value) {
    if (left_tree != nullptr) {
      if (left_tree->erase(obj, left_tree)) {
        tree_height = max(left_tree->height(), right_tree->height()) + 1;
        return true;
      } else {
        return false;
      }
    }
  } else if (obj > node_value) {
    if (right_tree != nullptr) {
      if (right_tree->erase(obj, right_tree)) {
        tree_height = max(left_tree->height(), right_tree->height()) + 1;
        return true;
      } else {
        return false;
      }
    }
  } else {
    if (is_leaf()) {
      to_this = nullptr;
      delete this;
    } else if (left_tree == nullptr) {
      to_this = right_tree;
      delete this;
    } else if (right_tree == nullptr) {
      to_this = left_tree;
      delete this;
    } else {
      node_value = right_tree->node_value;
      right_tree->erase(node_value, right_tree);
      tree_height = max(left_tree->height(), right_tree->height()) + 1;
    }

    return this;
  }
}

/*
 * clear
 */
template <typename Type>
void SearchTree<Type>::SearchNode::clear() {
  if (left_tree != nullptr) left_tree->clear();
  if (right_tree != nullptr) right_tree->clear();

  delete this;
}

/***************************************
*         Public Misc. Functions
****************************************/
/*
 * is_leaf
 */
template <typename Type>
bool SearchTree<Type>::SearchNode::is_leaf() const {
  return (left_tree == nullptr && right_tree == nullptr);
}

/*
 * print
 */
template <typename Type>
void SearchTree<Type>::SearchNode::print(int indent) {
  if (this != nullptr) {
    if (indent) {
      for (int i = 0; i < indent; ++i) {
        Serial.print(" ");
      }
    }
    Serial.println(node_value);
    if (left_tree != nullptr) left_tree->print(indent-5);
    if (right_tree != nullptr) right_tree->print(indent+5);
  }
}

/*
 * max
 */
template <typename Type>
int SearchTree<Type>::SearchNode::max(int lhs, int rhs) const {
  return (lhs > rhs) ? lhs : rhs;
}

#endif
