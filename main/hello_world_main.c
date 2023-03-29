#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

#include "driver/gpio.h"

void app_main(void)
{
    
    gpio_config_t GPIO_config = {};
    GPIO_config.pin_bit_mask = (1<< 18);                /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    GPIO_config.mode = GPIO_MODE_DEF_OUTPUT;            /*!< GPIO mode: set input/output mode                     */
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;       /*!< GPIO pull-up                                         */
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;   /*!< GPIO pull-down                                       */
    GPIO_config.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&GPIO_config);

    while(1){
        printf("State: Led On !\n");
        gpio_set_level(18,0);                   //led sang
        vTaskDelay(1000/portTICK_PERIOD_MS);
        printf("State: Led Off !\n");
        gpio_set_level(18,1);                   // led tat - do led gan vao nguon Vcc
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
