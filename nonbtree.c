#include "nonbtree.h"

void Create_tree(Isi_Tree X, int Jml_Node)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        X[i].info = '\0';
        X[i].ps_fs = X[i].ps_nb = X[i].ps_pr = 0;
    }

    for (int i = 1; i <= Jml_Node; i++)
    {
        printf("Masukkan info untuk node %d: ", i);
        scanf(" %c", &X[i].info);

        if (i == 1)
        {
            X[i].ps_pr = 0; // root tidak punya parent
        }
        else
        {
            printf("Masukkan parent untuk node '%c' (index 1..%d): ", X[i].info, i - 1);
            scanf("%d", &X[i].ps_pr);
        }

        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
    }

    // Set hubungan anak dan saudara
    for (int i = 2; i <= Jml_Node; i++)
    {
        int parent = X[i].ps_pr;
        if (X[parent].ps_fs == 0)
        {
            X[parent].ps_fs = i;
        }
        else
        {
            int sibling = X[parent].ps_fs;
            while (X[sibling].ps_nb != 0)
                sibling = X[sibling].ps_nb;
            X[sibling].ps_nb = i;
        }
    }
}

bool IsEmpty(Isi_Tree P)
{
    return P[1].info == '\0';
}

void PreOrder(Isi_Tree P, int root)
{
    if (root == 0 || P[root].info == '\0')
        return;
    printf("%c ", P[root].info);
    PreOrder(P, P[root].ps_fs);
    PreOrder(P, P[root].ps_nb);
}

void InOrder(Isi_Tree P, int root)
{
    if (root == 0 || P[root].info == '\0')
        return;
    int child = P[root].ps_fs;
    if (child != 0)
    {
        InOrder(P, child);
        child = P[child].ps_nb;
    }
    printf("%c ", P[root].info);
    while (child != 0)
    {
        InOrder(P, child);
        child = P[child].ps_nb;
    }
}

void PostOrder(Isi_Tree P, int root)
{
    if (root == 0 || P[root].info == '\0')
        return;
    PostOrder(P, P[root].ps_fs);
    PostOrder(P, P[root].ps_nb);
    printf("%c ", P[root].info);
}

void Level_order(Isi_Tree X, int Maks_node)
{
    for (int i = 1; i <= Maks_node; i++)
    {
        if (X[i].info != '\0')
            printf("%c ", X[i].info);
    }
}

void PrintTree(Isi_Tree P)
{
    printf("Index\tInfo\tFS\tNB\tPR\n");
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != '\0')
        {
            printf("%d\t%c\t%d\t%d\t%d\n", i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
        }
    }
}

bool Search(Isi_Tree P, infotype X)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
            return true;
    }
    return false;
}

int nbElmt(Isi_Tree P)
{
    int count = 0;
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != '\0')
            count++;
    }
    return count;
}

int nbDaun(Isi_Tree P)
{
    int count = 0;
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != '\0' && P[i].ps_fs == 0)
            count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            int level = 0;
            int p = i;
            while (P[p].ps_pr != 0)
            {
                level++;
                p = P[p].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P, int root)
{
    if (root == 0 || P[root].info == '\0')
        return 0;
    int max_depth = 0;
    int child = P[root].ps_fs;
    while (child != 0)
    {
        int d = Depth(P, child);
        if (d > max_depth)
            max_depth = d;
        child = P[child].ps_nb;
    }
    return max_depth + 1;
}

int Max(infotype Data1, infotype Data2)
{
    return (Data1 > Data2) ? Data1 : Data2;
}
