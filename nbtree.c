#include "nbtree.h"

void Create_tree(Isi_Tree X, int Jml_Node){

    char karakter = 'A';
    int i = 1, ascii = (int)karakter;

    while (i <= Jml_Node )
    {
        if (i <= 10)
        {
            X[i].info = ascii;
            ascii++;
        }
        else{
            X[i].info = '-'; 
            X[1].ps_fs = nil; 
            X[1].ps_nb = nil; 
            X[1].ps_pr = nil; 
        }
        
        i++;
    }
    
    X[1].ps_fs = 2; 
    X[1].ps_nb = nil; 
    X[1].ps_pr = nil; 

    X[2].ps_fs = 4; 
    X[2].ps_nb = 3; 
    X[2].ps_pr = 1;

    X[3].ps_fs = 6; 
    X[3].ps_nb = nil; 
    X[3].ps_pr = 1;

    X[4].ps_fs = 0; 
    X[4].ps_nb = 5; 
    X[4].ps_pr = 2;

    X[5].ps_fs = 9; 
    X[5].ps_nb = nil; 
    X[5].ps_pr = 2;

    X[6].ps_fs = nil; 
    X[6].ps_nb = 7; 
    X[6].ps_pr = 3;

    X[7].ps_fs = nil; 
    X[7].ps_nb = 8; 
    X[7].ps_pr = 3;

    X[8].ps_fs = nil; 
    X[8].ps_nb = nil; 
    X[8].ps_pr = 3;

    X[9].ps_fs = nil; 
    X[9].ps_nb = 10; 
    X[9].ps_pr = 5;

    X[10].ps_fs = nil; 
    X[10].ps_nb = nil; 
    X[10].ps_pr = 5;
}

boolean IsEmpty (Isi_Tree P){
    return P[1].ps_fs == nil;
}

void PreOrder (Isi_Tree P){
    int indeks = 1 ;
    printf("%c ", P[indeks].info);
    for (int i = 1; i < 10; i++)
    {
        if (P[indeks].ps_fs == nil && P[indeks].ps_nb == nil)
        {
            while (P[indeks].ps_nb == nil)
            {
                indeks = P[indeks].ps_pr;
                if (indeks == 1)
                {
                    break;
                }
            }
            indeks = P[indeks].ps_nb;
            printf("=> %c ", P[indeks].info);

        }else{
            if (P[indeks].ps_fs != nil){
                printf("=> %c ",P[P[indeks].ps_fs].info );
                indeks = P[indeks].ps_fs;
            }
            else{
                if (P[indeks].ps_nb != nil){
                    printf("=> %c ", P[P[indeks].ps_nb].info);
                    indeks = P[indeks].ps_nb;
                }
            }
        }
    }
}

void InOrder (Isi_Tree P){
    int indeks = 1, ujungFS = 0, Arah = 0, count;
    for (int i = 0; i < 10; i++)
    {
        while (P[indeks].ps_fs != nil && !ujungFS)
        {
            indeks = P[indeks].ps_fs;
            count = 0;
        }
        ujungFS = 1;
        printf(" => %c", P[indeks].info);
        if (P[indeks].ps_fs == nil & P[indeks].ps_nb == nil)
        {
            while (P[indeks].ps_pr != nil && P[indeks].ps_nb == nil)
            {
                indeks = P[indeks].ps_pr;
            }
            indeks = P[indeks].ps_nb;
        }
        
        if (Arah != keatas)
        {   
            if (count >= 2 && P[indeks].ps_nb !=nil)
            {
                indeks = P[indeks].ps_nb;
            }
            else{
                indeks = P[indeks].ps_pr;
                Arah = keatas;
                count++;
            }
        }
        else{
            indeks = P[P[indeks].ps_fs].ps_nb;
            ujungFS = 0;
            Arah = kebawah;
            count++;
        }
    }
}

void PostOrder (Isi_Tree P){
    int indeks = 1, StopLoop = 0;

    for (int i = 0; i < 10; i++)
    {
        while (P[indeks].ps_fs != nil && !StopLoop)
        {
            indeks = P[indeks].ps_fs;
        }
        printf(" => %c", P[indeks].info);
        StopLoop = 1;

        if (P[indeks].ps_nb != nil)
        {   
            indeks = P[indeks].ps_nb;
            StopLoop = 0;
        }
        else if (P[indeks].ps_fs == nil)
        {
            indeks = P[indeks].ps_pr;
        }
        else{
            indeks = P[indeks].ps_pr;
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    int indeks[jml_maks + 1];
    int front = 0, rear = 0;

    if (X[1].info == '-') return;

    indeks[rear++] = 1;

    while (front < rear) {
        int current = indeks[front++];
        
        printf(" => %c", X[current].info);

        int Son = X[current].ps_fs;
        while (Son != nil) {
            indeks[rear++] = Son;
            Son = X[Son].ps_nb;
        }
    }

    printf("\n");
}


boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X && P[i].info != '-') {
            return true;
        }
    }
    return false;
}


int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int level[jml_maks + 1] = {0};
    int indeks[jml_maks + 1];
    int front = 0, rear = 0;

    indeks[rear++] = 1;

    while (front < rear) {
        int current = indeks[front++];

        if (P[current].info == X) {
            return level[current];
        }

        int Son = P[current].ps_fs;
        while (Son != nil) {
            level[Son] = level[current] + 1;
            indeks[rear++] = Son;
            Son = P[Son].ps_nb;
        }
    }
    return -1;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

int Depth(Isi_Tree P) {
    int maxDepth = 0;
    int level[jml_maks + 1] = {0};
    int queue[jml_maks + 1];
    int front = 0, rear = 0;

    if (P[1].info == '-') return 0;

    queue[rear++] = 1;

    while (front < rear) {
        int current = queue[front++];
        int child = P[current].ps_fs;

        while (child != nil) {
            level[child] = level[current] + 1;
            if (level[child] > maxDepth) {
                maxDepth = level[child];
            }
            queue[rear++] = child;
            child = P[child].ps_nb;
        }
    }

    return maxDepth;
}



void PrintTree (Isi_Tree P){
    for (int i = 1; i <= 10; i++)
    {
        printf("--> Indeks ke-%d = %c\n",i, P[i].info);
        printf("-------------------------------------------\n");
        printf("first son       : %d\n",P[i].ps_fs); 
        printf("next brother    : %d\n",P[i].ps_nb); 
        printf("Parent          : %d\n",P[i].ps_pr);
        printf("-------------------------------------------\n\n");
    }
}