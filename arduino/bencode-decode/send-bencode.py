import serial


ser = serial.Serial('/dev/ttyUSB1', 57600)
ser.write('d4:name4:bobo3:agei27ee')

# sys.exit(0)
