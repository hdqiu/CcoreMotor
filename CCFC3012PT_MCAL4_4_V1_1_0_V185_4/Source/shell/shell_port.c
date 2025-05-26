
#ifdef __GNUC__
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"

#endif



#ifdef __HIGHTEC__

#endif

#ifdef __ghs__

#pragma ghs nowarning 1518

#endif

#include "shell.h"
#include "stdint.h"
#include "stdio.h"
#include "Mcu.h"
#include "console.h"

#define SHELL_BUFFER_SIZE 1024

__attribute__ ((section (".data_share"))) volatile Shell shell[6U] = {{.write = 0U,.read = 0U}};
#if SWITCH_CORE_ENABLE
__attribute__ ((section (".data_share"))) volatile uint8_t shell_coreid = 0U;
#endif /* SWITCH_CORE_ENABLE */
char shellBuffer[6U][SHELL_BUFFER_SIZE];


short shellWrite(char *data, unsigned short len)
{
    for(unsigned short i=0;i<len;i++)
    {
        Uart_Send_Char(data[i]);
    }

    return 0;
}

short shellRead(char *data, unsigned short len)
{
    return Uart_Read_Char(data);
}

void shell_init(void)
{
#if SWITCH_CORE_ENABLE
    shell[shell_coreid].write = shellWrite;
    shell[shell_coreid].read = shellRead;
    for(int i=0;i<6U;i++)
    {
        shellInit((Shell *)&shell[i], shellBuffer[i], SHELL_BUFFER_SIZE);
    }
#else
    uint8_t coreid = GetCoreID();
    shell[coreid].write = shellWrite;
    shell[coreid].read = shellRead;

    shellInit((Shell *)&shell[coreid], shellBuffer[coreid], SHELL_BUFFER_SIZE);
#endif /* SWITCH_CORE_ENABLE */
}

int reboot(int argc, char *agrv[])
{
    Mcu_PerformReset();
    return 0;
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), reboot, reboot, reboot);

#if SWITCH_CORE_ENABLE
int switchCore(int argc, char *agrv[])
{
    uint8_t coreid = GetCoreID();
    if (argc!=2)
    {
        shellPrint((Shell *)&shell[coreid], "error: Parameter number error\r\n");
    }
    else
    {
        uint32 id = (uint32)atoi(agrv[1]);
        if(id > 5)
        {
            shellPrint((Shell *)&shell[coreid], "error: Parameter number error\r\n");
        }
        else
        {
            shell_coreid = id;
            shell[coreid].write = 0U;
            shell[coreid].read = 0U;
            shell[id].write = shellWrite;
            shell[id].read = shellRead;
            shellPrint((Shell *)&shell[id], "The current core id is %d.\r\n",id);
            shellWriteString((Shell *)&shell[id], "\r\n");
            shellWriteString((Shell *)&shell[id], ((Shell *)&shell[id])->info.user->data.user.name);
            char ShellDefaultCoreID[2] = {(unsigned char)('0' + shell_coreid), '\0'};
            shellWriteString((Shell *)&shell[id], ShellDefaultCoreID);
            shellWriteString((Shell *)&shell[id], ":");
            shellWriteString((Shell *)&shell[id], ((Shell *)&shell[id])->info.path ? ((Shell *)&shell[id])->info.path : "/");
            shellWriteString((Shell *)&shell[id], "$ ");
        }
    }
    return 0;
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), switchCore, switchCore, switchCore);
#endif /* SWITCH_CORE_ENABLE */
int currentCore(int argc, char *agrv[])
{
    uint8_t coreid = GetCoreID();
    if (argc!=1)
    {
        shellPrint((Shell *)&shell[coreid], "error: Parameter number error\r\n");
    }
    shellPrint((Shell *)&shell[coreid], "The current core id is %d.\r\n", coreid);
    return 0;
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), currentCore, currentCore, currentCore);

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#ifdef __HIGHTEC__

#endif

#ifdef __ghs__
#pragma ghs endnowarning 1518
#endif
