#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>



/*char * permissions_str(int n) {
  char ret[9];
  }*/

void print_metadata(char * name) {

  struct stat data;
  stat(name,&data);
  printf("%s metadata\n",name);
  printf("size: %lld bytes\n",data.st_size);
  printf("permissions: %o\n",data.st_mode);
  printf("last access time: %s",ctime( &(data.st_atime)));
  printf("last modification time: %s",ctime( &(data.st_mtime)));
  

}

int main() {

  int fd;
  fd=open("foo",O_CREAT | O_WRONLY , 0644);
  char s[] = "Hello world";
  write(fd,s,sizeof(s));
  close(fd);

  print_metadata("foo");

  return 0;
}
