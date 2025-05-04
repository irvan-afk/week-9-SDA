#include "nbtree.h"

void Create_tree(Isi_Tree X, int Jml_Node){

    char karakter = 'A';
    int i = 1, ascii = (int)karakter;

    while (i <= Jml_Node )
    {
        X[i].info = ascii;
        ascii++;
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

    X[5].ps_fs = nil; 
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
    printf("%c", P[1].info);

    
}

void InOrder (Isi_Tree P){
    int penampung = 1;
    int fsroot, p2;
    int tf;
    while (penampung != nil)
    {
        if (P[penampung].ps_fs != nil)
        {
            penampung = P[penampung].ps_fs;
            // Pengecekan apakah parent dari penampung adalah root
            if (P[penampung].ps_pr == 1)
            {
                fsroot = penampung;
            }
        }
        else
        {
            p2 = penampung;
            while (P[p2].ps_pr != 1)
            {
                if (P[p2].ps_pr == 1 && tf == 1)
                {

                }
                else
                {
                    printf("%c", P[p2].info);
                }
                if (P[p2].ps_pr == 1)
                {
                    tf = 1;
                }
                    p2 = P[p2].ps_pr;
             }
            if (P[penampung].ps_nb != nil)
            {
                penampung = P[penampung].ps_nb;
            }
        }
    }
}

void PrintTree (Isi_Tree P){
    for (int i = 1; i <= 10; i++)
    {
        printf("%c ", P[i].info);
        printf("%d ",P[i].ps_fs); 
        printf("%d ",P[i].ps_nb); 
        printf("%d\n\n",P[i].ps_pr);
    }
    
}
