#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int socketFd;
  struct sockaddr_un socketAddress;
  int bufferSize = 256;
  char buffer[bufferSize];

  /* Initialize the sockaddr_un struct */
  socketAddress.sun_family = AF_UNIX;
  strcpy(socketAddress.sun_path, argv[1]);

  /* Setup the socket, Connect, and Send the send CL Arg */
  socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
  connect(socketFd, (struct sockaddr *)&socketAddress, sizeof(socketAddress));
  send(socketFd, argv[2], strlen(argv[2]), 0);

  /* Check if we recieved a response */
  while (recv(socketFd, buffer, sizeof(buffer), 0) > 0) {
    buffer[sizeof(buffer)] = '\0';
    printf("%s", buffer);
  }

  /* Close and return */
  printf("\n");
  close(socketFd);
  return 0;
}
