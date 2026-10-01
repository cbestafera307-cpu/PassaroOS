#include <PassaroOS/print.h>
#include <PassaroOS/osconfig.h>
#include "modo_oculto_funcs.h"
#include <stdio.h>
kprintf("OS NAME: %s", OS_NAME);
print("1: ROOT");
print("2: RESET");
print("escolha um");
int opc;
scanf("%d", &opc);
if (opc == 1) {
        root();
    }
    else if (opc == 2) {
        reset();
    }
    else {
        print("NAO SUPORTADO. TENTE NOVAMENTE");
    }
