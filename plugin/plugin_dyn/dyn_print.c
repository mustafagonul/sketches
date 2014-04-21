typedef void (*print_func)(const char *);

static print_func callback = 0;

void dyn_register(print_func func)
{
  callback = func;
}

void dyn_print(const char *str)
{
  callback(str);
}



