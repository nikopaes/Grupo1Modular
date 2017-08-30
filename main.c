#include <stdio.h>
#include <stdlib.h>
#include "professor.h"



int main(void){
	Prof *prof = NULL;
	tpCondRetProfessor var = criaProf(&prof, 123, "Flavio");
	mostraProf(prof);
	liberaProf(prof);
	printf("FIM\n");
	return 0;
}
