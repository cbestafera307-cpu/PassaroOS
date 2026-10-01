void print(const char *msg);
void printk(const char *msg) {
  print("KERNEL MESSAGE: );
  print(msg);
}
void error(const char *msg) {
  print("ERROR: ");
  print(msg);
}
void warning(const char *msg) {
  print("WARNING: ");
  print(msg);
}
void memoryerror(const char *msg) {
  print("MEMORY_ERROR: ");
  print(msg);
}
