/*
 *  Template MIB group interface - sysORTable.h
 *
 */
#ifndef _MIBGROUP_SYSORTABLE_H
#define _MIBGROUP_SYSORTABLE_H

config_require(util_funcs)

struct sysORTable {
   char *OR_descr;
   oid  *OR_oid;
   size_t  OR_oidlen;
   struct timeval OR_uptime;
   struct snmp_session *OR_sess;
   struct sysORTable *next;
};

struct register_sysOR_parameters {
   oid  *name;
   int   namelen;
   char *descr;
};

extern void     init_sysORTable (void);
extern FindVarMethod var_sysORTable;
extern FindVarMethod var_sysORLastChange;
extern int      register_sysORTable (oid *, size_t, const char *);
extern int    unregister_sysORTable (oid *, size_t);
extern int      register_sysORTable_sess (oid *, size_t, const char *, struct snmp_session *);
extern int    unregister_sysORTable_sess (oid *, size_t, struct snmp_session *);
extern int    unregister_sysORTable_by_session (struct snmp_session *);

#define	SYSORTABLEINDEX		        1
#define	SYSORTABLEID		        2
#define	SYSORTABLEDESCR		        3
#define	SYSORTABLEUPTIME	        4

#define SYS_ORTABLE_REGISTERED_OK              0
#define SYS_ORTABLE_REGISTRATION_FAILED       -1
#define SYS_ORTABLE_UNREGISTERED_OK            0
#define SYS_ORTABLE_NO_SUCH_REGISTRATION      -1


#endif /* _MIBGROUP_SYSORTABLE_H */
