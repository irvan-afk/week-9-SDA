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

    X[4].ps_fs = nil; 
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
    printf("%c", P[1].info);

    
}

void InOrder(Isi_Tree P) {
    int stack[jml_maks];
    int state[jml_maks];  // 0 = belum kunjungi anak, 1 = sudah
    int top = -1;

    int current = 1; // Asumsi node 1 adalah root

    while (current != nil || top != -1) {
        // Telusuri anak pertama ke dalam stack
        while (current != nil) {
            top++;
            stack[top] = current;
            state[top] = 0;
            current = P[current].ps_fs;
        }

        // Ambil dari stack
        current = stack[top];

        if (state[top] == 0) {
            // Cetak node (baru selesai anak pertama)
            printf("%c ", P[current].info);
            state[top] = 1;

            // Lanjutkan ke saudara anak pertama jika ada
            int child = P[current].ps_fs;
            if (child != nil) {
                current = P[child].ps_nb;
            } else {
                current = nil; // Tidak punya anak -> kosong
            }
        } else {
            // Sudah cetak dan kunjungi saudara, pop dari stack
            top--;
            current = nil;
        }
    }
}

void PostOrder (Isi_Tree P){
    int current = 1; // Asumsi node 1 adalah root
    boolean firstroot = false, edgestatus = false;
    while (firstroot == false){
        if (P[current].ps_fs != nil && edgestatus == false){
            current = P[current].ps_fs;
            if (P[current].ps_fs == nil){
                printf("%c ", P[current].info);
            } 
        }
        else{
            if (P[current].ps_nb != nil){
                current = P[current].ps_nb;
                if (P[current].ps_fs == nil){
                    printf("%c ", P[current].info);
                }
            } else {
                edgestatus = true;
                current = P[current].ps_pr;
                printf("%c ", P[current].info);
            }
            if (P[current].ps_pr == 1){
                firstroot = true;
                if (firstroot == true && P[current].ps_nb !=nil){
                    firstroot = false;
                    edgestatus = false;
                    current = P[current].ps_nb;
                }
            }
        }
    }
    printf("%c ", P[1].info);
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


void inorders(Isi_Tree P, int node) {
    if (node == nil) return;

    // Anak pertama
    if (P[node].ps_fs != nil)
        inorders(P, P[node].ps_fs);

    // Node itu sendiri
    printf("%c ", P[node].info);

    // Saudara dari anak pertama
    if (P[node].ps_fs != nil) {
        int sibling = P[P[node].ps_fs].ps_nb;
        while (sibling != nil) {
            inorders(P, sibling);
            sibling = P[sibling].ps_nb;
        }
    }
}