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
	for(i=0; i<MAX_PROFS; i++) prof[i]=NULL;
	i=0;
	var = PRF_cria(prof+i, 1613172, "12345678901", "BraZilComZ", 15, 11, 2196);
	PRF_mostra(prof[i]);
	//alteraProf(prof, "felipe", "fse@gmail.com", 131312, 32342, "asdasdasas", 3123, 21, 4, 1924, 13123, 2123);
	printf("vamos alterar cpf");
	printf("%d\n", PRF_alteraCpf(prof[i], "10987654321"));
	PRF_mostra(prof[i]);
	PRF_libera(prof+i);
	printf("%d\n", prof==NULL);
	PRF_mostra(prof[i]);
	printf("FIM\n");
	return 0;
}
