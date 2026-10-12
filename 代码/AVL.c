#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int num;
    int bf;
    struct Node* Left;
    struct Node* Right;
}Node;
Node* createnode(int num)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> num = num;
    newnode -> bf = 0;
    newnode -> Left = NULL;
    newnode -> Right = NULL;
    return newnode;
}
//进行LL
Node* LLrotation(Node* node)
{
    Node* newnode = node -> Left;
    if(newnode -> Right !=NULL){
        node -> Left = newnode -> Right;
    }else{
        node -> Left =NULL;
    }
    newnode -> Right = node;
    newnode -> bf = 0;
    node -> bf = 0;
    return newnode;
}
//进行RR
Node* RRrotation(Node* node)
{
    Node* newnode = node -> Right;
    if(newnode -> Left !=NULL){
        node -> Right = newnode -> Left;
    }else{
        node -> Right = NULL;
    }
    newnode -> Left = node;
    newnode -> bf = 0;
    node -> bf = 0;
    return newnode;
}
//进行RL
Node* RLrotation(Node* node)
{
    Node *newnode = node -> Right -> Left;
    int oldbf = newnode -> bf;
    node -> Right ->Left = newnode ->Right;
    newnode -> Right = node -> Right;
    node ->Right = newnode -> Left;
    newnode -> Left = node;
    newnode -> bf = 0;
    if(oldbf == 1){
        node -> bf = 0;
        newnode -> Right -> bf = -1;
    }else if(oldbf == 0){
        node -> bf = 0;
        newnode -> Right -> bf = 0;
    }else if(oldbf == -1){
        node -> bf = 1;
        newnode -> Right -> bf = 0;
    }
    return newnode;
}
//进行LR
Node* LRrotation(Node* node)
{
    Node *newnode = node -> Left -> Right;
    int oldbf = newnode -> bf;
    node -> Left ->Right = newnode ->Left;
    newnode -> Left = node -> Left;
    node ->Left = newnode -> Right;
    newnode -> Right = node;
    newnode -> bf = 0;
    if(oldbf == 1){
        node -> bf = -1;
        newnode -> Left -> bf = 0;
    }else if(oldbf == 0){
        node -> bf = 0;
        newnode -> Left-> bf = 0;
    }else if(oldbf == -1){
        node -> bf = 0;
        newnode -> Left -> bf = 1;
    }
    return newnode;
}
//进行插入操作
Node* Insert(Node* Root,int num,int* increaseh)
{
    if(Root == NULL){
        Node* newnode = createnode(num);
        *increaseh = 1;
        return newnode;
    }
    if(num < Root -> num){
        Root -> Left = Insert(Root -> Left,num,increaseh);
        if(*increaseh){
            Root -> bf ++;
            if(Root -> bf == 0){
                *increaseh = 0;
            }else if(Root -> bf == 1){
                *increaseh = 1;
            }else if(Root -> bf > 1){
                if(Root -> Left ->bf == 1){
                    Root = LLrotation(Root);
                }else {
                    Root = LRrotation(Root);
                }
                *increaseh = 0;
            }
        }
    }else if(num > Root -> num){
        Root -> Right = Insert(Root -> Right,num,increaseh);
        if(*increaseh){
            Root -> bf --;
            if(Root -> bf == 0){
                *increaseh = 0;
            }else if(Root -> bf == -1){
                *increaseh = 1;
            }else if(Root -> bf < -1){
                if(Root -> Right ->bf == -1){
                    Root = RRrotation(Root);
                }else {
                    Root = RLrotation(Root);
                }
                *increaseh = 0;
            }
        }
    }
    return Root;
}
int main(){
    int n;
    scanf("%d",&n);
    Node* root = (Node*)malloc(sizeof(Node));
    root = NULL;
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        int increaseh = 0;
        root = Insert(root,m,&increaseh);
    }
    printf("%d",root->num);
}