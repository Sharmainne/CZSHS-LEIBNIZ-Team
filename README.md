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

   - [3.1. Open Challenge Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#21-power-management)

   - [3.2. Obstacle Challenge Strategy](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team?tab=readme-ov-file#21-power-management)

-  [4.Recommendatons](https://github.com/Sharmainne/CZSHS-LEIBNIZ-Team)

# Introduction
    This is the official engineering documentation of the Cielito Zamora Senior High School (CZSHS) LEIBNIZ Team for the Philippine Robot Olympiad (PRO) 2025 in the Future Engineers Category. Our project, centered around the theme Future of the Engineers, explores the boundless potential of robotics in shaping the future of engineering and technology. In this documentation, we present our self-driving car project, an innovative leap into autonomous systems. As we build this robot, we explore not only the technologies behind self-driving vehicles but also the profound impact they will have on engineering, mobility, and society as a whole. From autonomous navigation to advanced sensor integration, this project blends robotics, machine learning, and engineering principles to create a system that learns, adapts, and performs in dynamic environments. 
    This gives key aspects of the CZSHS LEIBNIZ Team robot’s development. We delve into the robot's design, development processes, and technical specifications, offering insights into the robotic technologies that drive its autonomous capabilities. These technologies include object detection, real-time decision-making, sensor fusion, and machine learning algorithms, all of which form the backbone of a fully autonomous vehicle. Our project is more than just a robotic self-driving car; it is a vision for the future of robotics, where engineers are tasked with creating smarter, more efficient systems that can redefine how we interact with technology and the world around us. Through this work, we demonstrate our commitment to advancing the field of robotics and autonomous technology, striving to push the boundaries of what robots can achieve.

# The Team
    Introducing the members of the Robotics Team of CZSHS—a group of highly motivated and forward-thinking students who are passionate about innovation, collaboration, and the future of technology. These individuals have dedicated their time, effort, and creativity to mastering the complexities of robotics, and together they represent the school’s commitment to excellence in Science, Technology, Engineering, and Mathematics (STEM)

In the Following image are the pictures of the members of FUTURE ENGINEERS Team:
- Juan Miguel C. Rabanal
  
- Jan Josh D.T. Santos
  
- Sharmainne Joy D. Campo
  

# Main Robot Specifications

# 1. Mobility Management
        In the Mobility management this are refers to the process of maintaining uninterrupted connectivity or access to a moving object. In telecommunications, it enables call/data transparency through monitoring device location and network handovers. For robotics, it is the capability of a robot to move autonomously, such as localization, mapping, path planning, and avoidance of obstacles, to preserve operational objectives during movement.
## 1.1. Motor Selection
    DRV8833 DC Motor Driver Module 
    For the front wheels, the team used the "AI STEAM 101S Simulated Steering Gear Module" because it functions as a software-driven core for the robot's mobility. It controls Mecanum wheels with high precision to achieve various mechanical rotations. This module provides variable angular velocity (from slow to fast turning speed), infinite angular displacement (constant 360-degree rotation), and an exceptionally small, even zero, turning radius (allowing rotation about a point).
    while at the back of the vehicle the team use A 'LEGO Servo Motor' this is a specialized motor, since this  offers precise control over angular position rather than continuous rotation. It achieves this accuracy through a built-in encoder that provides feedback on its current angle. Unlike ordinary motors, it's commanded to move to specific positions within a limited range of motion (e.g., ±180 degrees), making it ideal for tasks requiring exact angular control like steering or operating robotic arms.
     The team used the 'AI STEAM 101S Simulated Gear Module' and the 'LEGO Servo Motor' for the vehicle because both can provide the precise, software-driven control over motion in robots that the team desired. These motors enable complex robotic movements, such as advanced steering or accurate positioning, and rely on digital commands from a central controller, moving beyond simple continuous rotation.
## 1.2. Robot Design



# 2. Power and Sense Management
## 2.1. Power Management 
    Power management for robotics is the fundamental function of effectively governing, distributing, and optimizing a robot's electrical power. It means keeping track of and charging the power source safely, managing and distributing power to all devices, and actively minimizing energy usage through mechanisms such as sleep modes or dynamic power management. Its key significance is in maximizing autonomy, achieving stable performance, extending component life, and assuring the robot's safe use.
### 2.1.1. 18650 lithium-ion batteries
    18650 lithium-ion batteries are a popular power source in robotics, valued for their high energy density and nominal voltage of 3.6V or 3.7V per cell (which can be combined into higher voltage packs). They provide the necessary high discharge current for motors and power microcontrollers/sensors, enabling longer operating times and customizable battery configurations. Proper safety measures, such as a Battery Management System (BMS), are crucial due to their unprotected nature. 
    Given their ability to supply power for the entire system, including sensor management, the team decided to use these batteries as the primary power source for the vehicle. This choice was essential because the vehicle combines various components that collectively operate its functions, all requiring a reliable power supply


### 2.1.2. ESP 32 Wroom

### 2.1.3 DC Buck Converter Step-Down Module

### 2.1.4 TXS0108E chip


## 2.2. Sense Management
    Sense management in robotics is the holistic process of acquiring, processing, interpreting, and utilizing data from a robot's multitude of sensors in order to know its surroundings and internal state. It encompasses sensor data acquisition, sensor fusion (integration of data across multiple sensors), data processing (filtering, calibration), perception (detection, localization, mapping), and finally, information utilization to drive the robot's control and decision-making mechanisms. It is important for autonomy, safety, task execution, and robustness

### 2.2.1 ESP 32 Camera


### 2.2.2. Three Axis Digital Gyroscope Sensor Module 

### 2.2.3 Ultra Sonic Sensor




# 3. Obstacle Management 

## 3.1. Open Challenge Strategy

## 3.2. Obstacle Challenge Strategy

# 4. Recommendations











  
