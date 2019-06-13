#pragma once
#ifndef FILE_H
#define FILE_H
char inadress[20], outadress[20];
int weight[256] = { 0 };

struct HTNode {
	int parent;
	int weight;
	int lchild;
	int rchild;
}node[256 * 2 - 1];
#endif