#ifndef UNTITLED1_GLOBAL_H
#define UNTITLED1_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UNTITLED1_LIBRARY)
#  define UNTITLED1_EXPORT Q_DECL_EXPORT
#else
#  define UNTITLED1_EXPORT Q_DECL_IMPORT
#endif

#endif // UNTITLED1_GLOBAL_H
