/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int *TreeNodeToArray( struct TreeNode* root ){
    if(root == NULL)
      return 0;

    int * array = malloc(sizeof(int)* 10000);
    int index=0;

    while(root != NULL){
        array[index++] = root->val;

        if(root->left != NULL) { 
            array[index++] = root->left->val; 
        } else { 
                array[index++] = -1;
        }
        if(root->right) {
            array[index++] = root->right->val;
            
        } else {
                array[index++] = -1;
        }
        root = root->left;
    }
    for( int i =0 ; i< sizeof(array)/sizeof(int) ; i++) { 
       printf("%d, ", array[i] );
    }
    return array;
}

struct TreeNode* balanceBST(struct TreeNode* root) {

    struct TreeNode *agent = root;
    int * array = TreeNodeToArray(agent);
/*
    while(agent->left != NULL){
        agent = agent->left;
        deepL++;
    }
    while(agent->right != NULL){
        agent = agent->right;
        deepR++;
    }
    int diference = deepL - deepR;

    if(  diference > 1 ){
        liftUp(agent->left, agent );
    } else {
        liftUp(agent->right, agent );
    }
*/

    return root;
}