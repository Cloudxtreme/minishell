/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:35:20 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 18:02:20 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <signal.h>

static t_signal_def	g_signals[] = {
	{0, NULL},
	{SIGHUP, "hangup"},
	{SIGINT, ""},
	{SIGQUIT, "quit"},
	{SIGILL, "illegal hardware instruction"},
	{SIGTRAP, "trace trap"},
	{SIGABRT, "abort"},
	{SIGFPE, "floating point exception"},
	{SIGKILL, "killed"},
	{SIGBUS, "bus error"},
	{SIGSEGV, "segmentation fault"},
	{SIGALRM, "alarm"},
	{SIGTERM, "terminated"},
	{SIGURG, "urgent condition"},
	{SIGSTOP, "suspended"},
	{SIGTSTP, "suspended (2)"},
	{SIGCONT, "continued"},
	{SIGCHLD, "child changed"},
	{SIGTTIN, "suspended (3)"},
	{SIGTTOU, "suspended (4)"},
	{SIGIO, "io possible"},
	{SIGXCPU, "cpu limit exceeded"},
	{SIGXFSZ, "file size limit exceeded"},
	{SIGVTALRM, "virtual time alarm"},
	{SIGPROF, "profiling timer alarm"},
	{SIGWINCH, "window size change"},
	{SIGUSR1, "user-defined signal 1"},
	{SIGUSR2, "user-defined signal 2"},

#ifdef __APPLE__

	{SIGEMT, "EMT instruction"},
	{SIGSYS, "invalid system call"},
	{SIGINFO, "keyboard status request"},

#endif
#ifdef LINUX

	{SIGIOT, "IOT trap"},

#endif

};
