int received; //see how to handle this

void  ft_sendcbyc(char c, int pid)
{
  int i;
  
  i = 128; //see why
  while (i >= 1)
  {
    if (received == 1)
    {
      if (i & c)
         if (kill(pid, SIGUSR1) == -1)
           ft_error(1); // should quit n printf something saying there was an issue sending sig
         else
         {
          if (kill(pid, SIGUSR2) == -1)
            ft_error(1); // same than the one on top
         }
         i /= 2;
         received = 0;
    }
    usleep(1000);// --> it's maybe there we have to input usleep 1000
  }
}

int ft_client(int pid, char *str)
{
  int i;
  
  i = 0;
  while (str[i])
  {
      ft_sendcbyc(str[i], pid);
      i++;
  }
  return (0);
}

void    ft_proto(int signum, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)siginfo;
    (void)signum;
    received = 1;
    write(1, "Recieved signal from server\n", 28);
    return ;
}

int main(int argc, char **argv)
{
    struct sigaction    sigac;

    received = 1;
    sigemptyset(&sigac.sa_mask);
    sigaddset(&sigac.sa_mask, SIGINT);
    sigaddset(&sigac.sa_mask, SIGQUIT);
    sigaddset(&sigac.sa_mask, SIGUSR1);
    sigac.sa_flags = SA_SIGINFO;
    sigac.sa_sigaction = ft_proto;
    if (sigaction(SIGUSR2, &sigac, NULL) == -1)
        ft_errors("Error in client sigaction\n");
    if (ft_atoi(argv[1]) < 0)
        ft_errors("Wrong PID!\n");
    if (argc == 3)
        ft_client(ft_atoi(argv[1]), argv[2]);
    else
        errors("Wrong arguments!\n");
    while (1)
        sleep (5);
    return (0);
}
