/* Based on ipsvd utilities written by Gerrit Pape <pape@smarden.org>
 * which are released into public domain by the author.
 * Homepage: http://smarden.sunsite.dk/ipsvd/
 *
 * Copyright (C) 2007 Denis Vlasenko.
 *
 * Licensed under GPLv2, see file LICENSE in this tarball for details.
 */

struct hcc {
        char *ip;
        int pid;
};

void ipsvd_perhost_init(unsigned);

/* Returns number of already opened connects to this ips, including this one.
 * ip should be a malloc'ed ptr.
 * If return value is <= maxconn, ip is inserted into the table
 * and pointer to table entry if stored in *hccpp
 * (useful for storing pid later).
 * Else ip is NOT inserted (you must take care of it - free() etc) */
unsigned ipsvd_perhost_add(char *ip, unsigned maxconn, struct hcc **hccpp);

/* Finds and frees element with pid */
void ipsvd_perhost_remove(int pid);

//unsigned ipsvd_perhost_setpid(int pid);
//void ipsvd_perhost_free(void);
