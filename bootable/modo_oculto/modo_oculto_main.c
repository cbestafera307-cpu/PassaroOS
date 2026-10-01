#include <PassaroOS/print.h>
#include <PassaroOS/osconfig.h>
#include <stdio.h>
kprintf("OS NAME: %s", OS_NAME);
print("1: ROOT");
print("2: RESET");
print("escolha um");
int opc;
scanf("%d", &opc);
