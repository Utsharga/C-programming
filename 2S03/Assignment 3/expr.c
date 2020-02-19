/* Filename: expr.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>
#include "expr.h"
#include <stdlib.h>
#include <string.h>
char* makeString (char* s1 , char* s2 , char* s3){
    char *rtn = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);
    if(!rtn) return rtn;
    int p, q = 0;
    for (p = 0; (rtn[q] = s1[p]) != '\0'; ++p, ++q) {}
    for (p = 0; (rtn[q] = s2[p]) != '\0'; ++p, ++q) {}
    for (p = 0; (rtn[q] = s3[p]) != '\0'; ++p, ++q) {}
    return rtn;
}
Node* createNode (char* s, double val){
    Node* p = malloc(sizeof(Node));
    if(!p) return p;
    p->value = val;
    if(s != NULL)
      p->expr_string = makeString(s,"","");
    p->left = NULL;
    p->right = NULL;
    p->num_parents = 0;
    return p;
}
Node* binop (Operation op , Node* a, Node* b){
    Node* p = createNode(0,0);
    if(!p) return p;
    char *temp1, *temp2;
    if((a->num_parents == 1) || (b->num_parents == 1)){
        return NULL;
    }
    else {
        p->left = a;
        p->right = b;
        p->operation = op;
        p->num_parents=0;
        a->num_parents++;
        b->num_parents++;
        if (op==addop)  p->expr_string = makeString(a->expr_string, "+", b->expr_string);
        if (op==subop)  p->expr_string = makeString(a->expr_string, "-", b->expr_string);
        if (op==mulop){
            temp1 = (makeString("(", a->expr_string, ")"));
            temp2 = (makeString("(", b->expr_string, ")"));
            p->expr_string = makeString(temp1, "*",temp2);
            free(temp1);
            free(temp2);}
        if (op==divop){
            temp1 = (makeString("(", a->expr_string, ")"));
            temp2 = (makeString("(", b->expr_string, ")"));
            p->expr_string = makeString(temp1, "/", temp2);
            free(temp1);
            free(temp2);}
    }
    return p;
}
double evalTree ( Node* root ){
    double l_val, r_val;
    if (!root) return 0;
    else if (!root->left && !root->right)  return (root->value);
    else {
        l_val = evalTree(root->left);
        r_val = evalTree(root->right);
        if (root->operation==addop){ root->value=(l_val+r_val); return l_val+r_val;}
        if (root->operation==subop){ root->value=(l_val-r_val); return l_val-r_val;}
        if (root->operation==mulop){ root->value=(l_val*r_val); return l_val*r_val;}
        if (root->operation==divop){ root->value=(l_val/r_val); return l_val/r_val;}
    }
    return 0;
}
void freeTree (Node* root){
    if (root != NULL) {
        freeTree(root->right);
        free(root->expr_string);
        freeTree(root->left);
        free(root);
    }
}
Node* duplicateTree (Node* root){
    if (!root) return NULL;
    Node* new_node = malloc(sizeof(Node));
    if(root->expr_string != NULL) new_node->expr_string = makeString(root->expr_string, "", "");
    new_node->num_parents = root->num_parents;
    new_node->operation = root->operation;
    new_node->value = root->value;
    new_node->left = duplicateTree(root->left);
    new_node->right = duplicateTree(root->right);
    return new_node;
}
void printTree( Node* root ){
    if (!root) return;
    printf("Node\n");
    printf("    expr_string = %s\n", root->expr_string);
    printf("    value       = %g\n", root->value);
    printf("    num_parents = %d\n", root->num_parents);
    if (!root->left && !root->right) return;
    printTree(root->left);
    printTree(root->right);
    return;
}