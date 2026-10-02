#include <PassaroOS/osconfig.h>
#include <create_dir.h>
#include <remove_dir.h>

void root() {
 root = 1;
}
void reset() {
  remove_dir("storage/");
  create_dir("storage/");
  create_dir("storage/fotos/");
  create_dir("storage/docs/");
  create_dir("storage/bin/");
}
