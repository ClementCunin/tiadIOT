import machine
import time

pin = machine.Pin(2, machine.Pin.OUT)

def toggle(p):
    p.value(not p.value())


for x in range(1,11):
     toggle(pin)
     time.sleep_ms(500)