1.1	Purpose Of Project
The aim of this project is to generate 50 random 4-digit numbers, save these numbers as sold tickets in the txt called tickets.txt into the SD Card, then draw a random number from these 50 numbers and print the winning number on the LCD screen and the time the ticket was drawn with RTC. Then save this data as a log back into the SD Card.
1.2	Used materials
•	1 x Arduino Nano
•	1 x 16x2 LCD Display with I2C module
•	1 x RTC1307 with battery 
•	1 x Micro SD Card Module
•	1 x Mini Breadboard
•	1 x Micro SD Card
•	3 x Push Button
•	3 x 1k Ohm Resistance
•	1 x Data Cable
•	20 x Female-Male Jumper Cable
•	20 x Male-Male Jumper Cable

1.3	Fritzing Schema
![image](https://user-images.githubusercontent.com/53488195/167211930-5f328c06-efcb-4adc-a71f-1075382427b7.png)

 
1.4	Modules and Connections
SD Card Module: It works with 4.5-5 V.
•	GND  Ground
•	VCC  5V
•	MISO  D12
•	MOSI  D11
•	SCK  D13
•	CS  D10
RTC1307: It works with 3V so I wired to 3.3V on Arduino.
•	GND  Ground
•	VCC  3.3V
•	SDA  A4 (Used for data communication, A4 Default SDA port on Arduino Nano)
•	SCL  A5 (SCL used for synchronization of sending and receiving data parties)
I2C Module: It works with 5V. It reduces number of pin that LCD Display usage. 
•	GND  Ground
•	VCC  5V
•	SDA  A4 (Used for data communication, A4 Default SDA port on Arduino Nano)
•	SCL A5(SCL used for synchronization of sending and receiving data parties)
Buttons: They work with low voltage so I wired to 3.3V of Arduino.
•	D5,D6,D7
1.5	Functions of Project
 ![image](https://user-images.githubusercontent.com/53488195/167211944-431b22aa-6184-48d9-8f1b-498b6bb50187.png)

Figure 1
Button1: Calls mainmenu function in Arduino which contains Opening Screen as shown in Figure 1.
 ![image](https://user-images.githubusercontent.com/53488195/167211966-ee4641df-b410-422d-8998-6bd5b708e64e.png)

Figure 2
Button 2: Draws a lot and displays on LCD. The rightmost number indicates which ticket the ticket is. Also displays Date time on the screen. Figure 2.
 ![image](https://user-images.githubusercontent.com/53488195/167211983-06be62d2-d521-44a7-8b35-02c7144b6a19.png)

Figure 3
Button 3: Saves Winner number and date time of the draw into SD Card and returns to mainmenu function. Figure 3.
