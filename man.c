#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void read_doc(int fd){
  int n;
  
  while((n = read(fd, buf, sizeof(buf))) > 0)
    write(1, buf, n);
  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }
}

int main(int argc, char *argv[])
{
  int fd;
  int i=0;
  if(argc == 1){
      printf(1, "%s", "What manual page do you want?\n");
  }else{
    for(i = 1; i < argc; ++i){
      if((fd = open(argv[i], 0)) < 0){
        printf(1, "man: cannot open %s\n", argv[i]);
        exit();
      }

      read_doc(fd);
    }
  }


  exit();
}
