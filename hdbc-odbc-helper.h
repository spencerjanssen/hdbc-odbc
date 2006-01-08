#include <sql.h>

extern int sqlSucceeded(SQLRETURN ret);
extern SQLRETURN sqlFreeHandleEnv(SQLHANDLE hdl);

typedef struct TAG_finalizeonce {
  void *encapobj;
  int isfinalized;
} finalizeonce;

extern finalizeonce *wrapobj(void *obj);

extern void PQfinish_app(finalizeonce *conn);
extern void PQfinish_finalizer(finalizeonce *conn);

extern void PQclear_app(finalizeonce *res);
extern void PQclear_finalizer(finalizeonce *res);

extern void sqlFreeHandleSth_app(finalizeonce *res);
extern void sqlFreeHandleSth_finalizer(finalizeonce *res);

extern SQLINTEGER nullData;
extern void *getSqlOvOdbc3(void);
