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
	printf("hello world\n");
	var = PRF_cria( prof+i, "Bruce" , 111222333, "12345678901", 1112223, "bmMail@mail", 111222333, 11, 12, 2196, "BrasilComS", "RJ", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	PRF_mostra(prof[i]);
	//alteraProf(prof, "felipe", "fse@gmail.com", 131312, 32342, "asdasdasas", 3123, 21, 4, 1924, 13123, 2123);
	printf("vamos alterar cpf");
	PRF_alteraCpf(prof[i], "10987654321");
	//printf("%d\n", );
	PRF_alteraCpf(prof[i], "s");
	PRF_mostra(prof[i]);
	PRF_libera(prof+i);
	PRF_mostra(prof[i]);
	printf("FIM\n");
	return 0;
}
