# diagram @ https://cdn-learn.adafruit.com/assets/assets/000/034/887/original/microcontrollers_esp8266_blink_led_bb.png?1471571428

import machine
import time

led = machine.Pin(15, machine.Pin.OUT)

def toggle(p):
    p.value(not p.value())


for x in range(1,21):
     toggle(led)
     time.sleep_ms(100)