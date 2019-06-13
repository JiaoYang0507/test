#include "huffman.h"
#include "file.h"

void creatnode()
{
	for (int i = 0; i < 256; i++)
	{
		node[i].lchild = -1;
		node[i].rchild = -1;
		node[i].parent = -1;
		node[i].weight = weight[i];
	}
	for (int i = 256; i < 511; i++)
	{
		node[i].lchild = -1;
		node[i].rchild = -1;
		node[i].parent = -1;
		node[i].weight = 0;
	}
}

void creattree()
{
	;
	int n;
	for (int i = 256; i < 511; i++) {
		int s1, s2;
		selectmin(i, s1, s2);
		node[i].lchild = s1;
		node[i].rchild = s2;
		node[i].weight = node[s1].weight + node[s2].weight;
		node[s1].parent = i;
		node[s2].parent = i;
	}
}

void selectmin(int n, int& s1, int& s2) {
	int min = 0x7FFFFFFF;
	for (int i = 0; i < n; i++)
		if (node[i].parent == -1 && node[i].weight < min)
		{
			min = node[i].weight;
			s1 = i;
		}
	for (int i = 0; i < n; i++)
		if (i != s1 && node[i].parent == -1 && node[i].weight < min)
		{
			min = node[i].weight;
			s2 = i;
		}
}