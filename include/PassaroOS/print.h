void print(const char *msg);
void printk(const char *msg) {
  print("KERNEL MESSAGE: %s", msg);
}
