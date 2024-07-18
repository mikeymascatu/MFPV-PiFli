import network
import time
import socket

def web_page():
  html = html = """<!DOCTYPE html><html>
<head><meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
.buttonGreen { background-color: #4CAF50; border: 2px solid #000000;; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; }
.buttonRed { background-color: #D11D53; border: 2px solid #000000;; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; }
text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}
</style></head>
<body><center><h1>Control Panel</h1></center><br><br>
<form><center>
<center> <button class="buttonGreen" name="led" value="on" type="submit">LED ON</button>
<br><br>
<center> <button class="buttonRed" name="led" value="off" type="submit">LED OFF</button>
</form>
<br><br>
<br><br>
<p>%s<p></body></html>
"""

  return html

def ap_mode(ssid, password):
    """
        Description: This is a function to activate AP mode
        
        Parameters:
        
        ssid[str]: The name of your internet connection
        password[str]: Password for your internet connection
        
        Returns: Nada
    """
    # Start internet broadcast
    ap = network.WLAN(network.AP_IF)
    ap.config(essid=ssid, password=password)
    ap.active(True)
    ap.ifconfig(('192.168.0.4', '255.255.255.0', '192.168.0.3', '8.8.8.8'))

    #use 192.168.0.3 in cilent device when connected
    
    while ap.active() == False:
        pass
    print('AP Mode Is Active, You can Now Connect')
    print('IP Address To Connect to:: ' + ap.ifconfig()[0])
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   #creating socket object
    s.bind(('', 80))
    s.listen(5) #Lock server to only 1 connection due to safety concerns

ap_mode('uavnet', 'wiflipassword') #set password and ssid on secrets.py
#CHANGE PASSWORD ASAP when functioning

