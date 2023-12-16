---
layout: page
title: "Electrical System Overview"
subheadline: "Overview"
teaser: "An overview of the Electrical System of the Automatic Card Dealer."
categories:
    - system
show_meta: false
header:
    title: Electrical System
    background-color: "#EFC94C;"
    image_fullwidth: IMG_5722.jpg

---
<!--more-->


## Harnessing & Electrical System Overview

At the core of our electrical system, we use an `Arduino Uno` and an `Adafruit Motor Shield v2` placed directly on top of the Arduino to drive all hardware and firmware. The Motor shield has the capacity to drive up to 4 DC motors or two steppers, so for our product, it was the perfect amount since we needed one stepper motor and one DC motor.

On top of the motors, we also needed to use buttons with pull up resistors (debounce was handled in firmware)
Here is a schematic diagram that was used to keep track of all the harnessing and wiring for the auto dealer. 

<div class="row ">
    <div class="columns">
        <center><img width=900 src="{{ site.urlimg }}schematic_diagram.jpg" alt="" allowfullscreen>
        <p><i>  A schematic diagram of our electrical system </i></p></center>
    </div><!-- /.columns -->
</div><!-- /.row -->