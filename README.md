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

## 1.1. Motor Selection


### 1.1.2.AI STEAM 101S Simulated Steering Gear Module




## 1.2. Robot Design



# 2. Power and Sense Management
## 2.1. Power Management 

### 2.1.1. AI Steam 101S Controller 
    The AISTEAM Controller is the central 'brain' of the Nashenbot AISTEAM educational robots, featuring an ARM Cortex-M3 processor. It processes sensor data, controls motors and outputs, and is programmable using AIcode (graphical and Python) while also being compatible with the BBC micro:bit and its MakeCode platform. It includes various I/O ports for sensors, motors, and displays, all designed to facilitate learning in AI and STEM. The team utilized this controller because it was capable of handling complex coding and supporting a camera, which the team could then use to address obstacle detection and avoidance.
    
![image](https://github.com/user-attachments/assets/d5bd7f13-eb03-4b8d-9844-1c6f31d04700)

### 2.1.2. AI Steam 101S Lithium Battery Module 
    A lithium battery module in robotics is a self-contained unit of interconnected lithium-ion battery cells, designed to provide the necessary voltage and capacity to power a robot. It's crucial for mobile robots due to lithium's high energy density, and often includes a basic Battery Management System (BMS) for safety, thermal management, and modularity, allowing for flexible system design. The voltage a lithium battery module can handle depends on its internal series cell configuration. A single lithium-ion cell typically provides 3.6V-3.7V. Modules combine cells in series to achieve the higher voltages required for robots, with smaller educational robots commonly utilizing modules ranging from 7.4V to 14.8V. The team chose this particular module due to its user-friendliness, compatibility with the coding system, and overall convenience. 
    
![image](https://github.com/user-attachments/assets/9798e91b-7471-476b-b7b0-080aacc9310c)

## 2.2. Sense Management
### 2.2.1 AI Steam 101S Camera 
    The AISTEAM 101S AI Camera is a multifunctional vision sensor that acts as the robot's "eyes," enabling it to capture and interpret visual data. It can perform tasks like color recognition, object detection, and line following. Integrated with the AISTEAM Controller's AI capabilities, it provides visual input for intelligent obstacle avoidance, basic machine learning, and more sophisticated robot behaviors, significantly enhancing the educational robot's ability to interact with and understand its environment. The team use this for own satisfactory and since this is capable for seeing the obstacle and track the height, length and color of the obstacle. 
    
![image](https://github.com/user-attachments/assets/62fde19c-f9e1-4962-b2c9-0db87d4a5599)

### 2.2.2. AI Steam 101S Full-color light module
    The AISTEAM 101S Full-color light module serves as a versatile output component, capable of producing a broad spectrum of colors. Its main functions span providing visual feedback (such as clear status indicators), facilitating creative and expressive programming, and even offering specialized illumination for visual communication. The team integrated this module primarily because its dynamic colors could provide crucial visual cues regarding detected environmental colors or the robot's operational states. This capability was vital for the robot's precise navigation and environmental interaction, particularly when adhering to project rules that mandated careful avoidance of obstacle edges and accurate recognition of traffic signs.

![image](https://github.com/user-attachments/assets/7bcc0590-65cb-4440-8d41-0ca1d1f107a8)



# 3. Obstacle Management 

## 3.1. Open Challenge Strategy

## 3.2. Obstacle Challenge Strategy

# 4. Recommendations











  
