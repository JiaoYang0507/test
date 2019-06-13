
#include <stdio.h>
#include <stdlib.h>
#include"card.h"
#include "carFile.h"
#include"menu.h"
int main() {
	initial();
	getfile();
	outputMenu();
	savefile();
	return  0;
}