
#include <PassaroOS/create_dir.h>
#include <Uefi.h>
#include <Protocol/SimpleFileSystem.h>

extern EFI_FILE_PROTOCOL *gRoot;

int create_dir(const char *path)
{
    if (path == 0 || path[0] == '\0' || gRoot == 0)
        return -1;

    /* Converte ASCII para o formato de texto UEFI. */
    UINTN len = 0;
    while (path[len] != '\0')
        len++;

    CHAR16 *uefi_path = AllocateZeroPool(
        (len + 1) * sizeof(CHAR16)
    );

    if (uefi_path == 0)
        return -1;

    for (UINTN i = 0; i < len; i++) {
        char c = path[i];
        uefi_path[i] = (c == '/') ? L'\\' : (CHAR16)c;
    }

    EFI_FILE_PROTOCOL *dir = 0;

    EFI_STATUS status = gRoot->Open(
        gRoot,
        &dir,
        uefi_path,
        EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE |
            EFI_FILE_MODE_CREATE,
        EFI_FILE_DIRECTORY
    );

    if (!EFI_ERROR(status) && dir != 0)
        dir->Close(dir);

    FreePool(uefi_path);

    return EFI_ERROR(status) ? -1 : 0;
}
