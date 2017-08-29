#include "Prof.h"

void main(void)
{
	int i;
	int d;
	Prof* newProf;

	i = CadastraProfINT(newProf, 123456, "Flavio");

	if (i)
		printf("%d %s", newProf->matricula, newProf->nome);

	printf("NOT OK");

	scanf("%d", &d);
}