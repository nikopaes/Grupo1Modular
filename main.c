#include <stdio.h>
#include <stdlib.h>
#include "professor.h"

int main(void){
	Prof *prof = NULL;
	PRF_tpCondRet var = criaProf(&prof);
	mostraProf(prof);
	atualizaProf(prof, "felipe", "fse@gmail.com", 131312, 32342, "asdasdasas", 3123, 21, 4, 1924, 13123, 2123);
	mostraProf(prof);
	liberaProf(prof);
	printf("FIM\n");
	return 0;
}