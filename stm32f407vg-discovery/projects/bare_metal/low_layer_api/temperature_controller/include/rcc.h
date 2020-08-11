/*
 * Author: Jakub Standarski
 * Date: 11.08.2020
 *
 */

#ifndef RCC_H
    #define RCC_H



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

void rcc_set_ahb_prescaler(void);
void rcc_set_apb1_prescaler(void);
void rcc_set_apb2_prescaler(void);
void rcc_system_clock_init(void);

#endif /* RCC_H */

