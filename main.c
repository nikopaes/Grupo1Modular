#include <stdio.h>
#include <stdlib.h>
#include "professor.h"

int main(void){
	Prof *prof = NULL;
	PRF_tpCondRet var = criaProf(&prof, 1613172, "BraZilComZ", 15, 11, 1896);
	mostraProf(prof);
	//alteraProf(prof, "felipe", "fse@gmail.com", 131312, 32342, "asdasdasas", 3123, 21, 4, 1924, 13123, 2123);
	alteraCpfProf(prof, 2713161);
	mostraProf(prof);
	liberaProf(&prof);
	printf("%d\n", prof==NULL);
	mostraProf(prof);
	printf("FIM\n");
	return 0;
}