#ifndef SCHISM_PLAYER_FMOPL_H_
#define SCHISM_PLAYER_FMOPL_H_

#include "headers.h"

#define logerror(...) /**/

#define OPL_BANK_SIZE 9

#if OPLSOURCE == 2
# define OPL_CHANNELS 9
#elif OPLSOURCE == 3
# define OPL_CHANNELS 18
#else
# error "The current value of OPLSOURCE isn't supported! Check build-config.h."
#endif

typedef int16_t OPLSAMPLE;

typedef void (*OPL_TIMERHANDLER)(void *param,int timer,double period);
typedef void (*OPL_IRQHANDLER)(void *param,int irq);
typedef void (*OPL_UPDATEHANDLER)(void *param,int min_interval_us);
typedef void (*OPL_PORTHANDLER_W)(void *param,unsigned char data);
typedef unsigned char (*OPL_PORTHANDLER_R)(void *param);

/* OPL2 */
void *ym3812_init(uint32_t clock, uint32_t rate);
void ym3812_shutdown(void *chip);
void ym3812_reset_chip(void *chip);
int  ym3812_write(void *chip, int a, int v);
unsigned char ym3812_read(void *chip, int a);
int  ym3812_timer_over(void *chip, int c);
void ym3812_update_multi(void *chip, int32_t **buffers, int length, uint32_t vu_max[OPL_CHANNELS]);

void ym3812_set_timer_handler(void *chip, OPL_TIMERHANDLER TimerHandler, void *param);
void ym3812_set_irq_handler(void *chip, OPL_IRQHANDLER IRQHandler, void *param);
void ym3812_set_update_handler(void *chip, OPL_UPDATEHANDLER UpdateHandler, void *param);

/* OPL3 */
void *ymf262_init(uint32_t clock, uint32_t rate);
void ymf262_shutdown(void *chip);
void ymf262_reset_chip(void *chip);
int  ymf262_write(void *chip, int a, int v);
unsigned char ymf262_read(void *chip, int a);
int  ymf262_timer_over(void *chip, int c);
void ymf262_update_multi(void *chip, int32_t **buffers, int length, uint32_t vu_max[OPL_CHANNELS]);

void ymf262_set_timer_handler(void *chip, OPL_TIMERHANDLER TimerHandler, void *param);
void ymf262_set_irq_handler(void *chip, OPL_IRQHANDLER IRQHandler, void *param);
void ymf262_set_update_handler(void *chip, OPL_UPDATEHANDLER UpdateHandler, void *param);

/* moved this constant from snd_fm.c, because now the OPL update funcs need it */
/* Schismtracker output buffer works in 27bits: [MIXING_CLIPMIN..MIXING_CLIPMAX]
fmopl works in 16bits, although tested output used to range +-10000 instead of
    +-20000 from adlibtracker/screamtracker in dosbox. So we need 11 bits + 1 extra bit.
Also note when comparing volumes, that Screamtracker output on mono with PCM samples is not reduced by half.
*/
#define OPL_VOLUME 2274

#endif /* SCHISM_PLAYER_FMOPL_H_ */
