---
layout: page-fullwidth
title: "Mechanical System Overview"
subheadline: "Overview"
teaser: "An overview of the Mechanical System of the Automatic Card Dealer. The mechanical structure is composed of three main parts: the card dealer, the pan mechanism that rotates the card dealer, and the table."
categories:
    - system
show_meta: false
header:
    title: Mechanical System
    background-color: "#EFC94C;"
    image_fullwidth: mechanical.jpg

---
<!--more-->


## Card Dealer
The card dealer is made up of a 3D-printed case to hold the cards (black), a weight to push down on the cards (red), a roller with a DC motor (blue), and a gate to limit the number of cards that are ejected by the roller (orange). 


<center>
<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}caddealertop.jpg" alt="">
        <p><i>Top view of the automatic card dealer in CAD</i></p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}cadfront.jpg" alt="">
        <p><i>Front view of the automatic card dealer in CAD</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->
</center>


Cards are put into the card holder, then the weight is placed on top of them. The weight arm is made up of a ball bearing at the end that acts as the weight, which rests above the center of the roller. A rubber band is used to hold the weight arm in place and give it a little more force. Importantly, this rubber band can be moved back and forth along the weight arm such that the cards can be easily reloaded and then pressure be reapplied to allow them to deal consistently. A 1mm gap in the gate prevents excess cards from being ejected while preventing any friction against the gate walls that cause cards to get stuck. The final version of the card holder has some ease of use additions, such as finger holes to allow for easier removal of cards and a rubber band groove so the placement of the rubber band is always the same, resulting in a more consistent weight force.

<center>

<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}real_dealer1.jpg" alt="">
        <p><i>Top view of the card dealer before integration</i></p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}real_dealer2.jpg" alt="">
        <p><i>Top view of card dealer after integration</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->


<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}caddealershroud.jpg" alt="">
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <p>To increase the aesthetic appeal of the system a shroud was placed on the card dealer to cover the pan mechanism, wiring, and electronics. It also holds the LCD, player count buttons, and deal button to make them more accessible for users.</p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->
</center>


## Pan Mechanism
The pan mechanism makes use of 3 external spur gears, an internal spur gear, and a stepper motor to drive it.

<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}bottom_gears.jpg" alt="">
        <p><i>Bottom view of the platform and external spur gears</i></p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}internal_gear.jpg" alt="">
        <p><i>Top view of the internal spur gear</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->

The stepper motor gear drives the pan mechanism while the other two gears keep the platform level. The hole in the center of the platform allows the power cable to connect to the motor shield without getting tangled. The pan has two legs attached to it that hold up the card dealer. These legs also support the breadboard that we use in our wiring, and the Arduino rests on the pan “table” - the orange platform the legs are bolted into.
<center>
<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}isometric_pan_cad.jpg" alt="">
        <p><i>Isometric view of the full pan assembly </i>  </p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}bottom_pan_cad.jpg" alt="">
        <p><i>Bottom view of the gear system</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->
</center>

## Table

The table design went through multiple iterations and design sprints before a final design was settled on and built. From the beginning, the main goals for the table were that it would:
1. Be visually appealing
2. Have the ergonomic design be specified to the teams body
3. Act as a lower set, end table, rather than a chest high, sit up table
4. Be able to integrate the automatic card dealer sleekly, easily, and effectively

After multiple design sprints, the design of felt on a circular table was decided upon. In fabricating the circular shape, the Shop Bot CNC Mill was used to cut out concentric circles that were used in the table top, supports, and footers. These were then screwed together to form a solid top with a lip around the bottom where felt could be stretched taut and stapled. Along with a nice felt top, a piece of plywood was coated with a cherry cerise finish in order to lend a dark, red hue as a centerpiece that contrasted the blue felt of the table.

<center>
<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}table_parts.jpg" alt="">
        <p><i>Plywood table base components </i></p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}table_complete_isometric.jpg" alt="">
        <p><i>assembled table</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->
</center>

After the tabletop was assembled, the centerpiece was attached, and the felt was stretched taut across the surface, 14in legs were attached to the bottom, making a nice end table look that is sleek, practical, and works for all players.

Once the table was built, then it had to be integrated with the card dealer. For this to be done a central column was added on which the card dealer could sit upon. This was fairly easy to build and fit comfortably and securely under the table, attached to the rest of the table through four arms.

<center>
<div class="row t60">
    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}painted_center_support.jpg" alt="">
        <p><i>Central column (painted black) </i> </p>
    </div><!-- /.medium-6.columns -->

    <div class="medium-6 columns b30">
        <img src="{{ site.urlimg }}table_side.jpg" alt="">
        <p> <i>Central column integrated into table</i></p>
    </div><!-- /.medium-6.columns -->
</div><!-- /.row -->
</center>