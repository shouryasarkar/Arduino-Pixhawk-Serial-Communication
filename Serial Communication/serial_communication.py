import serial
port = 'COM5'
baud_rate = 9600
ser = serial.Serial(port,baud_rate) #a serial connection is made with the arduino port and the baud_rate
ser.flushInput()  #it clears the input buffer of serial connection

#now here we are vreating an infinite loop so the pixhawk is continuously going to give o/p when receives any data from the arduino 
while True:
    #here he rstrip method is used to remove all the white spaces from the string and utf-8 changes the decoded data from a byte to a string
    line = ser.readline().decode("utf-8").rstrip()
    print("The message from arduino: ", line)
    
    #going to check if the message from the arduino is same as we have defined
    if line == "Hello":
        message_from_Pixhawk = "Hi from PixHawk"
        ser.write(message_from_Pixhawk.encode("utf-8"))
        print("Reply sent to Arduino is: ", message_from_Pixhawk)
