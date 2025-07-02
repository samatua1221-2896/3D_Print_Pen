| Title | Author | Description | Date Started |
| ------------- | ------------- | ------------- | ----------|
| Arm Assistant | @samatua1221-2896 | A custom 3D printing pen | 6/18/25 |

### Overall Time Spent Designing as of July 1: 35 hrs

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

# June 20, 2025 

I spend A LOT of time trying to finalize my BOM today so I can start working on the CAD to place everything. I did start with Amazon thinking I wouldn't be able to afford shipping from anywhere else when I happened to stumble on DigiKey! Thank god they're US based so there's not going to be too many charges aside from regular shipping to Hawaii. Majority of the parts that I'm going to need are just going to be soldered though-hole on my PCB since it's easier for my project. I am keeping some of the parts on Amazon just because I feel like those should be higher quality items that are vetted more for my project so hopefully that's ok. I did end up picking a nozzle from what an Ender 3D printer would be using because I didn't want my project to be your run-of-the-mill 3D pen, I did want to try and be a little more creative so I wanted to try and play around with that type of heat tip.

So far this is what I have in my BOM, it's pretty messy but I think I should be able to clean it up pretty nicely over the next two days. For me personally, I'm trying to finish this project BEFORE July so I can eventually get enough points for that 3D printer.


# June 21, 2025 (10 hrs - last 2 days)

I actually did end up having a much harder time dealing with the actual PCB design of the baord once I realized that my tracks were probabaly too thin for the amount of power that I was trying to use. After plenty of time trying to figure out how to asign net classes to all of my parts, I eventually was able to wire everything up and after even MORE time I was able to manuever all of my wiring around the thicker lines. 

![Screenshot 2025-06-21 8 05 26 PM](https://github.com/user-attachments/assets/fe79749f-b3bf-427d-867b-1afa534a65b0)
![Screenshot 2025-06-21 8 05 56 PM](https://github.com/user-attachments/assets/7ef17aa5-97cd-477a-9ba4-de3519b92036)

I did stop my journal a little early yesterday because of one of my brother's basketball games, but I did end up figuring out all of my BOM materials. So far, it's looking like it'll be around $100, well under the grant limit for my project I hope (fingers crossed!) Listed below is my current BOM that hopefully wont change much more since I'll start working on the CAD now. Majority of my supplies are going to be sourced from Digikey with "higher quality" items coming from Amazon.

![Screenshot 2025-06-21 8 35 13 PM](https://github.com/user-attachments/assets/c7131e94-2cbb-46b5-809a-d3b2fc227a87)

Now I'm going to start making mockups for the whole 3D pen in Onshape, hopefully it won't take too long.

# June 22, 2025 (5 hrs)

So that actually took a LOT longer than I thought it would take. I'm realizing now that a lot of the components are bigger than I previously thought they would be so I'm going to try and shift around the design a little bit to try and mae sure that I can keep what I have so far which is there below.

![Screenshot 2025-06-22 1 20 25 AM](https://github.com/user-attachments/assets/783cc91b-34ca-4a41-b5d4-95756fcef85d)

# June 28, 2025 (3 hrs)

It's been a while since I've been able to work on the project, but now it loks like that it should be wrapping up now. CAD is now I belive completely finished with so now I have a complete plan for where everything will go and how it will all work. I did have to change a couple of things due to the size of the nozzle. I was planning on having everything to do with the nozzle be wrapped inside of the case but I don't believe I'm skilled in CAD enough to know how to do it in a way that would protect the PCB and be physically stable. I did add a couple of things like ventilation holes on the side of the nozzle and shifted around the placement of the motor that will carry the filament. Aside from that, just minor things like smoothing out all the edges and making sure all my parts are the correct ones are pretty much all I have left for CAD. Soon I'll start on writing the code for it but it should be a pretty simple task.

![Screenshot 2025-06-28 7 53 55 PM](https://github.com/user-attachments/assets/a39868c7-b90c-4188-8d13-2a0990ff9dc0)
![Screenshot 2025-06-28 7 54 03 PM](https://github.com/user-attachments/assets/fd2785b7-2fc6-4383-8c06-95dd6d59b10b)
![Screenshot 2025-06-28 7 45 57 PM](https://github.com/user-attachments/assets/529f8018-048b-4713-bf77-519b191ee0d6)

Ok, I just finished writing up the code with a good amount of help from ChatGPT since I'm not super experienced in it but I do believe that I am now finished and now I'm going to be working on the README and the submission files, crossing fingers for a good result!

# July 1, 2025 (2 hrs)

Today I really just spent time working on the README file and doing the finishing touches on all of my CAD files and labeling. Hopefully the project looks good and I'm going on the submission now, so wish me luck!
