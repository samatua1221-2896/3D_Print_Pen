| Title | Author | Description | Date Started |
| ------------- | ------------- | ------------- | ----------|
| Arm Assistant | @samatua1221-2896 | A custom 3D printing pen | 6/18/25 |

# June 18, 2025 (7 hours)

Today I decided I wanted to try and make a custom 3D printing pen that's pretty simple in terms of its ability but also has basic functionality. (I also really want some type of 3D printing tool like a 3D printer from highway maybe...) I started to base the concept off of MYNT3D's pen, it took me a little while but I was actually able to break it apart and figure out how the entire thing worked.

Based on the pictures below, I figured out that the pen had a potentiometer to adjust the temperature settings, there were two buttons to control the extruding and retraction of the filament, there was a slider to adjust the speed, and a small DC motor to actually control the movement of the filament. I decided I wanted to basically keep the basic functionality of the MYNT3D pen but have my own spin on it. I did want the entire thing to be powered by a 12V barrel jack to keep it simple. The microcontroller that was inside the MYNT pen looked to be some type of custom-made object, so I decided to use an Arduino Nano to keep it pretty simple for me so far.

![IMG_3427](https://github.com/user-attachments/assets/44d943f3-3548-469d-8d87-dddcd7e649f3)
![IMG_3430](https://github.com/user-attachments/assets/83a27d28-10fd-452b-a07b-a9b62b860080)


So far I've been working on the schematic that I can use, I eventually settled on keeping the manual potentiometer instead of a LCD screen, aside from that, I've just been working to keep the whole thing pretty simple and not too complex in its parts, also using THT components cause I've never had experience working with surface mounted components. Below is the main schematic that I have so far for it.

![alt text](image.png)

Tomorrow I'll work on arranging the PCB and starting to work on the CAD and wiring structure for the pen.