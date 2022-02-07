#ifndef QLS_H
#define QLS_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
#include <time.h>

void listfiles(const char *path);

#endif // QLS_H
