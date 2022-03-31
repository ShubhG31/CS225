/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node *root1 = t->right;
    t->right = root1->left;
    root1->left = t;


    t->height = 1 + std::max(heightOrNeg1(t->right), heightOrNeg1(t->left));
    root1->height = 1 + std::max(heightOrNeg1(root1->right), heightOrNeg1(root1->left));
    t = root1;


}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node *root1 = t->left;
    t->left = root1->right;
    root1->right = t;
    //update the height
    t->height = std::max(heightOrNeg1(t->right), heightOrNeg1(t->left)) +1;
    root1->height = std::max(heightOrNeg1(root1->right), heightOrNeg1(root1->left)) +1;
    t = root1;

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(subtree == NULL)return;
    int binaryHeight = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);

    if(binaryHeight==2){
        int binaryRight = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if(binaryRight>0){
            rotateLeft(subtree);
        }
        if(binaryRight<0){
            rotateRightLeft(subtree);
        }
    }
    if(binaryHeight==-2){
        int binaryLeft = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if(binaryLeft <0){
            rotateRight(subtree);
        }
        if(binaryLeft>0){
            rotateLeftRight(subtree);
        }

    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    // if(subtree==NULL){
    //     subtree=new Node(key, value);
    // }
    // else{
    //     (key<subtree->key)?insert(subtree->left,key,value):insert(subtree->right,key,value);
    // }
    // rebalance(subtree);
        if(subtree == NULL){
        Node* newNode =  new Node(key, value); 
        subtree = newNode;
    }
    else if(key>subtree->key){
        insert(subtree->right, key, value);
       // rebalance(subtree);
    }
    else if(key<subtree->key){
        insert(subtree->left, key, value);
        // rebalance(subtree);
    }
    else if(subtree->key == key){
        subtree->value = value;
    }
    subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL) return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree=NULL;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* previous=subtree->left;
            //goes to the right most tree when going to the left 
            while(previous->right!=NULL){
                previous=previous->right;
            }
            subtree->key= previous->key;
            subtree->value=previous->value;
            remove(subtree->left,previous->key);
            rebalance(subtree);
        } else {
            /* one-child remove */
            // your code here
            Node * tempTree = (subtree->right == NULL) ? subtree->left : subtree->right;
            *subtree = *tempTree;
            delete tempTree;
            tempTree = NULL;
            rebalance(subtree);
        }
        // your code here
        rebalance(subtree);
        subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));  
    }
}
