#include <stdio.h>
#include "nonbtree.h"

int main()
{
    Isi_Tree P = {0};
    int Jml_Node;
    int pilihan;
    char cari, d1, d2;

    printf("Masukkan jumlah node: ");
    scanf("%d", &Jml_Node);

    Create_tree(P, Jml_Node);

    do
    {
        printf("\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("PreOrder: ");
            PreOrder(P, 1);
            printf("\n");
            break;
        case 2:
            printf("InOrder: ");
            InOrder(P, 1);
            printf("\n");
            break;
        case 3:
            printf("PostOrder: ");
            PostOrder(P, 1);
            printf("\n");
            break;
        case 4:
            printf("Level Order: ");
            Level_order(P, Jml_Node);
            printf("\n");
            break;
        case 5:
            PrintTree(P);
            break;
        case 6:
            printf("Masukkan karakter node yang dicari: ");
            scanf(" %c", &cari);
            if (Search(P, cari))
                printf("Node ditemukan.\n");
            else
                printf("Node tidak ditemukan.\n");
            break;
        case 7:
            printf("Jumlah daun: %d\n", nbDaun(P));
            break;
        case 8:
            printf("Masukkan karakter node yang ingin dicek levelnya: ");
            scanf(" %c", &cari);
            printf("Level node %c: %d\n", cari, Level(P, cari));
            break;
        case 9:
            printf("Kedalaman tree: %d\n", Depth(P, 1));
            break;
        case 10:
            printf("Masukkan dua karakter node: ");
            scanf(" %c %c", &d1, &d2);
            printf("Nilai maksimum dari '%c' dan '%c' adalah '%c'\n", d1, d2, Max(d1, d2));
            break;
        case 11:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 11);

    return 0;
}
