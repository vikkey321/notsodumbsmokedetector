# Not so dumb smoke detector
A smart smoke detector which you can turn off using Google Assistant if you turn it on accidentally. This prototype was developed under 24 hours including the  concept, idea, breadboarding, electronics, soldering, CAD designing and 3d printing as part of #24hoursprototypechallenge.

Complete Video Here : https://youtu.be/j9lKQJRmcAQ

Steps to run the Code

1. Download and unzip this repository.
2. Open Terminal and brwose to server folder
  type "npm install"
  then type "npm run"
3. Download ngrok from this url : https://ngrok.com/
4. Add ngrok to your system path. Then type:
  ngrok http 3000 ( for windows)
  or
  ./ngrok http 3000 (for linux & mac)
5. Connect an MQ2 sensor to Nodemcu.
  Gnd - Gnd
  Vcc - 3v3
  Analog Pin - A0
  Buzzer  & LED - +ve to D0 and -ve to GND 
6. Upload the sketch from NodeMCU code folder to NodeMCU.
7. Copy the IP address of NodeMCU and replace it in the app.js code inside server folder.
8. Create an IFTTT applet. Check the IFTTT_applet folder for reference. Copy the ngrok URL and paste it in your applet.
9. If you have connected NodeMCU to other power source, check the threshold value in the serial terminal. And adjust the threshold value in the Node MCU code. Now simply light any lighter near the sensor and it will start beeping. Just say "I am just cooking" to your google assistant or google home and the beep will stop. 

I have also uploaded STL for the Cad which I made. You can downlad it from the STL folder.

![alt text](http://vsgupta.in/wp-content/uploads/2019/07/7C1D9F1C-33A7-4D9E-9B05-A795ED3F58A6.jpg)

