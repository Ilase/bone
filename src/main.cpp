#include <libssh/libssh.h>
#include <utility>
#include <stdlib.h>
#include <iostream>

int main()
{
  ssh_session my_ssh_session = ssh_new();
  if (my_ssh_session == NULL)
    {std::cout << "err";}
    else{
        std::cout << "eta";
    }

  ssh_free(my_ssh_session);
  
  return 0;
}