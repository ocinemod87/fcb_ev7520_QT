FCB EV 7520 Controller in QT

This software is a school project I developed during an internship for my AP degree in IT Technology.

The application is part of a bigger project about a microscope used for scientific research and development. 
The camera is a Sony FCB-EV7520 using the VISCA protocol to communicate. The camera is Full-HD and has many features such as 
a digital and optical zoom, Infra-Red mode for night vision, manual and automatic exposure and focus.

My task was to implement a library containing commands and inquiries to be send to the camera. The logic of the library is 
implemented in C++ for the back-and side and this logic is triggered by a graphical user interface developed in QML.

The different classes are implemented in this way:

- The main.cpp file is the file where all the engine is set. It creates the objects for the QML graphic interface and the
  MainWindow instance.
  
- The MainWindow class can be considered the heart of the software, it contain instances of all the other classes which 
  communicate through a system used in QT called signal and slot, a set of messages that can be triggered by events, when it 
  happens a signal containing an information is sent to a slot which is a function operating a certain task.

- The Controller class is responsible for the communication of the software, the place where all the informations travel. It 
  sends messages back and forth between the different classes and the user interface. 

- The Serial class sets up the serial interface responsible for sending and receiving information from the computer serial   
  port that is connected to the camera through the hardware. It takes the incoming information containing the operation to 
  perform from the libraries and it wraps this message into a QByteArray that is an array of bytes understandable from the 
  camera. Then it sends this array to the camera to perform the tasks. It also takes the incoming array of bytes from the 
  hardware (such as inquiries) and sends the QByteArray to the CameraInquiry class.

- The CameraInquiry class is the library containing all the possible inquiries that can be sent to the camera to check the 
  state of it, for example it contains the array of bytes that asks to the camera what is the state of the zoom in that 
  moment. It also takes the logic, receives the answer back from the Serial class and manipulates the info to be shown to the 
  user.

- The CameraCommand class is responsible for the camera functionality. It contains the commands to be performed by the 
  camera. When one of its functions is triggered by an user action, it sends the command (such as zoom-in or zoom-out) to the 
  Serial class.

- The VideoManager class is the interface connecting the software with the one implemented with another software which is   
  part of the entire project. The communicating application is a software for computer vision using OpenCV library in Python. 
  In order to be able to communicate between C++ and Python I created a shared memory which runs OpenCV on a separate Thread. 
  Once received the video frame from the OpenCV library it converts it into a QPixmap object that can be sent to the QML side 
  of the software and displayed on the screen.
  
I used QML (mixed with some JavaScript functions) to develop the front-end part of the software. 

With QML is possible to create a component (such as a slider managing a manual focus) with a certain functionality and use it 
in different part of the user interface, allowing the user to have the same command in different parts of the GUI. Taking 
inspiration from the object oriented programming world I developed a branch of component that can be represented by a 
reversed piramid.

At the top of it there are all the graphical styles used to implement the aesthetics of the components, here I defined the 
color and the shape for all the sliders, buttons etc. Then I have the single component triggering the action to be 
performed (such as zoom slider, focus slider, exposure buttons etc). 

In a deeper level I created the different kind of menus of the GUI, a toolbar menu standing on the top of the screen, it is 
an easy and fast way to trigger the most common commands. Then I created a menu bar on the left of the screen with different 
icons opening pages of the menu that contain all the commands available in the software. 

Moreover there is an additional menu with all the functionality using the native menu from the Linux OS, it is placed on the 
bar on the top of the screen and it is a common menu we can find in every kind of software.

This piramid ends into the main window file, it wraps up all these components and show them on the top of the videodisplayed.

In some cases I also used some graphic tools for image manipulation, in this way I created the lowpoly inspired background of 
the menus and  some icons representing the command contained into that specific menu page.

