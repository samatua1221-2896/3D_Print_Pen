| Title | Author | Description | Date Started |
| ------------- | ------------- | ------------- | ----------|
| Arm Assistant | @samatua1221-2896 | A custom 3D printing pen | 6/18/25 |

# June 18, 2025 (7 hours)

Today I decided I wanted to try and make a custom 3D printing pen that's pretty simple in terms of its ability but also has basic functionality. (I also really want some type of 3D printing tool like a 3D printer from highway maybe...) I started to base the concept off of MYNT3D's pen, it took me a little while but I was actually able to break it apart and figure out how the entire thing worked.

Based on the pictures below, I figured out that the pen had a potentiometer to adjust the temperature settings, there were two buttons to control the extruding and retraction of the filament, there was a slider to adjust the speed, and a small DC motor to actually control the movement of the filament. I decided I wanted to basically keep the basic functionality of the MYNT3D pen but have my own spin on it. I did want the entire thing to be powered by a 12V barrel jack to keep it simple. The microcontroller that was inside the MYNT pen looked to be some type of custom-made object, so I decided to use an Arduino Nano to keep it pretty simple for me so far.

![IMG_3427](https://github.com/user-attachments/assets/44d943f3-3548-469d-8d87-dddcd7e649f3)
![IMG_3430](https://github.com/user-attachments/assets/83a27d28-10fd-452b-a07b-a9b62b860080)


So far I've been working on the schematic that I can use, I eventually settled on keeping the manual potentiometer instead of a LCD screen, aside from that, I've just been working to keep the whole thing pretty simple and not too complex in its parts, also using THT components cause I've never had experience working with surface mounted components. Below is the main schematic that I have so far for it.

![Screenshot 2025-06-18 5 01 48 PM](https://github.com/user-attachments/assets/9a111527-ea79-4895-9bb5-a3904e44d945)

Tomorrow I'll work on arranging the PCB and starting to work on the CAD and wiring structure for the pen.


# June 19, 2025 (8 hrs)

Today I worked on getting my BOM in order and finishing up the design of my PCB. So far, it's looking like theres not too much to do. I did start working on my BOM and figuring out how to get the products, I started using AliExpress and was extrememly happy to find that almost everything I needed was super cheap and not a problem to find at all. Then I went to go check out and found that none of them ship to Hawaii (:( whyyyy tarrifs) so it looks like I'm going to be searching on Amazon for the best prices again even if that means a little bit of a cost raise. 

Aside from that, now it looks like I've finished my PCB and it's not looking to bad if I say so myself. The pieces are relatively simple to fix and put on so I think it's looking pretty good so far.

![Screenshot 2025-06-19 11 49 11 PM](https://github.com/user-attachments/assets/ae6cd512-47b7-4854-95fc-5c38adcaf6da)

I did spend quite a bit of time trying to fix all the rails, but pretty much I think this should be the final version of my PCB. Im planning on having the buttons on top and the power and potentiometer coming out of the back just to avoid having some things at awkward positions while I'm using the pen. 

# June 20, 2025 (5 hrs)

I spend A LOT of time trying to finalize my BOM today so I can start working on the CAD to place everything. I did start with Amazon thinking I wouldn't be able to afford shipping from anywhere else when I happened to stumble on DigiKey! Thank god they're US based so there's not going to be too many charges aside from regular shipping to Hawaii. Majority of the parts that I'm going to need are just going to be soldered though-hole on my PCB since it's easier for my project. I am keeping some of the parts on Amazon just because I feel like those should be higher quality items that are vetted more for my project so hopefully that's ok. I did end up picking a nozzle from what an Ender 3D printer would be using because I didn't want my project to be your run-of-the-mill 3D pen, I did want to try and be a little more creative so I wanted to try and play around with that type of heat tip.

So far this is what I have in my BOM, it's pretty messy but I think I should be able to clean it up pretty nicely over the next two days. For me personally, I'm trying to finish this project BEFORE July so I can eventually get enough points for that 3D printer.
