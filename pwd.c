#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

char buf[DIRSIZ];

int main(int argc, char *argv[])
{
  getcwd(buf, DIRSIZ);
  printf(1, "%s", buf);

  exit();
}