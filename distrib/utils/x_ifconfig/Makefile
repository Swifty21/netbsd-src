# $NetBSD: Makefile,v 1.38 2017/02/08 23:26:24 rin Exp $
# Build a smaller ifconfig (i.e. for boot media)

NOMAN=		# defined

.include <bsd.own.mk>

PROG=		ifconfig
SRCDIR=		${.CURDIR}/../../../sbin/ifconfig

CPPFLAGS+=	-DCRUNCHOPS

.if defined(SMALLPROG_INET6) && (${USE_INET6} != "no")
CPPFLAGS+=	-DINET6
SRCS+=		af_inet6.c
.endif

.PATH:		${SRCDIR}

.include "${SRCDIR}/Makefile.common"

.include <bsd.prog.mk>
