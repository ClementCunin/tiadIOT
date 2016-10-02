# LED manipulation module
# Basic LED wiring : https://cdn-learn.adafruit.com/assets/assets/000/035/356/original/microcontrollers_esp8266_blink_led_bb.png?1472787270

import machine
import time

def toggle(p):
	pin = machine.Pin(p, machine.Pin.OUT)
	pin.value(not pin.value())

def blink(p, reps = 1, freq = 1):
	for i in range(reps * 2):
		toggle(p)
		time.sleep_ms(int(1000 / freq / 2))

def blinkForever(p, freq = 1):
	while True:
		blink(p, freq)		

def fadeIn(pwm, delay = 1):
	for i in range(1024):
		pwm.duty(i)
		time.sleep_ms(delay)
	
def fadeOut(pwm, delay = 1):
	for i in range(1024, 0, -1):
		pwm.duty(i)
		time.sleep_ms(delay)

def fade(p, reps = 1, delay = 1):
	pwm = machine.PWM(machine.Pin(p))
	pwm.freq(60)

	for i in range(reps):
		fadeIn(pwm, delay)
		fadeOut(pwm, delay)

def fadeForever(p, delay = 1):
	while True:
		fade(p, 1, delay)