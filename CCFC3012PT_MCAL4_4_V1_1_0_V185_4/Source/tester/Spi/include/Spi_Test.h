/*
 * Spi_Test.h
 *
 *  Created on: 2023��8��10��
 *      Author: june
 */

#ifndef SPI_TEST_H_
#define SPI_TEST_H_


#define DSPI0_TCF_INTPRI        INTR_PRI_50
#define DSPI1_TCF_INTPRI        INTR_PRI_50
#define DSPI2_TCF_INTPRI        INTR_PRI_50
#define DSPI3_TCF_INTPRI        INTR_PRI_50
#define DSPI4_TCF_INTPRI        INTR_PRI_50
#define DSPI5_TCF_INTPRI        INTR_PRI_50
#define DSPI6_TCF_INTPRI        INTR_PRI_50
#define DSPI12_TCF_INTPRI       INTR_PRI_50


#define DSPI0_TCF_IntID          DSPI0_TCF_IRQn
#define DSPI1_TCF_IntID          DSPI1_TCF_IRQn
#define DSPI2_TCF_IntID          DSPI2_TCF_IRQn
#define DSPI3_TCF_IntID          DSPI3_TCF_IRQn
#define DSPI4_TCF_IntID          DSPI4_TCF_IRQn
#define DSPI5_TCF_IntID          DSPI5_TCF_IRQn
#define DSPI6_TCF_IntID          DSPI6_TCF_IRQn
#define DSPI12_TCF_IntID         DSPI12_TCF_IRQn

FUNC(void, SPI_CODE) dspi_Int_Enable(VAR(uint8, SPI_VAR) Spi_u8HandleIdx);
void spi_Env_Init();
int spi_func(int argc, char *agrv[]);

typedef void (*Spifunc)(void);
typedef struct _SpifuncMachine
{
    char *name;
    Spifunc spifunc;
}SpifuncMachine;

void spi_de_init(void);
void spi0_port_init(void);
void spi0_intc_init(void);

void spi_test(void);
void spi_0000(void);
void spi_0001(void);
void spi_0002(void);
void spi_0003(void);
void spi_4911_B(void);
void spi_4911_A(void);
void spi_0004(void);
void spi_0005(void);

void SPI_Init(void);

void EnableSpiInterrupt(void);
#endif /* SPI_TEST_H_ */
