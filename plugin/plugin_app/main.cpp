#include <iostream>
#include <dlfcn.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef void (*print_func)(const char *);
typedef void (*register_func)(print_func func);
typedef void (*print_func)(const char *);

void dyn_register(print_func func);
void dyn_print(const char *);

#ifdef __cplusplus
}
#endif



#ifdef __cplusplus
extern "C" {
#endif

void print(const char *str)
{
  std::cout << str << std::endl;
}

#ifdef __cplusplus
}
#endif



int main()
{
  void *handle = dlopen("./../plugin_dyn/Debug/libplugin_dyn", RTLD_NOW | RTLD_GLOBAL);
  if (handle == 0)
    return -1;

  register_func r_func = (register_func) dlsym(handle, "dyn_register");
  if (r_func == 0)
    return -2;

  r_func(print);

  print_func p_func = (print_func) dlsym(handle, "dyn_print");
  if (p_func == 0)
    return -3;


  p_func("Hello World!");

  return 0;
}




