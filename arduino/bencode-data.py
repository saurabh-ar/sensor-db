import requests
import json
import sys
import time 
import serial

def post_data_point (bencode) :
    url = "http://yuktix01.cloudapp.net:8080/sensordb/v1/datapoint"
    post_data = bencode + "\r\n"
    headers = { 'Content-type': 'text/plain' }
    r = requests.post(url, data=post_data, headers=headers)
    print r.status_code
    print r.text

    return 

def process_line(bencode) :
	bencode = bencode.strip()
	if not bencode.isspace() :
	    print bencode
	    post_data_point(bencode)
	return 


ser = serial.Serial('/dev/ttyUSB1', 9600)
line = ''

while True:
	try :
		line = ser.readline()
		process_line(line)
	except serial.serialutil.SerialException:
		pass
