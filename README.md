# CZSHS-LEIBNIZ-Team
    This repository showcases the CZSHS LEIBNIZ Team's self-driving car project for the Philippine Robotics Olympiad (PRO) 2025 - Future Engineers Category (Self-Driving Car). It includes details on the robot’s design, functionalities, and technical specifications, highlighting our commitment to advancing autonomous technology. 



# Main Content
- [Introduction](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team#introduction)

   - [The Team](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/README.md#the-team)

- [Robot Specifications](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/README.md#robot-specifications)
  
- [1.Mobility Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#1-mobility-management)

  - [1.1. Motor Selection](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team)
  
  - [1.2. Robot Design](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team)
    
-  [2.Power and Sense Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#2-power-and-sense-management)
  
   - [ 2.1. Power Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#21-power-management)
     
        * [2.1.1. 18650 lithium-ion batteries](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#5-engineering-factor)
         
        * [2.1.2. ESP 32](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#212-esp-32)
    
        * [2.1.3. TXS0108E chip](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#213-txs0108e-chip)
    
        * [2.1.4. DC-DC Buck Converter Step Down Module](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#214-dc-dc-buck-converter-step-down-module)
       
     
   - [2.2. Sense Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#21-power-management)
  
-  [3.Obstacle Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#3-obstacle-management)

   - [3.1. Robot Driving Mechanism](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#31-determine-driving-direction)

   - [3.2. Open Challange Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#32-open-challenge-strategy)
     
   - [3.3 Obstacle Challenge Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#33-obstacle-challenge-strategy)

-  [4.Program Construction Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [4.1. Camera Program Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [4.2. ESP32 Program Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - 
-  [5. Engineering Factor](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#5-engineering-factor)
     
-  [6. Appendices](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#5-engineering-factor)
   - [6.1. Team Photos](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#5-engineering-factor)
   - [6.2. Vehicle Photos](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/tree/main?tab=readme-ov-file#5-engineering-factor)

     
# Introduction
    This is the official engineering documentation of the Cielito Zamora Senior High School (CZSHS) LEIBNIZ Team for the Philippine Robot Olympiad (PRO) 2025 in the Future Engineers Category. Our project, centered around the theme "Future of the Engineers," explores the boundless potential of robotics in shaping the future of engineering and technology. In this documentation, we present our self-driving car project, an innovative leap into autonomous systems. As we build this robot, we explore not only the technologies behind self-driving vehicles but also the profound impact they will have on engineering, mobility, and society as a whole. From autonomous navigation to advanced sensor integration, this project blends robotics, machine learning, and engineering principles to create a system that learns, adapts, and performs in dynamic environments. 
    This gives key aspects of the CZSHS LEIBNIZ Team robot’s development. We delve into the robot's design, development processes, and technical specifications, offering insights into the robotic technologies that drive its autonomous capabilities. These technologies include object detection, real-time decision-making, sensor fusion, and machine learning algorithms, all of which form the backbone of a fully autonomous vehicle. Our project is more than just a robotic self-driving car; it is a vision for the future of robotics, where engineers are tasked with creating smarter, more efficient systems that can redefine how we interact with technology and the world around us. Through this work, we demonstrate our commitment to advancing the field of robotics and autonomous technology, striving to push the boundaries of what robots can achieve.

# The Team
    Introducing the members of the Robotics Team of CZSHS—a group of highly motivated and forward-thinking students who are passionate about innovation, collaboration, and the future of technology. These individuals have dedicated their time, effort, and creativity to mastering the complexities of robotics, and together they represent the school’s commitment to excellence in Science, Technology, Engineering, and Mathematics (STEM)

In the Following image are the pictures of the members of FUTURE ENGINEERS Team:
- Juan Miguel C. Rabanal

  Social Media contact: https://www.facebook.com/miguel.rabanal.733
  
- Jan Josh D.T. Santos

  Social Media contact: https://www.facebook.com/share/14GvB6W9dwH/?mibextid=wwXIfr
  
- Sharmainne Joy D. Campo

  Social Media contact: https://www.facebook.com/share/1XqtCNYRpd/


# Main Robot Specifications
     The CZSHS-Leibniz Team Presents this self-driving robot for the Phillipine Robot Olympiad 2024. Designed with precision, agility, and performance in mind, this robot embodies innovation and teamwork by our trio. Engineered to meet the demands of the competition, the Cielito-Leibniz Robots features a combination design built with LEGO® and ESP 32 Camera, offering optimal speed, maneuverability, and power efficiency. Below are the specifications that highlight the robot’s capabilities, reflecting our team's commitment to excellence and readiness to compete on the global stage.

* Dimensions: 254mm(L) x 177.8mm(W) x 165mm (H)
* Weight: 0.92kg
* Maximum Speed: 6.8m/s
* Maximum Steer: ±45°
* Steering Torque: 100Ncm
* Working Voltage: 4.4V-8.8V
* Drive System: Rear-wheel drive (RWD)
* Steering Geometry: Parallel steering
* Material: LEGO® Technic

# 1. Mobility Management
    In the Mobility management this are refers to the process of maintaining uninterrupted connectivity or access to a moving object. In telecommunications, it enables call/data transparency through monitoring device location and network handovers. For robotics, it is the capability of a robot to move autonomously, such as localization, mapping, path planning, and avoidance of obstacles, to preserve operational objectives during movement.
### 1.1. Motor Selection 
    For the front wheels of the Vehicle the team use 'LEGO Technic Medium Hub Motor (also known as the Medium Angular Motor in SPIKE Prime)' this is a compact, cube-like motor integral to newer LEGO robotics platforms like SPIKE Prime. It features integrated design with Technic pin compatibility, a specialized connector for LEGO hubs, and provides precise control over speed, direction, and rotational feedback due to its internal encoder. It's used for driving mechanisms and wheels in LEGO robots.
    while at the back of the vehicle the team use A 'LEGO Servo Motor' this is a specialized motor, since this  offers precise control over angular position rather than continuous rotation. It achieves this accuracy through a built-in encoder that provides feedback on its current angle. Unlike ordinary motors, it's commanded to move to specific positions within a limited range of motion (e.g., ±180 degrees), making it ideal for tasks requiring exact angular control like steering or operating robotic arms.
    The team used the 'LEGO Tecnic Medium Hub Motor' and the 'LEGO Servo Motor' for the vehicle because both can provide the precise, software-driven control over motion in robots that the team desired. These motors enable complex robotic movements, such as advanced steering or accurate positioning, and rely on digital commands from a central controller, moving beyond simple continuous rotation.
 <img src = https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/Image%20Discussion/steering.jfif>
    
### 1.2. Robot Design
     the team decided to do this vehicle design since this can be convenient and the team also needs a simple and smaller version of robot for the parking area so that can fit easily and it can possibly not hassle at all the team utilize thee length to be able steer easily and as well as the width for the balance weight of the vehicle
<img width="1388" height="794" alt="image" src="https://github.com/user-attachments/assets/872bd2a2-8702-4429-8dbd-e69871b34c35" />

    
    


# 2. Power and Sense Management
### 2.1. Power Management 
    Power management for robotics is the fundamental function of effectively governing, distributing, and optimizing a robot's electrical power. It means keeping track of and charging the power source safely, managing and distributing power to all devices, and actively minimizing energy usage through mechanisms such as sleep modes or dynamic power management. Its key significance is in maximizing autonomy, achieving stable performance, extending component life, and assuring the robot's safe use.
 <img src = https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/Image%20Discussion/power%20management.jfif>
 
### 2.1.1. 18650 lithium-ion batteries
    18650 lithium-ion batteries are the source of the power of the veehicle, valued for their high energy density and nominal voltage of 3.6V or 3.7V per cell (which can be combined into higher voltage packs). This provide the necessary high discharge current for motors and power microcontrollers/sensors, enabling longer operating times and customizable battery configurations. Proper safety measures, such as a Battery Management System (BMS), are crucial due to their unprotected nature. 
    Given their ability to supply power for the entire system, including sensor management, the team decided to use these batteries as the primary power source for the vehicle. This choice was essential because the vehicle combines various components that collectively operate its functions, all requiring a reliable power supply.
### 2.1.2. ESP 32
    The team used the ESP32-WROOM-32 because of its relevance to power management. Its core ESP32 SoC is designed with advanced power efficiency features, offering various sleep modes (e.g., Deep Sleep) and dynamic frequency scaling to significantly reduce its own power consumption. This makes it ideal for optimizing battery life in embedded and IoT applications, and it helps the 18650 Lithium-ion batteries save enough power for the vehicle. Specifically, it can achieve significant power savings by utilizing its Deep Sleep mode, where current consumption drops from 80-150 mA (active) to as low as 5-20 µA.

    The team designated the ESP32-WROOM-32 as the central processing unit, or "brain," of the vehicle. This strategic choice was made due to its powerful dual-core processor and integrated Wi-Fi and Bluetooth capabilities, which provide the necessary computational power and connectivity to manage all critical operations and complex decision-making processes required for the robot's autonomous functions.As the vehicle's brain, the ESP32-WROOM-32 is responsible for orchestrating every aspect of its operation. This includes processing data from various sensors (like the ESP32-CAM and gyroscope), executing control algorithms for navigation and obstacle avoidance, and coordinating actions with actuators such as motors. Its wireless capabilities further enable remote control, data logging, and communication with other systems, making it an indispensable core for the vehicle's intelligent and connected functionality.

### 2.1.3. TXS0108E chip
    The TXS0108E chip is an absolutely essential 8-bit bidirectional voltage-level translator. Its core purpose is to seamlessly and safely enable crucial communication between electronic components that operate at fundamentally different logic voltage levels, such as connecting a 3.3V microcontroller to a 5V sensor or vice-versa. This prevents potential damage to sensitive inputs by ensuring that signals are always at the correct voltage for the receiving component. Critically, the TXS0108E handles data flow in both directions automatically without requiring dedicated control pins, making it incredibly versatile for protocols like I2C, SPI, or UART where data lines are shared. This capability makes it an unparalleled choice for ensuring interoperability and robust protection in complex mixed-voltage circuits, commonly found in robotics, embedded systems, and DIY electronics projects.

    The Team decided to use the TXS0108E chip as a voltage-level translator because the ESP32-WROOM-32, which operates at 3.3 volts, cannot be directly connected to the 18650 Lithium-ion batteries that supply 8 volts. Crucially, the TXS0108E chip ensures that the signal voltages exchanged between the ESP32 and other components operating at different logic levels are safely translated, preventing damage and enabling proper communication for the vehicle to function. It is essential for maintaining voltage compatibility on data lines, not for regulating the main power supply voltage from the battery, which would require a separate voltage regulator.

### 2.1.4. DC-DC Buck Converter Step Down Module
    A DC-DC Buck Converter Step Down Module is an electronic circuit specifically designed to efficiently convert a higher DC (Direct Current) voltage into a stable, lower DC voltage. Unlike less efficient linear regulators that dissipate excess voltage as heat, buck converters are a type of switching power supply. They achieve their high efficiency (often exceeding 85-95%) by rapidly switching a component, like a transistor, on and off. This process precisely regulates the output voltage, ensuring it remains stable even if the input voltage fluctuates or the connected load changes. This module is a vital component in power management across numerous applications. It is commonly used in battery-powered devices to step down the battery's higher voltage to the lower voltage requirements of sensitive components like microcontrollers (e.g., 3.3V or 5V). Furthermore, buck converters are indispensable in automotive electronics, LED lighting, and general electronics projects where a specific, lower DC voltage needs to be derived efficiently from a higher DC source, thereby optimizing power usage and minimizing heat generation.
    
    The team strategically decided to incorporate DC-DC Buck Converter Step Down Modules into their design. This was absolutely critical because the ESP32-WROOM-32, the vehicle's "brain," can only safely operate at 3.3 volts, while the primary power source, the 18650 Lithium-ion battery, supplies 8 volts. Therefore, the 8 volts from the battery are directly fed into these DC-DC Buck Converter Step Down Modules, which then efficiently lower and regulate the main power supply voltage to the precise 3.3 volts required by the ESP32-WROOM-32.
    Crucially, in addition to managing the main power supply, the team also integrated the TXS0108E chip. While the buck converters handle the power voltage reduction, the TXS0108E is essential for translating signal voltages between the 3.3V ESP32-WROOM-32 and any other components that might operate at different logic levels (like 5V). This prevents damage to sensitive inputs and ensures seamless communication on data lines. To ensure robust and protected power distribution, the team employed two separate DC-DC Buck Converter Step Down Modules: one specifically dedicated to supplying the correct operating voltage to the ESP32-WROOM-32, and the other for powering the DRV8833 DC Motor Driver and various other components connected throughout the vehicle. This meticulous approach to both power regulation and signal voltage translation ensures every part receives its ideal operating voltage and communicates safely, maximizing efficiency and preventing damage.

## 2.2. Sense Management
    Sense management in robotics is the holistic process of acquiring, processing, interpreting, and utilizing data from a robot's multitude of sensors in order to know its surroundings and internal state. It encompasses sensor data acquisition, sensor fusion (integration of data across multiple sensors), data processing (filtering, calibration), perception (detection, localization, mapping), and finally, information utilization to drive the robot's control and decision-making mechanisms. It is important for autonomy, safety, task execution, and robustness
<img src = https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/Image%20Discussion/sense%20management.jfif>
    
### 2.2.1 ESP 32 Camera
     The ESP32-CAM module in robotics functions as a compact, low-cost, and wirelessly connected vision system, essentially providing the robot with its "eyes." By integrating an ESP32-S chip with a camera, it enables the robot to capture and stream images or video data from its environment. This capability is fundamental for various robotic tasks, including obstacle detection, line following, and even basic object recognition, allowing the robot to perceive and react to its surroundings. Beyond environmental perception, the ESP32-CAM facilitates crucial First-Person View (FPV) and remote operation. It streams real-time video wirelessly to a user, offering vital visual feedback for teleoperation, remote monitoring, and informing the robot's control systems for autonomous decision-making. This makes it an invaluable, cost-effective tool for adding visual intelligence and remote interaction to a wide array of robotic projects.
    
    The team strategically selected the ESP32-CAM module for its crucial role in sensing and detecting colors during the obstacle course round. This vital component empowers the robot to function properly and maintain its alignment: specifically, it directs the robot to align itself to the right upon detecting a red obstacle. Conversely, when the camera identifies a green obstacle, it commands the robot to turn to the left, automatically adjusting its path to navigate effectively, The camera ensures highly accurate detection by meticulously analyzing color information, leveraging its 240 x 360 RGB565 resolution. This process involves identifying objects based on the concentration and distribution of specific color pixels. A higher density of a particular color's pixels on the closest object precisely indicates its color. This critical visual data is then processed by the ESP32-CAM, which subsequently transmits this intelligence to the ESP32-WROOM (the vehicle's central processing unit or "brain"), enabling the robot to immediately execute the appropriate actions to skillfully avoid the detected obstacle.
    
### 2.2.2. Three Axis Digital Gyroscope Sensor Module 
    Since the vehicle required a gyroscope, the team chose this module. The Three-Axis Digital Gyroscope Sensor Module's primary function is to measure angular velocity (rotational speed) around its X, Y, and Z axes in digital form. Its key importance lies in providing crucial data for orientation and attitude tracking, enabling stabilization systems, navigation, and motion sensing in various applications, including robotics. Specifically, it provides fundamental data on the robot's angular velocity, which is essential for the vehicle to understand its own rotational movement and maintain stability during operation.
    
### 2.2.3 Ultra Sonic Sensor
    The Ultrasonic Sensor in robotics functions as a non-contact ranging device, serving as one of the robot's primary "eyes" or perception tools. It operates by emitting high-frequency sound waves and then measuring the time it takes for these waves to bounce off an object and return. This "time-of-flight" data is then used to accurately calculate the distance to the nearest obstacle or surface within its detection cone. This capability is crucial for enabling various robotic behaviors, most notably obstacle avoidance, where the robot detects objects in its path and adjusts its movement to prevent collisions. Beyond just avoiding obstacles, ultrasonic sensors are also employed for tasks like navigation ( maintaining a specific distance from a wall), mapping (creating rudimentary environmental layouts), level sensing (detecting liquid or material levels), and proximity detection, making them a fundamental component for robots that need to perceive and interact with their immediate physical environment.

    The team made a strategic decision to integrate four ultrasonic sensors for comprehensive obstacle detection and avoidance. While the camera excels at identifying frontal obstacles, the vehicle critically required additional sensory input for reliable wall detection, a task the camera isn't inherently suited for due to its limited field of view and close-proximity blind spots. Therefore, two ultrasonic sensors were placed at the front, with one on each side, enabling the vehicle to precisely detect walls using sound waves. This configuration ensures the vehicle can effectively navigate tight spaces and maintain proper clearance, providing a crucial layer of environmental awareness that perfectly complements the camera's vision.
 <img src = https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team/blob/main/Image%20Discussion/ultrasonic%20sensor.jfif>

# 3. Obstacle Management 
    To successfully detect and negotiate the obstacles on the field, a meticulously planned strategy is essential for completing 3 laps in both the Open and Obstacle Challenge Rounds. The team dedicated significant time to developing efficient obstacle management approaches, consistently incorporating innovative and effective ideas into their strategy.
## 3.1. Robot Driving Mechanism
    The robot employs a parallel steering geometry, wherein a front LEGO Technic Medium hub motor precisely steers the front wheels in parallel. The robot is propelled by a rear-wheel drive (RWD) transmission, where power from the rear LEGO Servo motor drives the rear wheels, enabling forward or reverse propulsion. This specific steering geometry and transmission configuration was selected by the team due to its prevalence and proven effectiveness within the Future Engineers Category. Furthermore, empirical testing conducted by the team demonstrated that the RWD system provided superior handling characteristics compared to a front-wheel drive (FWD) configuration.
    

## 3.2. Open Challenge Strategy
     In Open Challenge Rounds, the only obstacles present on the game field are its outer boundary wall and the randomly placed inner wall. The robot must not touch the outer wall and must not move the inner wall to successfully finish the three laps requirement.
### 3.2.1 Wall Avoidance 
    To successfully avoid touching the outer boundary wall, the robot automatically performs a 90° turn based on gyro when it detects it is within a specific distance. This can ensure that the robot maintains a safe distance from the outer wall after each maneuver. The ultrasonic sensor is critical for detecting if the robot is about to collide with the outer wall; if an imminent collision is detected, the robot immediately steers away and especially, to make the robot align itself to the middle distance between walls. Furthermore, these ultrasonic sensor also enables the robot to maintain a precise angle, guaranteeing proper turns and straight driving paths after each rotation.
    

## 3.3. Obstacle Challenge Strategy
    In Obstacle Challenge Rounds, the game field becomes much more complex with increased obstacles. The robot must navigate a field containing an outer boundary, a random inner wall, and up to seven randomly colored traffic signs (green or red), plus two parking lot boundaries. The robot's tasks include passing green signs on the left, red signs on the right, and parking between the lot boundaries after completing three laps, all while avoiding contact with any traffic signs or parking boundaries.

# 4. Program Construction Guide

    The program construction for the CZSHS LEIBNIZ Team robotics project is centered in this repository, which serves as the official codebase for all robot control software for the Philippine Robotics Olympiad (PRO) 2025. All logic and algorithms are implemented in C++ and maintained within the "source of program" directory, ensuring every source file uses the `.cpp` extension for proper syntax highlighting and compilation. The codebase is organized by functionality—such as sensor handling, motor control, and decision-making to promote clarity and ease of development. Team members follow clear and consistent naming conventions, write modular code, and document important sections to better understand and for future updates. Before committing, all changes are tested thoroughly, both in simulation and on the robot, to ensure reliability. Collaboration is facilitated through regular updates: members pull the latest changes before starting new work, use branches for features or fixes, and submit clear, descriptive commit messages. Major updates or issues are communicated through the repository’s discussion tools. By adhering to these practices, the team maintains an organized, maintainable, and competition-ready program.

## 4.1. Camera Program Guide
 ### STEP 1. Gathering Necessary Components
    Bringing an ESP32 camera module to life involves a series of steps, transforming it from a mere component into a functional web-streaming device. This journey begins with gathering the necessary components: your ESP32-CAM, an FTDI programmer or USB-to-serial adapter, and a handful of jumper wires to bridge the connections. These are the foundational pieces that will enable communication and power the module.

 ### STEP 2. Hardware Connections
    Once you have your components, the next crucial step is establishing the hardware connections. Carefully connect the FTDI programmer to the ESP32 camera module. This requires precise wiring: ensure the RX pin on the FTDI connects to the TX pin on the ESP32, and vice-versa, TX to RX. Always connect GND to GND, and for power, connect VCC to the appropriate voltage (either 3.3V or 5V), depending on your specific ESP32 model. A vital step for programming is to short the GPIO0 pin to GND; this puts the ESP32 into upload mode, allowing it to receive new code.

 ### STEP 3. Installing Arduino IDE
    With the hardware sorted, the focus shifts to your computer, specifically to install the Arduino IDE. If you don't have the app, download and install the Arduino IDE from Arduino's official website. This application integrates development environment in where you'll write, compile, and upload the code to your ESP32.

 ### STEP 4. Configuring the Arduino IDE
    After installation, you'll need to configure the Arduino IDE to recognize the ESP32 board. Open "File > Preferences" and in the "Additional Board Manager URLs" field, add the following URL: https://dl.espressif.com/dl/package_esp32_index.json. This URL provides access to the ESP32 board definitions. Next, navigate to "Tools > Board > Board Manager," search for "ESP32," and install the package specifically designed for ESP32 development boards. This will equip your Arduino IDE with the necessary files to communicate with your camera module.

 ### STEP 5. Selecting Board and Port
    With the IDE configured, it's time to select the correct board and port. Under "Tools > Board," you'll now find an option to select your specific ESP32 camera model (ESP32-CAM). For reliable uploads, set the upload speed to 115200 baud rate. Finally, you'll need to identify and select the appropriate COM port that corresponds to your connected FTDI programmer. This port is the communication channel between your computer and the ESP32.

 ### STEP 6. Loading Sample Code
    When loading the sample code appear, open "File > Examples > ESP32 > Camera > CameraWebServer." This particular example provides a complete web server for streaming video from your ESP32-CAM. Additionally, ensure you select the correct camera model in the code by uncommenting the appropriate #define CAMERA_MODEL_AI_THINKER line (or whichever model you have).

 ### STEP 7. Uploading the Code
    With the code prepared, it's time to upload it to the ESP32. Ensure your ESP32 camera is connected to your computer via the FTDI programmer, and crucially, make sure GPIO0 is shorted to GND to keep it in programming mode. Then, in the Arduino IDE, click the "Upload" button to compile and transfer the code. Once the upload is complete, disconnect GPIO0 from GND; this allows the ESP32 to boot into normal operation mode, running the newly uploaded web server.

 ### STEP 8. Running the Program
    After the camera and program runs, open the Serial Monitor in the Arduino IDE (usually found under "Tools > Serial Monitor"). After a moment, the ESP32 will connect to your robot through USB-C cable and display the IP address assigned to the ESP32 camera. Copy this IP address and enter it into any web browser on a device connected to the same Wi-Fi network. This will bring up the camera's web interface, allowing you to view live feeds, adjust settings, and capture images or videos, effectively turning your ESP32-CAM into a remote surveillance or monitoring device.

 ### STEP 9. Troubleshooting
    Should you encounter any hiccups along the way, remember these troubleshooting tips. If the camera fails to boot or upload, double-check all your wiring and connections meticulously. Verify that you've selected the correct board and settings in the Arduino IDE. Reconfirm your Wi-Fi credentials and ensure your network is stable. If issues persist, a simple restart of the ESP32 camera can often resolve unresolved problems, giving you a fresh start.

# 4.2. ESP32 Program Guide
    Welcome to the ESP32 Program Guide for the CZSHS-LEIBNIZ-Team repository! This guide is designed to help you set up your environment, understand the code structure, and successfully upload programs to your ESP32 board using the files provided in the Source of Program folder.

## Folder Structure
    The Source of Program/ directory contains all the necessary files for our ESP32 program. This includes main.ino, which serves as the primary entry point for sketch. Any custom libraries required for the project are located in the library/ folder, and this README.md file provides documentation and usage instructions.

Source of Program/
│
├── main.ino          # Main Arduino sketch for ESP32
├── library/          # Custom libraries (if any)
└──  README.md         # This guide

## Prerequisites
    Before you begin, ensure you have an ESP32 Board (such as an ESP32 DevKit, NodeMCU-ESP32S, or WROOM) and a USB-C Cable to connect it to your computer. You will also need to install either the Arduino IDE or PlatformIO (available as a VSCode extension) as your development environment.

### Step 1. Set Up Arduino IDE for ESP32
    Once the repository is cloned, configure your Arduino IDE to work with ESP32 boards. Open the Arduino IDE, go to File > Preferences, and in the "Additional Boards Manager URLs" field, add the provided URL for the ESP32 board definitions. After saving, open the Tools > Board > Boards Manager, search for "esp32", and click "Install" to add the necessary board support. Finally, select your specific ESP32 board from the Tools > Board menu.

### Step 2. Install Required Libraries
    Your program may depend on various libraries. To install them, go to Tools > Manage Libraries within the Arduino IDE. In the Library Manager, search for any libraries listed in the #include statements of your .ino files and install them. This step ensures all necessary functions and components are available for your program to compile correctly.

### STep 3. Open and Upload the Program
    With your environment set up and libraries installed, you can now open the program. Open main.ino in the Arduino IDE, making sure that any supporting .ino files are located in the same folder to be recognized as part of the sketch. Connect your ESP32 board to your computer using a USB cable, then select the correct communication port under Tools > Port. Finally, click the "Upload" button (the right arrow icon) to compile and transfer the program to your ESP32 board.

## Common Issues & Troubleshooting
    If your board is not found, ensure that you have installed the appropriate USB drivers for your ESP32 board and that you have selected the correct board type and serial port in the Arduino IDE's Tools menu. If the upload fails, try holding down the BOOT button on your ESP32 board while the upload process is running; this often puts the board into programming mode. If you encounter errors due to missing libraries, carefully review the #include statements in your code and use the Arduino IDE's Library Manager (Tools > Manage Libraries) to search for and install any libraries that are not present.

## References
    For more detailed information and resources, you can refer to the ESP32 Arduino Core GitHub repository, the Official ESP32 Documentation, and the PlatformIO ESP32 Documentation. These resources provide extensive information on ESP32 development and troubleshooting.

# 5. Engineering Factor 
    The group's main engineering goal was to create a vehicle defined by its small and nimble nature. This initial choice was made with strategic intent to assure the robot's ability to move freely in tight spaces, namely the allocated parking zone. It also sought to provide easy negotiation of the complex obstacle course, allowing the robot to make its way around different traffic signs unscathed. One of the primary features of this design was the compact overall footprint of the vehicle. This specific measurement was carefully designed to enable sharp and responsive steering turns, thus greatly improving the robot's control and maneuverability during intricate maneuvers. 
   
    To make operations efficient and easy to use, the robot has a single, self-explanatory control button. With the touch of this button, the critical process is activated: simultaneous calibration of the robot's onboard gyroscope, camera, and ultrasonic sensors, all the sensory systems being geared up for instant usage.After these initial calibrations are done, the whole car automatically starts its pre-programmed process. This pre-loaded program instructs the robot to perform its pre-programmed task, which is to drive three complete laps around the specified map without any human intervention.

# 6. Appendices
    These are the supplementary figures for the team's engineering documentation about the robot and the team.

## 6.1. Team Photos
     part contains multiple official and funny photos of the team in order for judges to identify the team during the competition.

| Formal Team Photos | Funny Team Photos|
| ----------------------------------- | ------------------------------- |
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/0f36c774-9cd9-4116-b216-317051cb5f98" width = "480">|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/0076adf6-db14-4c03-a6cc-447048d2ba29" width = "480">|
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/caacc902-b162-4de8-9b50-e291f700e06f">|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/32a9efd6-0b92-45aa-86ec-e406f930a30e" width = "480">|

## 6.2. Vehicle Photos
| Front View                          | Rear View                       |
| ----------------------------------- | ------------------------------- |
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/6acc3500-c773-4f09-936b-6b4fa06e0e0b">|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/1587a028-6e96-46f6-87e1-b68323f8debb">|
| Left Side View                      | Right Side View                 |
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/fe9fbb0c-4562-4812-9ba1-fbe110c474d4">|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/eb7adb4a-6684-4968-b99b-d48ad34e5b42">|
| Top View                            | Bottom  View                    | 
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/c051f748-d7e2-4ebb-afd0-ad5dceffd6b7">|<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/a2bc0ee5-4388-4cb5-9c08-0aaba1c48a88">
| Isometric View                                                        |
|<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/8b22a0f9-62e3-47c4-a6f1-a846fe1dff61">|









  
