#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

char buf[DIRSIZ];

int main(int argc, char *argv[])
{
  if(getcwd(buf, DIRSIZ))
    printf(1, "%s\n", buf);
  else
    printf(1,"%s\n","The path is too long.");

  exit();
}