# $NetBSD: Makefile.inc,v 1.9 2016/09/19 22:05:05 christos Exp $

.PATH: ${.CURDIR}/complex

COMPLEX_SRCS = cabs.c carg.c \
	ccos.c ccosh.c cephes_subr.c cexp.c clog.c conj.c cpow.c cproj.c \
	cimag.c creal.c csin.c csinh.c csqrt.c ctan.c ctanh.c \
	catrig.c
CATRIG_SRCS = cacos.c cacosh.c casin.c casinh.c catan.c catanh.c

CPPFLAGS+=-I${.CURDIR}/src
.for i in ${COMPLEX_SRCS}
SRCS+=	$i ${i:S/.c/f.c/} ${i:S/.c/l.c/}
MAN+= ${i:Ncatrig*:Ncephes_*:S/.c/.3/}
MLINKS+= ${i:Ncatrig*:Ncephes_*:S/.c/.3/} ${i:Ncatrig*:Ncephes_*:S/.c/f.3/}
MLINKS+= ${i:Ncatrig*:Ncephes_*:S/.c/.3/} ${i:Ncatrig*:Ncephes_*:S/.c/l.3/}
.endfor

.for i in ${CATRIG_SRCS}
MAN+= ${i:S/.c/.3/}
MLINKS+= ${i:S/.c/.3/} ${i:S/.c/f.3/}
MLINKS+= ${i:S/.c/.3/} ${i:S/.c/l.3/}
.endfor


