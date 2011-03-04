/* Codeforces 675D - Tree Construction
 * https://codeforces.com/problemset/problem/675/D
 * rating: 1800 | tags: data structures, trees
 * source: accepted submission #18651374 (GNU C) downloaded from Codeforces
 */

//requires stdlib.h
#include<stdio.h>
#include<stdlib.h>

typedef struct __struct_BSTV{
    int val;
}BSTV;

typedef struct __struct_BST{
    BSTV val;  //Values stored in the node.
    int h;  //Height of the node. Starts from 0 for leaf nodes
    int count;  //Count of the number 'val' present in the BST. Set to 0 if deleted
    int w;  //Number of numbers in the sub-tree rooted at this node
    struct __struct_BST *left,*right;  //left and right children
}BST;

BSTV BST_makeV(int);
int BST_cmp(BSTV, BSTV);
void BST_insert(BST **, BSTV);
void BST_update(BST **);
int BST_geth(BST *);
int BST_getw(BST *);
int BST_getc(BST *);
void BST_fixit(BST **);
void BST_rotl(BST **);
void BST_rotr(BST **);
BST * BST_search(BST *, BSTV);
void BST_delete(BST **, BSTV);
int BST_lessthan(BST *, BSTV);
int BST_greaterthan(BST *, BSTV);
BST *BST_previous(BST *, BSTV);
BST *BST_next(BST *, BSTV);

int main(){
	BST *all, *left, *right, *tmp;
	int n,i,j;
	all=left=right=NULL;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &i);
		tmp=BST_previous(all, BST_makeV(i));
		BST_insert(&all, BST_makeV(i));
		if(tmp!=NULL && BST_search(right, tmp->val)==NULL){
			printf("%d ", tmp->val.val);
			BST_insert(&right, tmp->val);
		}
		else if((tmp=BST_next(all, BST_makeV(i)))!=NULL && BST_search(left, tmp->val)==NULL){
			printf("%d ", tmp->val.val);
			BST_insert(&left, tmp->val);
		}
	}
	printf("\n");
	return 0;
}

BSTV BST_makeV(int val){
    /*
      returns the struct which is used by the bst
    */
    BSTV retval;
    retval.val = val;
    return retval;
}

int BST_cmp(BSTV a, BSTV b){
    /*
      Compares the values of a and b
      -1(less than zero) if a < b
      0 if a == b
      1(greater than zero) if a > b
    */
    return a.val - b.val;
}

void BST_insert(BST **tarp, BSTV val){
    /*
      Inserts the number 'val' under the BST whose pointer is pointed by tarp
    */
    BST *target = *tarp;
    if(target == NULL){
	//Make a new leaf node
	target = (BST *)malloc(sizeof(BST));
	target->val = val;
	target->h = 0;
	target->left = NULL;
	target->right = NULL;
	target->count = 1;
	target->w = 1;
	*tarp = target;  //Change the pointer value to the newly allocated node
	return ;
    }
    if(BST_cmp(target->val, val) == 0){
	//Number already present in the BST. Only need to increase the count.
	target->count++;
	target->w++;
    }
    else if(BST_cmp(target->val, val) > 0){
	BST_insert(&(target->left), val);
    }
    else{
	BST_insert(&(target->right), val);
    }
    //Update values like height, weight etc.
    BST_update(tarp);
}

void BST_update(BST **tarp){
    /*
      Updates 'w' and 'h' of the BST.
      Make sure the children are updated before calling this for the parent.
    */
    BST *target = *tarp;
    int lh, rh;
    if(target == NULL){
	return ;
    }
    target->w = BST_getw(target->left) + BST_getw(target->right) + target->count;
    lh = BST_geth(target->left);
    rh = BST_geth(target->right);
    if(lh > rh)
	target->h = lh+1;
    else
	target->h = rh+1;
    //Make sure the BST is balanced
    if(lh > rh+1 || rh > lh+1)
	BST_fixit(tarp);
}

int BST_getw(BST *target){
    if(target == NULL)
	return 0;
    return target->w;
}

int BST_geth(BST *target){
    //Set height of NULL to -1 to make height of leaf nodes as 0
    if(target == NULL)
	return -1;
    return target->h;
}

int BST_getc(BST *target){
    if(target == NULL)
	return 0;
    return target->count;
}

void BST_fixit(BST **tarp){
    /*
      Fixes imbalanced BST
    */
    BST *target = *tarp;
    if(BST_geth(target->left) > BST_geth(target->right)){
	if(BST_geth(target->left->left) > BST_geth(target->left->right)){
	    BST_rotr(tarp);
	    BST_update(&((*tarp)->right));
	    BST_update(tarp);
	}
	else{
	    BST_rotl(&(target->left));
	    BST_rotr(tarp);
	    target = *tarp;
	    BST_update(&(target->left));
	    BST_update(&(target->right));
	    BST_update(tarp);
	}
    }
    else{
	if(BST_geth(target->right->right) > BST_geth(target->right->left)){
	    BST_rotl(tarp);
	    BST_update(&((*tarp)->left));
	    BST_update(tarp);
	}
	else{
	    BST_rotr(&(target->right));
	    BST_rotl(tarp);
	    target = *tarp;
	    BST_update(&(target->right));
	    BST_update(&(target->left));
	    BST_update(tarp);
	}		
    }
}

void BST_rotl(BST **tarp){
    /*
      Rotates the node towards left ie. CCW
    */
    BST *r, *target;
    target = *tarp;
    r = target->right;
    *tarp = r;
    target->right = r->left;
    r->left = target;
}

void BST_rotr(BST **tarp){
    /*
      Rotates the node towards left ie. CCW
    */
    BST *l, *target;
    target = *tarp;
    l = target->left;
    *tarp = l;
    target->left = l->right;
    l->right = target;
}

BST *BST_search(BST *target, BSTV val){
    /*
      Search for the node containing the number 'val'
    */
    if(target == NULL)
	return NULL;
    if(BST_cmp(target->val, val) == 0)
	return target;
    else if(BST_cmp(target->val, val) > 0){
	return BST_search(target->left, val);
    }
    else{
	return BST_search(target->right, val);
    }
}

void BST_delete(BST **tarp, BSTV val){
    /*
      Delete the number 'val' from the BST
    */
    BST *target;
    if(tarp == NULL)
	return ;
    target = *tarp;
    if(BST_cmp(target->val, val) == 0){
	if(target->count > 0){
	    target->count--;
	    target->w--;
	}
    }
    else if(BST_cmp(target->val, val) > 0){
	BST_insert(&(target->left), val);
    }
    else{
	BST_insert(&(target->right), val);
    }
    BST_update(tarp);
}

int BST_lessthan(BST *target, BSTV val){
    /*
      Return the number of elements in the BST lesser than 'val'
    */
    if(target == NULL)
	return 0;
    if(BST_cmp(target->val, val) >= 0){
	return BST_lessthan(target->left, val);
    }
    else{
	return BST_lessthan(target->right, val) + BST_getc(target) + BST_getw(target->left);
    }
}

int BST_greaterthan(BST *target, BSTV val){
    /*
      Return the number of elements in the BST greater than 'val'
    */
    if(target == NULL)
	return 0;
    if(BST_cmp(target->val, val) <= 0){
	return BST_greaterthan(target->right, val);
    }
    else{
	return BST_greaterthan(target->left, val) + BST_getc(target) + BST_getw(target->right);
    }
}

BST *BST_previous(BST *node, BSTV val){
    /*
      Return the node which comes before 'val' in-order.
      Returns NULL if no node is found.
    */
    if(node == NULL)
	return NULL;
    if(BST_cmp(node->val, val) < 0){
	BST *tmp = BST_previous(node->right, val);
	if(tmp)
	    return tmp;
	if(BST_getc(node)){
	    return node;
	}
    }
    return BST_previous(node->left, val);
}

BST *BST_next(BST *node, BSTV val){
    /*
      Return the node which comes after 'val' in-order.
      Returns NULL if no node is found.
    */
    if(node == NULL)
	return NULL;
    if(BST_cmp(node->val, val) > 0){
	BST *tmp = BST_next(node->left, val);
	if(tmp)
	    return tmp;
	if(BST_getc(node)){
	    return node;
	}
    }
    return BST_next(node->right, val);
}
