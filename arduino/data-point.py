import requests
import json
import sys
import time 
import serial

def post_data_point (value) :
    url = "http://yuktix01.cloudapp.net:8080/sensordb/v1/datapoint"
    unix_ts = int(time.time())
    data = { 
        'projectId':'p001', 
        'serialNumber': 's001', 
        'readings': [ {"name" : "resistor" , "value" : value , "timestamp" : unix_ts} ] 
        }

    post_data = json.dumps(data)
    post_data = post_data + "\r\n"
    headers = { 'Content-type': 'application/json' }
    r = requests.post(url, data=post_data, headers=headers)
    print r.status_code

    return 

ser = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    value = ser.readline()
    print value
    post_data_point(value)

# sys.exit(0)
