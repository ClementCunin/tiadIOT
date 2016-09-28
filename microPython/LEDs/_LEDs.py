# LED manipulation module

import machine
import time

def toggle(p):
	pin = machine.Pin(p, machine.Pin.OUT)
	pin.value(not pin.value())

def blink(p, reps = 1, freq = 1):
	for i in range(reps * 2):
		toggle(p)
		time.sleep_ms(int(1000 / freq))

def fadeIn(pwm, delay = 1):
	for i in range(1024):
		pwm.duty(i)
		time.sleep_ms(delay)
	
def fadeOut(pwm, delay = 1):
	for i in range(1024, 0, -1):
		pwm.duty(i)
		time.sleep_ms(delay)

def fade(p, delay = 1):
	pwm = machine.PWM(machine.Pin(p))
	pwm.freq(60)

	fadeIn(pwm, delay)
	fadeOut(pwm, delay)