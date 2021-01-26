import notify2
import socket
import time 

import subprocess

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('0.0.0.0', 8080 ))
s.listen(0)                 
 
while True:
    client, addr = s.accept()
    client.settimeout(10)
    while True:
        content = client.recv(1024)
        if len(content) ==0:
           break
        if str(content,'utf-8') == 'Escape':
            notify2.init('DayTripper')
            n = notify2.Notification('Great' ,"", 'software-update-urgent')
            n.show()
            subprocess.call(["xdotool", "set_desktop", "0"])
    client.close()