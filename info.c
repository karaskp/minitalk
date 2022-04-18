/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:31:37 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 13:44:24 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	write
	ft_printf

	sighandler_t	signal(int signum, sighandler_t handler);
			sighandler_t are basicly (void handler(int signum){...})

	int	sigemptyset(sigset_t *set);
		initializes the signal set given by set to empty

	int	sigaddset(sigset_t *set, int signum);
		add signal signum from *set

	int	sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
			sigaction struct be like :
			struct sigaction
			{
				void	(*sa_handler)(int);
				void	(*sa_sigaction)(int, siginfo_t *, void *);
				sigset_t	sa_mask;
				int	sa_flags;
			}
		sa_flags = set of flags modifying the behaviour of signal formed by bitwise 
				or 0 or a list of flags
		siginfo_t =
			siginfo_t {
    				int      si_signo;     Signal number 
  				int      si_errno;     An errno value
    				int      si_code;      Signal code 
    				int      si_trapno;    Trap number that caused
                             				hardware-generated signal
                            				 (unused on most architectures) 
    				pid_t    si_pid;       Sending process ID 
    				uid_t    si_uid;       Real user ID of sending process 
    				int      si_status;    Exit value or signal 
				clock_t  si_utime;     User time consumed 
    				clock_t  si_stime;     System time consumed 
    				sigval_t si_value;     Signal value 
    				int      si_int;       POSIX.1b signal 
    				void    *si_ptr;       POSIX.1b signal 
    				int      si_overrun;   Timer overrun count; POSIX.1b timers 
    				int      si_timerid;   Timer ID; POSIX.1b timers 
    				void    *si_addr;      Memory location which caused fault 
    				long     si_band;      Band event (was int in
                             				glibc 2.3.2 and earlier) 
    				int      si_fd;        File descriptor 
    				short    si_addr_lsb;  Least significant bit of address
                             				(since kernel 2.6.32) 
				}
	int	kill(pid_t pid, int sig);
		if pid > 0 --> sig sent to the id of pid
		if pid == 0 --> sig sent to every process of the group
		if pid == -1 --> sig sent to evry process with permission
		if sig == 0 --> no signal sent but error check performed
		(peut permettre de test la validite du PID)
		returns 0 on success, -1 on error 
		ex = kill(getpid(), SIGUSR1);
	getpid
	malloc
	free
	pause
	sleep
	usleep
	exit
	
	2 exec = client et server
	1 globale autorisée par exec (1 client 1 server)
	
	server = lancé en premier, affiche son PID
	client = 2 param : le PID du server, une str a transmettre
		il doit comm au server la chaine qu'il a en param
	server = reçoit la chaine puis l'affiche (rapidement)
		doit pouvoir recevoir str de plsrs clients sans restart
	les exec doivent communiquer ensemble uniquement avec sign UNIX
	SIGUSR1 & SIGUSR2
		(sont emis par user process, provoque une terminaison)

	(linux ne met pas les signaux en file d'attente qd on a deja un 
	signal en attente du meme type)
*/
