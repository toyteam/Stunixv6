#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

char buf[512];

int copy(char * src, char *dest)
{
  int fd1;
  int fd2;
  int n;

  if((fd1 = open(src, O_RDONLY)) < 0)
  {
    printf(1, "cat: cannot open %s\n", src);
    return 1;
  }

  if((fd2 = open(dest, O_CREATE | O_WRONLY)) < 0)
  {
    printf(1, "cat: cannot open %s\n", dest);
    return 1;
  }
  
  while((n = read(fd1, buf, sizeof(buf))) > 0)
    write(fd2, buf, n);

  if(n < 0){
    printf(1, "cat: read error\n");
    return 1;
  }

  close(fd1);
  close(fd2);
  return 0;
}

int main(int argc, char *argv[])
{
  int i;
  
  if(argc<=1)
  {
    printf(1,"cp: missing file operand \n Try 'cp --help' for more information.\n");
  }
  else if(argc<=2)
  {
    printf(1,
       "cp: missing destination file operand after '%s' \n Try 'cp --help' for more information.",
       argv[1]);
  }
  else if(argc==3)
  {
    if(copy(argv[1],argv[2]))
    {
      printf(1,"cp:copy failed.");
    }
  }
  else
  {
    for(i=1;i<argc-1;++i)
    {
      if(copy(argv[i],argv[argc-1]))
      {
        printf(1,"cp:copy failed.");
      }
    }
  }
  

  exit();
}