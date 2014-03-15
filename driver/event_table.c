/*

 














*/

#include "ppm_events_public.h"

const struct ppm_event_info g_event_info[PPM_EVENT_MAX] =
{
	/* PPME_GENERIC_E */{"syscall", EC_OTHER, EF_NONE, 2, {{"ID", PT_SYSCALLID, PF_DEC}, {"nativeID", PT_UINT16, PF_DEC}}},
	/* PPME_GENERIC_X */{"syscall", EC_OTHER, EF_NONE, 1, {{"ID", PT_SYSCALLID, PF_DEC}}},
	/* PPME_SYSCALL_OPEN_E */{"open", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SYSCALL_OPEN_X */{"open", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"fd", PT_FD, PF_DEC}, {"name", PT_FSPATH, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, file_flags}, {"mode", PT_UINT32, PF_HEX}}},
	/* PPME_SYSCALL_CLOSE_E */{"close", EC_IO_OTHER, (ppm_event_flags)(EF_DESTROYS_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_CLOSE_X */{"close", EC_IO_OTHER, (ppm_event_flags)(EF_DESTROYS_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_READ_E */{"read", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_READ_X */{"read", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_WRITE_E */{"write", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_WRITE_X */{"write", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_BRK_E */{"brk", EC_MEMORY, EF_NONE, 1, {{"size", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_BRK_X */{"brk", EC_MEMORY, EF_NONE, 1, {{"res", PT_UINT64, PF_HEX}}},
	/* PPME_SYSCALL_EXECVE_E */{"execve", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_EXECVE_X */{"execve", EC_PROCESS, EF_MODIFIES_STATE, 8, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC}}},
	/* PPME_CLONE_E */{"clone", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_CLONE_X */{"clone", EC_PROCESS, EF_MODIFIES_STATE, 11, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC}}},
	/* PPME_PROCEXIT_E */{"procexit", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_NA1 */{"NA1", EC_PROCESS, EF_UNUSED, 0},
	/* PPME_SOCKET_SOCKET_E */{"socket", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"domain", PT_FLAGS32, PF_DEC, socket_families}, {"type", PT_UINT32, PF_DEC}, {"proto", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_SOCKET_X */{"socket", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SOCKET_BIND_E */{"bind", EC_NET, EF_USES_FD, 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SOCKET_BIND_X */{"bind", EC_NET, EF_USES_FD, 2, {{"res", PT_ERRNO, PF_DEC}, {"addr", PT_SOCKADDR, PF_NA}}},
	/* PPME_SOCKET_CONNECT_E */{"connect", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SOCKET_CONNECT_X */{"connect", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"res", PT_ERRNO, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}}},
	/* PPME_SOCKET_LISTEN_E */{"listen", EC_NET, EF_USES_FD, 2, {{"fd", PT_FD, PF_DEC}, {"backlog", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_LISTEN_X */{"listen", EC_NET, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SOCKET_ACCEPT_E */{"accept", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SOCKET_ACCEPT_X */{"accept", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}, {"queuepct", PT_UINT8, PF_DEC}}},
	/* PPME_SYSCALL_SEND_E */{"send", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_SEND_X */{"send", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_SENDTO_E */{"sendto", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}}},
	/* PPME_SOCKET_SENDTO_X */{"sendto", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_RECV_E */{"recv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_RECV_X */{"recv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_RECVFROM_E */{"recvfrom", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_RECVFROM_X */{"recvfrom", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}, {"tuple", PT_SOCKTUPLE, PF_NA}}},
	/* PPME_SOCKET_SHUTDOWN_E */{"shutdown", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"fd", PT_FD, PF_DEC}, {"how", PT_FLAGS8, PF_HEX, shutdown_how}}},
	/* PPME_SOCKET_SHUTDOWN_X */{"shutdown", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SOCKET_GETSOCKNAME_E */{"getsockname", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETSOCKNAME_X */{"getsockname", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETPEERNAME_E */{"getpeername", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETPEERNAME_X */{"getpeername", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_SOCKETPAIR_E */{"socketpair", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"domain", PT_FLAGS32, PF_DEC, socket_families}, {"type", PT_UINT32, PF_DEC}, {"proto", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_SOCKETPAIR_X */{"socketpair", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 5, {{"res", PT_ERRNO, PF_DEC}, {"fd1", PT_FD, PF_DEC}, {"fd2", PT_FD, PF_DEC}, {"source", PT_UINT64, PF_HEX},{"peer", PT_UINT64, PF_HEX}}},
	/* PPME_SOCKET_SETSOCKOPT_E */{"setsockopt", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"level", PT_UINT16, PF_DEC}, {"optname", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_SETSOCKOPT_X */{"setsockopt", EC_NET, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"res", PT_ERRNO, PF_DEC}, {"optval", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_GETSOCKOPT_E */{"getsockopt", EC_NET, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"level", PT_UINT16, PF_DEC}, {"optname", PT_UINT32, PF_DEC}}},
	/* PPME_SOCKET_GETSOCKOPT_X */{"getsockopt", EC_NET, EF_USES_FD, 2, {{"res", PT_ERRNO, PF_DEC}, {"optval", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_SENDMSG_E */{"sendmsg", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}}},
	/* PPME_SOCKET_SENDMSG_X */{"sendmsg", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SOCKET_SENDMMSG_E */{"sendmmsg", EC_IO_WRITE, EF_NONE, 0},
	/* PPME_SOCKET_SENDMMSG_X */{"sendmmsg", EC_IO_WRITE, EF_NONE, 0},
	/* PPME_SOCKET_RECVMSG_E */{"recvmsg", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SOCKET_RECVMSG_X */{"recvmsg", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 4, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}, {"tuple", PT_SOCKTUPLE, PF_NA}}},
	/* PPME_SOCKET_RECVMMSG_E */{"recvmmsg", EC_IO_READ, EF_NONE, 0},
	/* PPME_SOCKET_RECVMMSG_X */{"recvmmsg", EC_IO_READ, EF_NONE, 0},
	/* PPME_SOCKET_ACCEPT4_E */{"accept", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"flags", PT_INT32, PF_HEX}}},
	/* PPME_SOCKET_ACCEPT4_X */{"accept", EC_NET, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}, {"queuepct", PT_UINT8, PF_DEC}}},
	/* PPME_SYSCALL_CREAT_E */{"creat", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SYSCALL_CREAT_X */{"creat", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"name", PT_FSPATH, PF_NA}, {"mode", PT_UINT32, PF_HEX}}},
	/* PPME_SOCKET_PIPE_E */{"pipe", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SOCKET_PIPE_X */{"pipe", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"res", PT_ERRNO, PF_DEC}, {"fd1", PT_FD, PF_DEC}, {"fd2", PT_FD, PF_DEC}, {"ino", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_EVENTFD_E */{"eventfd", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 2, {{"initval", PT_UINT64, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX}}},
	/* PPME_SYSCALL_EVENTFD_X */{"eventfd", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_FUTEX_E */{"futex", EC_IPC, EF_NONE, 3, {{"addr", PT_UINT64, PF_HEX}, {"op", PT_FLAGS16, PF_HEX, futex_operations}, {"val", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_FUTEX_X */{"futex", EC_IPC, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_STAT_E */{"stat", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_STAT_X */{"stat", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_LSTAT_E */{"lstat", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_LSTAT_X */{"lstat", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_FSTAT_E */{"fstat", EC_FILE, EF_USES_FD, 1, {{"fd", PT_FD, PF_NA}}},
	/* PPME_SYSCALL_FSTAT_X */{"fstat", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_STAT64_E */{"stat64", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_STAT64_X */{"stat64", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_LSTAT64_E */{"lstat64", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_LSTAT64_X */{"lstat64", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_FSTAT64_E */{"fstat64", EC_FILE, EF_USES_FD, 1, {{"fd", PT_FD, PF_NA}}},
	/* PPME_SYSCALL_FSTAT64_X */{"fstat64", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_EPOLLWAIT_E */{"epoll_wait", EC_WAIT, EF_NONE, 1, {{"maxevents", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_EPOLLWAIT_X */{"epoll_wait", EC_WAIT, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_POLL_E */{"poll", EC_WAIT, EF_NONE, 2, {{"fds", PT_FDLIST, PF_DEC}, {"timeout", PT_INT64, PF_DEC}}},
	/* PPME_SYSCALL_POLL_X */{"poll", EC_WAIT, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"fds", PT_FDLIST, PF_DEC}}},
	/* PPME_SYSCALL_SELECT_E */{"select", EC_WAIT, EF_NONE, 0},
	/* PPME_SYSCALL_SELECT_X */{"select", EC_WAIT, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_NEWSELECT_E */{"newselect", EC_WAIT, EF_NONE, 0},
	/* PPME_SYSCALL_NEWSELECT_X */{"newselect", EC_WAIT, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_LSEEK_E */{"lseek", EC_FILE, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC}, {"whence", PT_FLAGS8, PF_DEC, lseek_whence}}},
	/* PPME_SYSCALL_LSEEK_X */{"lseek", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_LLSEEK_E */{"llseek", EC_FILE, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC}, {"whence", PT_FLAGS8, PF_DEC, lseek_whence}}},
	/* PPME_SYSCALL_LLSEEK_X */{"llseek", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_IOCTL_E */{"ioctl", EC_IO_OTHER, EF_USES_FD, 2, {{"fd", PT_FD, PF_DEC}, {"request", PT_UINT64, PF_HEX}}},
	/* PPME_SYSCALL_IOCTL_X */{"ioctl", EC_IO_OTHER, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_GETCWD_E */{"getcwd", EC_FILE, EF_NONE, 0},
	// Note: path is PT_CHARBUF and not PT_FSPATH because we assume it's abosulte and will never need resolution
	/* PPME_SYSCALL_GETCWD_X */{"getcwd", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_CHARBUF, PF_NA}}},
	// Note: path is PT_CHARBUF and not PT_FSPATH because we don't want it to be resolved, since the event handler already changes it
	/* PPME_SYSCALL_CHDIR_E */{"chdir", EC_FILE, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_CHDIR_X */{"chdir", EC_FILE, EF_MODIFIES_STATE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_CHARBUF, PF_NA}}},
	/* PPME_SYSCALL_FCHDIR_E */{"fchdir", EC_FILE, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_NA}}},
	/* PPME_SYSCALL_FCHDIR_X */{"fchdir", EC_FILE, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_MKDIR_E */{"mkdir", EC_FILE, EF_NONE, 2, {{"path", PT_FSPATH, PF_NA}, {"mode", PT_UINT32, PF_HEX}}},
	/* PPME_SYSCALL_MKDIR_X */{"mkdir", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_RMDIR_E */{"rmdir", EC_FILE, EF_NONE, 1, {{"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_RMDIR_X */{"rmdir", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_OPENAT_E */{"openat", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"dirfd", PT_FD, PF_DEC}, {"name", PT_CHARBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, openat_flags}, {"mode", PT_UINT32, PF_HEX}}},
	/* PPME_SYSCALL_OPENAT_X */{"openat", EC_FILE, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_LINK_E */{"link", EC_FILE, EF_NONE, 2, {{"oldpath", PT_FSPATH, PF_NA}, {"newpath", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_LINK_X */{"link", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_LINKAT_E */{"linkat", EC_FILE, EF_NONE, 4, {{"olddir", PT_FD, PF_DEC}, {"oldpath", PT_CHARBUF, PF_NA}, {"newdir", PT_FD, PF_DEC}, {"newpath", PT_CHARBUF, PF_NA}}},
	/* PPME_SYSCALL_LINKAT_X */{"linkat", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_UNLINK_E */{"unlink", EC_FILE, EF_NONE, 1, {{"path", PT_FSPATH, PF_NA}}},
	/* PPME_SYSCALL_UNLINK_X */{"unlink", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_UNLINKAT_E */{"unlinkat", EC_FILE, EF_NONE, 2, {{"dirfd", PT_FD, PF_DEC}, {"name", PT_CHARBUF, PF_NA}}},
	/* PPME_SYSCALL_UNLINKAT_X */{"unlinkat", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_PREAD_E */{"pread", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_PREAD_X */{"pread", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_PWRITE_E */{"pwrite", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_PWRITE_X */{"pwrite", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_READV_E */{"readv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_READV_X */{"readv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_WRITEV_E */{"writev", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_WRITEV_X */{"writev", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_PREADV_E */{"preadv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"pos", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_PREADV_X */{"preadv", EC_IO_READ, (ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_PWRITEV_E */{"pwritev", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC}}},
	/* PPME_SYSCALL_PWRITEV_X */{"pwritev", EC_IO_WRITE, (ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}}},
	/* PPME_SYSCALL_DUP_E */{"dup", EC_IO_OTHER, (ppm_event_flags)(EF_CREATES_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_DUP_X */{"dup", EC_IO_OTHER, (ppm_event_flags)(EF_CREATES_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_SIGNALFD_E */{"signalfd", EC_SIGNAL, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"mask", PT_UINT32, PF_HEX}, {"flags", PT_FLAGS8, PF_HEX}}},
	/* PPME_SYSCALL_SIGNALFD_X */{"signalfd", EC_SIGNAL, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_KILL_E */{"kill", EC_SIGNAL, EF_NONE, 2, {{"pid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC}}},
	/* PPME_SYSCALL_KILL_X */{"kill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_TKILL_E */{"tkill", EC_SIGNAL, EF_NONE, 2, {{"tid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC}}},
	/* PPME_SYSCALL_TKILL_X */{"tkill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_TGKILL_E */{"tgkill", EC_SIGNAL, EF_NONE, 3, {{"pid", PT_PID, PF_DEC}, {"tid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC}}},
	/* PPME_SYSCALL_TGKILL_X */{"tgkill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_NANOSLEEP_E */{"nanosleep", EC_SLEEP, EF_NONE, 1, {{"interval", PT_RELTIME, PF_DEC}}},
	/* PPME_SYSCALL_NANOSLEEP_X */{"nanosleep", EC_SLEEP, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC}}},
	/* PPME_SYSCALL_TIMERFD_CREATE_E */{"timerfd_create", EC_TIME, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 2, {{"clockid", PT_UINT8, PF_DEC}, {"flags", PT_FLAGS8, PF_HEX}}},
	/* PPME_SYSCALL_TIMERFD_CREATE_X */{"timerfd_create", EC_TIME, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_INOTIFY_INIT_E */{"inotify_init", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"flags", PT_FLAGS8, PF_HEX}}},
	/* PPME_SYSCALL_INOTIFY_INIT_X */{"inotify_init", EC_IPC, (ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SYSCALL_GETRLIMIT_E */{"getrlimit", EC_PROCESS, EF_NONE, 1, {{"resource", PT_FLAGS8, PF_DEC, rlimit_resources}}},
	/* PPME_SYSCALL_GETRLIMIT_X */{"getrlimit", EC_PROCESS, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"cur", PT_INT64, PF_DEC}, {"max", PT_INT64, PF_DEC}}},
	/* PPME_SYSCALL_SETRLIMIT_E */{"setrlimit", EC_PROCESS, EF_NONE, 1, {{"resource", PT_FLAGS8, PF_DEC, rlimit_resources}}},
	/* PPME_SYSCALL_SETRLIMIT_X */{"setrlimit", EC_PROCESS, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"cur", PT_INT64, PF_DEC}, {"max", PT_INT64, PF_DEC}}},
	/* PPME_SYSCALL_PRLIMIT_E */{"prlimit", EC_PROCESS, EF_NONE, 2, {{"pid", PT_PID, PF_DEC}, {"resource", PT_FLAGS8, PF_DEC, rlimit_resources}}},
	/* PPME_SYSCALL_PRLIMIT_X */{"prlimit", EC_PROCESS, EF_NONE, 5, {{"res", PT_ERRNO, PF_DEC}, {"newcur", PT_INT64, PF_DEC}, {"newmax", PT_INT64, PF_DEC}, {"oldcur", PT_INT64, PF_DEC}, {"oldmax", PT_INT64, PF_DEC}}},
	/* PPME_SCHEDSWITCH_E */{"switch", EC_SCHEDULER, EF_NONE, 1, {{"next", PT_PID, PF_DEC}}},
	/* PPME_SCHEDSWITCH_X */{"NA2", EC_SCHEDULER, EF_UNUSED, 0},
	/* PPME_DROP_E */{"drop", EC_INTERNAL, EF_NONE, 1, {{"ratio", PT_UINT32, PF_DEC}}},
	/* PPME_DROP_X */{"drop", EC_INTERNAL, EF_NONE, 1, {{"ratio", PT_UINT32, PF_DEC}}},
	/* PPME_SYSCALL_FCNTL_E */{"fcntl", EC_IO_OTHER, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"fd", PT_FD, PF_DEC}, {"cmd", PT_FLAGS8, PF_DEC, fcntl_commands}}},
	/* PPME_SYSCALL_FCNTL_X */{"fcntl", EC_IO_OTHER, (ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC}}},
	/* PPME_SCHEDSWITCHEX_E */{"switch", EC_SCHEDULER, EF_NONE, 5, {{"next", PT_PID, PF_DEC}, {"pgft_maj", PT_UINT32, PF_DEC}, {"pgft_min", PT_UINT32, PF_DEC}, {"next_pgft_maj", PT_UINT32, PF_DEC}, {"next_pgft_min", PT_UINT32, PF_DEC}}},
	/* PPME_SCHEDSWITCHEX_X */{"NA2", EC_SCHEDULER, EF_UNUSED, 0},
};
