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
  
   - [2.2. Sense Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#21-power-management)
  
-  [3.Obstacle Management](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#3-obstacle-management)

   - [3.1. Determine Driving Direction](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#31-determine-driving-direction)

   - [3.2. Open Challange Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#32-open-challenge-strategy)
     
   - [3.3 Obstacle Challenge Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#33-obstacle-challenge-strategy)

-  [4.Program Construction Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [4.1. Camera Program Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [4.2. ESP32 Wroom Program Guide](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
     
-  [5. Appendices](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [5.1. Team Photos](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [5.2. Vehicle Photos](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)
   - [5.3. Vehicle Bills of Materials](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#5-program-construction-guide)

     
# Introduction
    This is the official engineering documentation of the Cielito Zamora Senior High School (CZSHS) LEIBNIZ Team for the Philippine Robot Olympiad (PRO) 2025 in the Future Engineers Category. Our project, centered around the theme "Future of the Engineers," explores the boundless potential of robotics in shaping the future of engineering and technology. In this documentation, we present our self-driving car project, an innovative leap into autonomous systems. As we build this robot, we explore not only the technologies behind self-driving vehicles but also the profound impact they will have on engineering, mobility, and society as a whole. From autonomous navigation to advanced sensor integration, this project blends robotics, machine learning, and engineering principles to create a system that learns, adapts, and performs in dynamic environments. 
    This gives key aspects of the CZSHS LEIBNIZ Team robot’s development. We delve into the robot's design, development processes, and technical specifications, offering insights into the robotic technologies that drive its autonomous capabilities. These technologies include object detection, real-time decision-making, sensor fusion, and machine learning algorithms, all of which form the backbone of a fully autonomous vehicle. Our project is more than just a robotic self-driving car; it is a vision for the future of robotics, where engineers are tasked with creating smarter, more efficient systems that can redefine how we interact with technology and the world around us. Through this work, we demonstrate our commitment to advancing the field of robotics and autonomous technology, striving to push the boundaries of what robots can achieve.

# The Team
    Introducing the members of the Robotics Team of CZSHS—a group of highly motivated and forward-thinking students who are passionate about innovation, collaboration, and the future of technology. These individuals have dedicated their time, effort, and creativity to mastering the complexities of robotics, and together they represent the school’s commitment to excellence in Science, Technology, Engineering, and Mathematics (STEM)

In the Following image are the pictures of the members of FUTURE ENGINEERS Team:
- Juan Miguel C. Rabanal
- Social Media contact: https://www.facebook.com/juanmiguel.rabanal?mibextid=ZbWKwL
  
- Jan Josh D.T. Santos
- Social Media contact: https://www.facebook.com/janjosh.santos.1?mibextid=ZbWKwL
  
- Sharmainne Joy D. Campo
- Social Media contact: https://www.facebook.com/share/1XqtCNYRpd/


# Main Robot Specifications

# 1. Mobility Management
    In the Mobility management this are refers to the process of maintaining uninterrupted connectivity or access to a moving object. In telecommunications, it enables call/data transparency through monitoring device location and network handovers. For robotics, it is the capability of a robot to move autonomously, such as localization, mapping, path planning, and avoidance of obstacles, to preserve operational objectives during movement.
## 1.1. Motor Selection 
    For the front wheels of the Vehicle the team use 'LEGO Technic Medium Hub Motor (also known as the Medium Angular Motor in SPIKE Prime)' this is a compact, cube-like motor integral to newer LEGO robotics platforms like SPIKE Prime. It features integrated design with Technic pin compatibility, a specialized connector for LEGO hubs, and provides precise control over speed, direction, and rotational feedback due to its internal encoder. It's used for driving mechanisms and wheels in LEGO robots.
    while at the back of the vehicle the team use A 'LEGO Servo Motor' this is a specialized motor, since this  offers precise control over angular position rather than continuous rotation. It achieves this accuracy through a built-in encoder that provides feedback on its current angle. Unlike ordinary motors, it's commanded to move to specific positions within a limited range of motion (e.g., ±180 degrees), making it ideal for tasks requiring exact angular control like steering or operating robotic arms.
    The team used the 'LEGO Tecnic Medium Hub Motor' and the 'LEGO Servo Motor' for the vehicle because both can provide the precise, software-driven control over motion in robots that the team desired. These motors enable complex robotic movements, such as advanced steering or accurate positioning, and rely on digital commands from a central controller, moving beyond simple continuous rotation.
## 1.2. Robot Design



# 2. Power and Sense Management
## 2.1. Power Management 
    Power management for robotics is the fundamental function of effectively governing, distributing, and optimizing a robot's electrical power. It means keeping track of and charging the power source safely, managing and distributing power to all devices, and actively minimizing energy usage through mechanisms such as sleep modes or dynamic power management. Its key significance is in maximizing autonomy, achieving stable performance, extending component life, and assuring the robot's safe use.
### 2.1.1. 18650 lithium-ion batteries
    18650 lithium-ion batteries are the source of the power of the veehicle, valued for their high energy density and nominal voltage of 3.6V or 3.7V per cell (which can be combined into higher voltage packs). This provide the necessary high discharge current for motors and power microcontrollers/sensors, enabling longer operating times and customizable battery configurations. Proper safety measures, such as a Battery Management System (BMS), are crucial due to their unprotected nature. 
    Given their ability to supply power for the entire system, including sensor management, the team decided to use these batteries as the primary power source for the vehicle. This choice was essential because the vehicle combines various components that collectively operate its functions, all requiring a reliable power supply.
### 2.1.2. ESP 32 Wroom
    The team used the ESP32-WROOM-32 because of its relevance to power management. Its core ESP32 SoC is designed with advanced power efficiency features, offering various sleep modes (e.g., Deep Sleep) and dynamic frequency scaling to significantly reduce its own power consumption. This makes it ideal for optimizing battery life in embedded and IoT applications, and it helps the 18650 Lithium-ion batteries save enough power for the vehicle. Specifically, it can achieve significant power savings by utilizing its Deep Sleep mode, where current consumption drops from 80-150 mA (active) to as low as 5-20 µA.

    The team designated the ESP32-WROOM-32 as the central processing unit, or "brain," of the vehicle. This strategic choice was made due to its powerful dual-core processor and integrated Wi-Fi and Bluetooth capabilities, which provide the necessary computational power and connectivity to manage all critical operations and complex decision-making processes required for the robot's autonomous functions.As the vehicle's brain, the ESP32-WROOM-32 is responsible for orchestrating every aspect of its operation. This includes processing data from various sensors (like the ESP32-CAM and gyroscope), executing control algorithms for navigation and obstacle avoidance, and coordinating actions with actuators such as motors. Its wireless capabilities further enable remote control, data logging, and communication with other systems, making it an indispensable core for the vehicle's intelligent and connected functionality.

### 2.1.4. TXS0108E chip
    The TXS0108E chip is an absolutely essential 8-bit bidirectional voltage-level translator. Its core purpose is to seamlessly and safely enable crucial communication between electronic components that operate at fundamentally different logic voltage levels, such as connecting a 3.3V microcontroller to a 5V sensor or vice-versa. This prevents potential damage to sensitive inputs by ensuring that signals are always at the correct voltage for the receiving component. Critically, the TXS0108E handles data flow in both directions automatically without requiring dedicated control pins, making it incredibly versatile for protocols like I2C, SPI, or UART where data lines are shared. This capability makes it an unparalleled choice for ensuring interoperability and robust protection in complex mixed-voltage circuits, commonly found in robotics, embedded systems, and DIY electronics projects.

    The Team decided to use the TXS0108E chip as a voltage-level translator because the ESP32-WROOM-32, which operates at 3.3 volts, cannot be directly connected to the 18650 Lithium-ion batteries that supply 8 volts. Crucially, the TXS0108E chip ensures that the signal voltages exchanged between the ESP32 and other components operating at different logic levels are safely translated, preventing damage and enabling proper communication for the vehicle to function. It is essential for maintaining voltage compatibility on data lines, not for regulating the main power supply voltage from the battery, which would require a separate voltage regulator.

### 2.1.5. DC-DC Buck Converter Step Down Module
    A DC-DC Buck Converter Step Down Module is an electronic circuit specifically designed to efficiently convert a higher DC (Direct Current) voltage into a stable, lower DC voltage. Unlike less efficient linear regulators that dissipate excess voltage as heat, buck converters are a type of switching power supply. They achieve their high efficiency (often exceeding 85-95%) by rapidly switching a component, like a transistor, on and off. This process precisely regulates the output voltage, ensuring it remains stable even if the input voltage fluctuates or the connected load changes. This module is a vital component in power management across numerous applications. It is commonly used in battery-powered devices to step down the battery's higher voltage to the lower voltage requirements of sensitive components like microcontrollers (e.g., 3.3V or 5V). Furthermore, buck converters are indispensable in automotive electronics, LED lighting, and general electronics projects where a specific, lower DC voltage needs to be derived efficiently from a higher DC source, thereby optimizing power usage and minimizing heat generation.
    
    The team strategically decided to incorporate DC-DC Buck Converter Step Down Modules into their design. This was absolutely critical because the ESP32-WROOM-32, the vehicle's "brain," can only safely operate at 3.3 volts, while the primary power source, the 18650 Lithium-ion battery, supplies 8 volts. Therefore, the 8 volts from the battery are directly fed into these DC-DC Buck Converter Step Down Modules, which then efficiently lower and regulate the main power supply voltage to the precise 3.3 volts required by the ESP32-WROOM-32.
    Crucially, in addition to managing the main power supply, the team also integrated the TXS0108E chip. While the buck converters handle the power voltage reduction, the TXS0108E is essential for translating signal voltages between the 3.3V ESP32-WROOM-32 and any other components that might operate at different logic levels (like 5V). This prevents damage to sensitive inputs and ensures seamless communication on data lines. To ensure robust and protected power distribution, the team employed two separate DC-DC Buck Converter Step Down Modules: one specifically dedicated to supplying the correct operating voltage to the ESP32-WROOM-32, and the other for powering the DRV8833 DC Motor Driver and various other components connected throughout the vehicle. This meticulous approach to both power regulation and signal voltage translation ensures every part receives its ideal operating voltage and communicates safely, maximizing efficiency and preventing damage.

## 2.2. Sense Management
    Sense management in robotics is the holistic process of acquiring, processing, interpreting, and utilizing data from a robot's multitude of sensors in order to know its surroundings and internal state. It encompasses sensor data acquisition, sensor fusion (integration of data across multiple sensors), data processing (filtering, calibration), perception (detection, localization, mapping), and finally, information utilization to drive the robot's control and decision-making mechanisms. It is important for autonomy, safety, task execution, and robustness
### 2.2.1 ESP 32 Camera
     The ESP32-CAM module in robotics functions as a compact, low-cost, and wirelessly connected vision system, essentially providing the robot with its "eyes." By integrating an ESP32-S chip with a camera, it enables the robot to capture and stream images or video data from its environment. This capability is fundamental for various robotic tasks, including obstacle detection, line following, and even basic object recognition, allowing the robot to perceive and react to its surroundings. Beyond environmental perception, the ESP32-CAM facilitates crucial First-Person View (FPV) and remote operation. It streams real-time video wirelessly to a user, offering vital visual feedback for teleoperation, remote monitoring, and informing the robot's control systems for autonomous decision-making. This makes it an invaluable, cost-effective tool for adding visual intelligence and remote interaction to a wide array of robotic projects.
    
    The team strategically selected the ESP32-CAM module for its crucial role in sensing and detecting colors during the obstacle course round. This vital component empowers the robot to function properly and maintain its alignment: specifically, it directs the robot to align itself to the right upon detecting a red obstacle. Conversely, when the camera identifies a green obstacle, it commands the robot to turn to the left, automatically adjusting its path to navigate effectively, The camera ensures highly accurate detection by meticulously analyzing color information, leveraging its 240 x 360 RGB565 resolution. This process involves identifying objects based on the concentration and distribution of specific color pixels. A higher density of a particular color's pixels on the closest object precisely indicates its color. This critical visual data is then processed by the ESP32-CAM, which subsequently transmits this intelligence to the ESP32-WROOM (the vehicle's central processing unit or "brain"), enabling the robot to immediately execute the appropriate actions to skillfully avoid the detected obstacle.
### 2.2.2. Three Axis Digital Gyroscope Sensor Module 
    Since the vehicle required a gyroscope, the team chose this module. The Three-Axis Digital Gyroscope Sensor Module's primary function is to measure angular velocity (rotational speed) around its X, Y, and Z axes in digital form. Its key importance lies in providing crucial data for orientation and attitude tracking, enabling stabilization systems, navigation, and motion sensing in various applications, including robotics. Specifically, it provides fundamental data on the robot's angular velocity, which is essential for the vehicle to understand its own rotational movement and maintain stability during operation.
    
### 2.2.3 Ultra Sonic Sensor
    The Ultrasonic Sensor in robotics functions as a non-contact ranging device, serving as one of the robot's primary "eyes" or perception tools. It operates by emitting high-frequency sound waves and then measuring the time it takes for these waves to bounce off an object and return. This "time-of-flight" data is then used to accurately calculate the distance to the nearest obstacle or surface within its detection cone. This capability is crucial for enabling various robotic behaviors, most notably obstacle avoidance, where the robot detects objects in its path and adjusts its movement to prevent collisions. Beyond just avoiding obstacles, ultrasonic sensors are also employed for tasks like navigation ( maintaining a specific distance from a wall), mapping (creating rudimentary environmental layouts), level sensing (detecting liquid or material levels), and proximity detection, making them a fundamental component for robots that need to perceive and interact with their immediate physical environment.

    The team strategically decided to utilize the ultrasonic sensor for obstacle detection and avoidance on the vehicle. Beyond the camera's capabilities, which primarily focus on frontal obstacles, the vehicle critically requires an additional sensor for wall detection. The camera, by its very nature, cannot reliably perceive walls from all angles or at close proximity. Therefore, the ultrasonic sensor plays an indispensable role by precisely detecting walls using its sound waves, ensuring the vehicle can navigate tight spaces and maintain proper clearance, thus providing a crucial layer of environmental awareness that complements the camera's vision.


# 3. Obstacle Management 
    To successfully detect and negotiate the obstacles on the field, a meticulously planned strategy is essential for completing 3 laps in both the Open and Obstacle Challenge Rounds. The team dedicated significant time to developing efficient obstacle management approaches, consistently incorporating innovative and effective ideas into their strategy.
## 3.1. Determine Driving Direction
    For precise obstacle management, the ESP32 Camera is critically utilized. It is specifically programmed to identify the color of obstacles, which then dictates the robot's driving direction: upon detecting a red obstacle, the robot is commanded to turn to the right; conversely, if a green obstacle is identified, the robot is directed to turn to the left. This direct visual feedback is fundamental to the robot's ability to navigate the obstacle course effectively and make real-time, color-based decisions for safe passage.

## 3.2. Open Challenge Strategy
     In Open Challenge Rounds, the only obstacles present on the game field are its outer boundary wall and the randomly placed inner wall. The robot must not touch the outer wall and must not move the inner wall to successfully finish the three laps requirement.
### 3.2.1 Wall Avoidance 
    o successfully avoid touching the outer boundary wall, the robot automatically performs a 90° turn based on gyro when it detects it is within a specific distance. This can ensure that the robot maintains a safe distance from the outer wall after each maneuver. The ultrasonic sensor is critical for detecting if the robot is about to collide with the outer wall; if an imminent collision is detected, the robot immediately steers away and especially, to make the robot align itself to the middle distance between walls. Furthermore, these ultrasonic sensor also enables the robot to maintain a precise angle, guaranteeing proper turns and straight driving paths after each rotation.
    
```python
Ultra_Sonics::Ultra_Sonics(int max_distance, int trigPin1, int echoPin1, 
                           int trigPin2, int echoPin2, 
                           int trigPin3, int echoPin3, 
                           int trigPin4, int echoPin4) : 
                           mySonar1(trigPin1, echoPin1, max_distance),
                           mySonar2(trigPin2, echoPin2, max_distance),
                           mySonar3(trigPin3, echoPin3, max_distance),
                           mySonar4(trigPin4, echoPin4, max_distance) {}
```

## 3.3. Obstacle Challenge Strategy
    In Obstacle Challenge Rounds, the game field becomes much more complex with increased obstacles. The robot must navigate a field containing an outer boundary, a random inner wall, and up to seven randomly colored traffic signs (green or red), plus two parking lot boundaries. The robot's tasks include passing green signs on the left, red signs on the right, and parking between the lot boundaries after completing three laps, all while avoiding contact with any traffic signs or parking boundaries.

### 3.3.1 Traffic Sign Direction

### 3.3.2. Parking lot Detection


# 4. Program Construction Guide

## 4.1. Camera Program Guide

## 4.2. ESP32 Wroom Program Guide


# 5. Appendices

## 5.1. Team Photos

## 5.2. Vehicle Photos

## 5.3. Vehicle Bills of Materials










  
