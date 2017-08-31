#include <stdio.h>
#include <stdlib.h>
#include "professor.h"



int main(void){
	Prof *prof = NULL;
	PRF_tpCondRet var = criaProf(&prof);
	mostraProf(prof);
	liberaProf(prof);

	printf("%d\n", var);

	printf("FIM\n");
	return 0;
}
