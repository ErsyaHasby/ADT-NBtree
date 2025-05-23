// dibuat oleh Ersya Hasby Satria
// 241511072

#ifndef nbtrees_h
#define nbtrees_h

#include <stdio.h>
#include <stdbool.h>

#define jml_maks 20
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

typedef char infotype;
typedef int address;

typedef struct
{
    infotype info;
    address ps_fs; // first son
    address ps_nb; // next brother
    address ps_pr; // parent
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

// Konstruktor dan kondisi dasar
void Create_tree(Isi_Tree X, int Jml_Node);
bool IsEmpty(Isi_Tree P);

// Traversal
void PreOrder(Isi_Tree P, int root);
void InOrder(Isi_Tree P, int root);
void PostOrder(Isi_Tree P, int root);
void Level_order(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P);

// Search & Informasi
bool Search(Isi_Tree P, infotype X);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P, int root);
int Max(infotype Data1, infotype Data2);

#endif
