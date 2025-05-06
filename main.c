#include "nbtree.h"

int main(){
    Isi_Tree X;
    int pilih;

    Create_tree(X, 20);

    do
    {
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search Node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih menu : ");
        scanf("%d",&pilih);
        switch (pilih)
        {
        case 1:
            PreOrder (X);
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 2:
            InOrder (X);
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 3:
            PostOrder (X);
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 4:
            Level_order(X, 10);
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 5:
            PrintTree (X);
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 6:
            char info = 'H';
            if(Search (X, info)){
                printf("info %c di temukan",info);
            }
            else{
                printf("info %c tidak di temukan",info);
            }
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 7:
            printf("jumlah Leaf: %d",nbDaun (X));
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 8:
            char info1 = 'G';
            printf("info %c berada di level : %d",info1,Level (X, info1));
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 9:
            printf("kedalaman tree nya adalah %d",Depth (X));
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        case 10:
            char Data1 = 'D', Data2 = 'I';
            printf("membandingkan karakter %c dan Karakter %c di suatu node",Data1,Data2);
            printf("Karakter %c lebih besar",Max(Data1, Data2));
            printf("\n klik apapun untuk melanjutkan");
            getch();
            printf("\n");
            break;
        }
    } while (pilih != 11);
    return 0;
}