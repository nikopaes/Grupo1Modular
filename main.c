#include <stdio.h>
#include <stdlib.h>
#include "professor.h"

int main(void){
	Prof *prof = NULL;
	criaProf(&prof, 123, "Flavio");
	mostraProf(prof);
	liberaProf(prof);
	return 0;
}
