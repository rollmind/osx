#
# Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
#                         University Research and Technology
#                         Corporation.  All rights reserved.
# Copyright (c) 2004-2005 The University of Tennessee and The University
#                         of Tennessee Research Foundation.  All rights
#                         reserved.
# Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
#                         University of Stuttgart.  All rights reserved.
# Copyright (c) 2004-2005 The Regents of the University of California.
#                         All rights reserved.
# $COPYRIGHT$
# 
# Additional copyrights may follow
# 
# $HEADER$
#

# Use the top-level Makefile.options



# Make the output library in this directory, and name it either
# mca_<type>_<name>.la (for DSO builds) or libmca_<type>_<name>.la
# (for static builds).

if OMPI_BUILD_iof_proxy_DSO
component_noinst =
component_install = mca_iof_proxy.la
else
component_noinst = libmca_iof_proxy.la
component_install =
endif

proxy_SOURCES = \
    iof_proxy.c \
    iof_proxy.h \
    iof_proxy_component.c \
    iof_proxy_svc.c \
    iof_proxy_svc.h

mcacomponentdir = $(libdir)/openmpi
mcacomponent_LTLIBRARIES = $(component_install)
mca_iof_proxy_la_SOURCES = $(proxy_SOURCES)
mca_iof_proxy_la_LIBADD = \
    $(top_ompi_builddir)/orte/libopen-rte.la \
    $(top_ompi_builddir)/opal/libopen-pal.la
mca_iof_proxy_la_LDFLAGS = -module -avoid-version

noinst_LTLIBRARIES = $(component_noinst)
libmca_iof_proxy_la_SOURCES = $(proxy_SOURCES)
libmca_iof_proxy_la_LIBADD =
libmca_iof_proxy_la_LDFLAGS = -module -avoid-version
