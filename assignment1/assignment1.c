#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fd, n;
  int offset = sizeof("student.");
  char buffer[100];
  char change_line[] = "\n";
  char replaced_str[] = "NTHU student.";

  // print "student."
  fd = open("sample.txt", O_RDWR);
  lseek(fd, -offset, SEEK_END);
  read(fd, buffer, offset);
  write(1, buffer, offset);

  // change line only needed when test under mac osx
  // write(1, change_line, 2);

  // write replaced string to sample.txt
  lseek(fd, -offset, SEEK_END);
  write(fd, replaced_str, sizeof(replaced_str));

  // print sample.txt
  lseek(fd, 0, SEEK_SET);
  n = read(fd, buffer, 100);
  write(1, buffer, n);

  return 0;
}