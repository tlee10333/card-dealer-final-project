---
layout: page-fullwidth
subheadline: "Engineering Systems"
title: "Our Team's Engineering Divisions"
teaser: "Our interdisciplinary project utilizes Mechanical, Electrical, and Software/Firmware engineering components. You can learn about each system and how it was designed throughout the project here."
permalink: "/system/"
mediaplayer: true

widget1:
  title: "Mechanical System"
  url: '/system/mechanical/'
  image: mechanical.jpg
  text: "Our product's mechanical structure is composed of three main parts: the card dealer, the pan mechanism that rotates the card dealer, and the table. Click on the button to read more about it"

widget2:
  title: "Electrical System"
  url: '/system/electrical/'
  image: electrical.jpg
  text: "The electrical system of the product is composed a motor shield, DC Motor, (with encoder), stepper motor, buttons, and an LCD screen using an i2C driver. Click on the button to read more about it"

widget3:
  title: "Firmware System"
  url: '/system/firmware/'
  image: firmware.jpg
  text: "The team uses firmware to drive all electrical systems and also contains multiple testing setups for debugging that was used during the integration process. Click on the button to read more about it"



---
# System Overview 
<center>
<div class="row">
        <img src="{{ site.urlimg }}schematic.jpg" alt="">
        <p><i>This is a block diagram of the entire system overview encompassing the major different components of the mechanical, electrical, and firmware systems.</i></p> 
</div><!-- /.row -->
</center>

Overall, our automatic dealer centers around a DC motor which is used to deal cards, and a stepper motor which turns the DC motor around so that it can deal to multiple people. We use buttons which trigger the motors in the firmware, and everything in cleanly integrated into a table. For more information on the specifics, look at the different systems below!

