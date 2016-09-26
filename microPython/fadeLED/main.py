# diagram @ https://cdn-learn.adafruit.com/assets/assets/000/035/547/original/microcontrollers_esp8266_blink_led_bb.png?1473148560

import time
import machine

pwm = machine.PWM(machine.Pin(15))
pwm.freq(60)

for x in range(1,21):
    for i in range(1024):
        pwm.duty(i)
        time.sleep_ms(2)
    for i in range(1023, -1, -1):
        pwm.duty(i)
        time.sleep_ms(2)