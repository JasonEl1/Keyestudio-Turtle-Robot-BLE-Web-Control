# Keyestudio-Turtle-Robot-BLE-Web-Control

Control the Keyestudio Turtle Robot using a web interface. This is accomplished through the use of serial communication from the HM-10 module to the arduino board, and communication through the Web Bluetooth API from the browser to the module. So far, the web interface is only able to receive an echo of transmitted messages to the module. The eventual end goal is to be able to control the robot using this web interface.

> The boilerplate code for the JavaScript component of this project was heavily inspired by the following project by ``ErniW`` : [Web-Bluetooth-and-HM-10-module-for-Arduino](https://github.com/ErniW/Web-Bluetooth-and-HM-10-module-for-Arduino)