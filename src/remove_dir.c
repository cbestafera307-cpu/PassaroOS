
#include <PassaroOS/remove_dir.h>
#include <Uefi.h>

/* Implementação interna que apaga a pasta. */
EFI_STATUS uefi_remove_dir(const char *path);

int remove_dir(const char *path)
{
    if (path == 0 || path[0] == '\0')
        return -1;

    EFI_STATUS status = uefi_remove_dir(path);

    if (status == EFI_SUCCESS)
        return 0;

    return -1;
}
