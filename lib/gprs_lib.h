#ifndef _GPRS_LIB_H
#define _GPRS_LIB_H


typedef struct gprsstatus_info{
    int connect;
    int signalStrength;
 }gprsstatus_info_t;


/*set the GPRS APN return 0 is ok others is error */
extern int SetGprsAPN(const char *ApnBuf);

/*set the GPRS Setup return 0 is ok others is error */
extern int SetGprsSetup(const char *ApnBuf,const char *DialBuf);

/*set the GPRS CONNECT return 0 is ok others is error */
extern int SetGprsConnect(void);

/*set the GPRS DISCONNECT return 0 is ok others is error*/
extern int SetGprsDisconnect(void);

/*get the GPRS status*/
int  GetGprsStatus(gprsstatus_info_t *status);

/* on = 1 is POWER ON  on = 0 is POWER OFF return 0 is ok and >0 is error */
extern int SetGprsPower(unsigned int on);


/* the "second" is RESET TIME  "2< second < 10"  default is 2 */
extern int SetGprsReset(unsigned int second);

#endif
