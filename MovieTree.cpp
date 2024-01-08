#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode *getLLMovieNode(int r, string t, int y, float q)
{
    LLMovieNode *lmn = new LLMovieNode();
    lmn->ranking = r;
    lmn->title = t;
    lmn->year = y;
    lmn->rating = q;
    lmn->next = NULL;
    return lmn;
}

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
    root = NULL;
}

/* ------------------------------------------------------ */
void _destruct(TreeNode *t)
{
    if (t)
    {
        _destruct(t->leftChild);
        _destruct(t->rightChild);

        LLMovieNode *curr = t->head;
        LLMovieNode *prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
            prev = NULL;
        }
        delete t;
        t = NULL;
    }
}

MovieTree::~MovieTree()
{
    _destruct(root);
}

/* ------------------------------------------------------ */
void inorderTraversalHelper(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversalHelper(root->leftChild);
    cout << root->titleChar << " ";
    inorderTraversalHelper(root->rightChild);
}

void MovieTree::inorderTraversal()
{
    inorderTraversalHelper(root);
    cout << endl;
}

/* ------------------------------------------------------ */
TreeNode *searchCharHelper(TreeNode *curr, char key)
{
    if (curr == NULL)
        return curr;
    else if (curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode *MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* ------------------------------------------------------ */
void _showMovieCollection(TreeNode *T)
{
    if (T == NULL)
        return;
    else
    {
        _showMovieCollection(T->leftChild);
        LLMovieNode *m = T->head;
        cout << "Movies starting with letter: " << T->titleChar << endl;
        while (m != NULL)
        {
            cout << " >> " << m->title << " " << m->rating << endl;
            m = m->next;
        }
        _showMovieCollection(T->rightChild);
    }
}

void MovieTree::showMovieCollection()
{
    _showMovieCollection(root);
}

/* ------------------------------------------------------ */
void _insert(int ranking, string title, int year, float rating, TreeNode *&T, TreeNode *&parent)
{
    if (T == NULL)
    {
        T = new TreeNode;
        T->titleChar = title[0];
        T->leftChild = NULL;
        T->rightChild = NULL;
        T->parent = parent;

        T->head = new LLMovieNode;
        T->head->next = NULL;
        T->head->ranking = ranking;
        T->head->rating = rating;
        T->head->title = title;
        T->head->year = year;
    }
    else
    {
        if (title[0] > T->titleChar)
        {
            parent = T;
            _insert(ranking, title, year, rating, T->rightChild, parent);
        }
        else
        {
            parent = T;
            _insert(ranking, title, year, rating, T->leftChild, parent);
        }
    }
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
    LLMovieNode *newM = getLLMovieNode(ranking, title, year, rating);

    if (root == NULL)
    {
        root = new TreeNode;
        root->leftChild = NULL;
        root->rightChild = NULL;
        root->parent = NULL;
        root->titleChar = title[0];
        root->head = newM;
    }
    else if (searchCharNode(title[0]) != NULL) // check to see if tree node is already there
    {
        LLMovieNode *curr = searchCharNode(title[0])->head;
        LLMovieNode *prev;

        // check to see if new movie is head of tree node
        if (title.compare(curr->title) < 0)
        {
            newM->next = searchCharNode(title[0])->head;
            searchCharNode(title[0])->head = newM;
        }
        else
        {
            // iterate down the linked list under the tree node
            while (curr != NULL && title.compare(curr->title) > 0)
            {
                prev = curr;
                curr = curr->next;
            }
            newM->next = curr;
            prev->next = newM;
        }
    }
    else
    {
        TreeNode *node;
        _insert(ranking, title, year, rating, root, node);
    }
}

/* ------------------------------------------------------ */
void MovieTree::removeMovieRecord(string title)
{
    TreeNode *targetT = searchCharNode(title[0]);

    if (targetT == NULL)
    {
        cout << "Movie not found." << endl;
        return;
    }

    LLMovieNode *targetM = targetT->head;

    if (targetT->head->title == title) // if target movie is the the TreeNode's head
    {
        targetT->head = targetT->head->next;
        delete targetM;
        targetM = NULL;

        if (targetT->head == NULL)
        {
            delete targetT;
            targetT = NULL;
        }

        return;
    }

    targetM = targetT->head;
    LLMovieNode *prevM;

    while (title.compare(targetM->title) > 0) // go to correct position in linked list
    {
        prevM = targetM;
        targetM = targetM->next;
    }
    if (title == targetM->title)
    {
        prevM->next = targetM->next;
        delete targetM;
        targetM = NULL;
        return;
    }

    cout << "Movie not found." << endl;
}

/* ------------------------------------------------------ */
void MovieTree::leftRotation(TreeNode *curr)
{
    if (root == NULL)
        return;
    else if (curr->rightChild == NULL)
    {
        cout << "no rotation can be performed" << endl;
        return;
    }
    else if (curr == root)
    {
        TreeNode *currRight = curr->rightChild;
        root = curr->rightChild;
        
        // set parents
        curr->rightChild->parent = NULL;
        curr->parent = curr->rightChild;

        // reorder tree
        curr->rightChild = currRight->leftChild;
        currRight->leftChild = curr;
    }
    else
    {
        // set parents
        TreeNode *currParent = curr->parent;
        TreeNode *currRight = curr->rightChild;
        if (curr->rightChild->leftChild != NULL)
        {
            curr->rightChild->leftChild->parent = curr;
        }
        currRight->parent = currParent;
        curr->parent = currRight;

        // reorder tree
        curr->rightChild = currRight->leftChild;
        currRight->leftChild = curr;
        
        if(currRight->parent->titleChar < currRight->titleChar)
        {
            currRight->parent->rightChild = currRight;
        }
        else
        {
            currRight->parent->leftChild = currRight;
        }
    }
}

/* ------------------------------------------------------ */
