#include "nbtree.h"

int main(){
    Isi_Tree X;

    Create_tree(X, 10);
    for (int i = 1; i <= 10; i++)
    {
        printf("%c \n", X[i].info);
        printf("%d\n",X[i].ps_fs); 
        printf("%d\n",X[i].ps_nb); 
        printf("%d\n\n",X[i].ps_pr); 
    }
    

    return 0;
}