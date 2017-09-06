#include <stdio.h>
#include <stdlib.h>
#include "professor.h"

#define MAX_PROFS 10

Prof *prof[5] = {NULL, NULL, NULL, NULL, NULL};

void fazSentido(void);

int main(void){
	//Prof *prof[MAX_PROFS];

	int i;
	PRF_tpCondRet var;
	//for(i=0; i<MAX_PROFS; i++) prof[i]=NULL;
	i=0;
	fazSentido();
	//var = criaProf(prof+i, 1613172, "666", "BraZilComZ", 15, 11, 1896);
	mostraProf(prof[i]);
	//alteraProf(prof, "felipe", "fse@gmail.com", 131312, 32342, "asdasdasas", 3123, 21, 4, 1924, 13123, 2123);
	alteraCpfProf(prof[i], "171");
	mostraProf(prof[i]);
	liberaProf(prof+i);
	printf("%d\n", prof==NULL);
	mostraProf(prof[i]);
	printf("FIM\n");
	return 0;
}

void fazSentido(void){
	criaProf(prof, 1613172, "666", "BraZilComZ", 15, 11, 1896);
}