# -*- coding: utf-8 -*-


import logging
from sys import argv
import serial

SERIAL_PORT = "/dev/ttyUSB0"
SERIAL_BAUDRATE = "9600"


class ArduinoSerial(object):
    """docstring for ArduinoSerial"""
    def __init__(self):
        self.ser = serial.Serial(SERIAL_PORT,SERIAL_BAUDRATE, timeout=3) 

    def readLine():
        return self.ser.readline()

    def writeStr(towrite):
        self.ser.write(bytes(towrite))

    def close(self):
        self.ser.close()



def main():
    try:
        script, symbol = argv
        symbol = str(symbol)
    except Exception, e:
        print("Wrong number of argument")
        return
    ardSerial = ArduinoSerial()
    ardSerial.writeStr(symbol)
    ardSerial.readline()
    ardSerial.close()


if __name__ == '__main__':
    main()