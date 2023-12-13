---
layout: page
title: "Mechanical System Overview"
subheadline: "Overview"
teaser: "An overview of the Mechanical System of the Automatic Card Dealer."
categories:
    - system
show_meta: false
header:
    title: Mechanical System
    background-color: "#EFC94C;"
    image_fullwidth: unsplash_brooklyn-bridge_header.jpg
    caption: This is a caption for the header image with link
    caption_url: https://unsplash.com/
---
<!--more-->

## Card Dealer
The mechanical structure is composed of three main parts: the card dealer, the pan mechanism that rotates the card dealer, and the table. 

The card dealer is made up of a 3D-printed case to hold the cards (black), a weight to push down on the cards (red), a roller with a DC motor (blue), and a gate to limit the number of cards that are ejected by the roller (orange). 

Cards are put into the card holder, then the weight is placed on top of them. The weight arm is made up of a ball bearing at the end that acts as the weight, which rests above the center of the roller. A rubber band is used to hold the weight arm in place and give it a little more force. Importantly, this rubber band can be moved back and forth along the weight arm such that the cards can be easily reloaded and then pressure be reapplied to allow them to deal consistently. A 1mm gap in the gate prevents excess cards from being ejected while preventing any friction against the gate walls that cause cards to get stuck. The final version of the card holder has some ease of use additions, such as finger holes to allow for easier removal of cards and a rubber band groove so the placement of the rubber band is always the same, resulting in a more consistent weight force.

[video of placing the cards in the card holder?]
To increase the aesthetic appeal of the system a shroud was placed on the card dealer to cover the pan mechanism, wiring, and electronics. It also holds the LCD, player count buttons, and deal button to make them more accessible for users.

## Pan Mechanism
The pan mechanism makes use of 3 external spur gears, an internal spur gear, and a stepper motor to drive it.

The stepper motor gear drives the pan mechanism while the other two gears keep the platform level. The hole in the center of the platform allows the power cable to connect to the motor shield without getting tangled. The pan has two legs attached to it that hold up the card dealer. These legs also support the breadboard that we use in our wiring, and the Arduino rests on the pan “table” - the orange platform the legs are bolted into.

## Table

The table design went through multiple iterations and design sprints before a final design was settled on and built. From the beginning, the main goals for the table were that it would:
1. Be visually appealing
2. Have the ergonomic design be specified to the teams body
3. Act as a lower set, end table, rather than a chest high, sit up table
4. Be able to integrate the automatic card dealer sleekly, easily, and effectively

In the process of creating this design, the team went through two design sprints. The first was to decide upon the overall design of the table structure and how it would integrate the card dealer. Six designs were proposed and a weighted decision matrix was created. The desire was to balance simplicity with a cool, effective design, so 5 different metrics were valued and weighted 

After an overall design was decided upon, a second sprint was done to determine another important component of the project, the aesthetics. Multiple different options were presented, covering material from hardwood to felt tops, their costs were all determined, and a final design of felt was chosen because of its sleekness, ease of assembly, and cheapness.


The design of felt on a circular table presented a unique construction challenge, as making circular designs into wood is always difficult. After doing some testing, it was found that the maximum diameter of the table would ideally be 44 inches in order for everyone to be able to reach their cards. In fabricating the circular shape, the Shop Bot CNC Mill was used to cut out concentric circles that were used in the table top, supports, and footers. These were then screwed together to form a solid top with a lip around the bottom where felt could be stretched taut and stapled.

Along with a nice felt top, the team wanted a nicer surface for the cards to fall upon, and thus a piece of plywood was coated with a cherry cerise finish in order to lend it a dark, red hue that contrasted well with the blue felt that was chosen for the table color.


After the table top was assembled, the centerpiece was attached, and the felt was stretched taut across the surface, 14in legs were attached to the bottom, making a nice end table look that is sleek, practical, and works for all players.


Once the table was built, then it had to be integrated with the card dealer. For this to be done there had to be a central column on which the card dealer could sit upon. This was fairly easy to build and fit comfortably and securely under the table, attached to the rest of the table through four arms.
