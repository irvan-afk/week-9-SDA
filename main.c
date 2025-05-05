#include "nbtree.h"

int main(){
    Isi_Tree X;

    Create_tree(X, 10);
    // for (int i = 1; i <= 10; i++)
    // {
    //     printf("%c => ", X[i].info);
    //     printf("%d ",X[i].ps_fs); 
    //     printf("%d ",X[i].ps_nb); 
    //     printf("%d\n",X[i].ps_pr); 
    // }
    
    PreOrder (X);


    return 0;
}