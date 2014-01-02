
typedef int (*Compare) (void *a , void *b);
        
typedef struct {
        Compare compare;
        void *root;
} BST;
typedef struct Node{
        void *data;
        struct Node *left;
        struct Node *right;
}Node;

BST* createBST(Compare compare);
int insertInBST(BST* tree , void *value);
int searchInBST(BST* tree, void *value);
int deleteFromBST(BST* tree, void *value);
void dispose();

