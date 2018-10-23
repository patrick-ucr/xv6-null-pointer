#include "types.h"
#include "stat.h"
#include "user.h"
#define NULL ((void*)0)

char buf[512];

void
seeaddspace(int fd)
{
  int n;
  printf(1, "Opening the file null and printing it:\n");
  while((n = read(fd, buf, sizeof(buf))) > 0)
    write(1, buf, n);
  if(n < 0){
    printf(1, "seeaddspace: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd;
  char *nullfile = 0;
  //int fd = open(nullfile, 0644);
  if((fd = open(nullfile, 0)) < 0){
    printf(1, "seeaddspace: cannot open %s\n", nullfile);
    exit();
  }
  seeaddspace(fd);
  close(fd);
  exit();
}