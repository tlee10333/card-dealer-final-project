---
#
# Use the widgets beneath and the content will be
# inserted automagically in the webpage. To make
# this work, you have to use › layout: frontpage
#
layout: frontpage
header:
  image_fullwidth: header_unsplash_12.jpg
widget1:
  title: "About Us"
  url: '/about/'
  image: widget-1-302x182.jpg
  text: 'Our team is made up of four engineers from a diverse set of backgrounds to develop a product that is the intersection between mechanical, electrical, and software engineering.'

widget2:
  title: "Our Project"
  url: '/project/'
  text: 'The Automatic Card Dealer is an innovative way to deal cards for card games without human error and maximum efficiency. Centered around human design and seamless integration into the environment, our product is intuitive to use.'
  video: '<a href="#" data-reveal-id="videoModal"><img src="http://phlow.github.io/feeling-responsive/images/start-video-feeling-responsive-302x182.jpg" width="302" height="182" alt=""/></a>'
widget3:
  title: "Progress"
  url: '/sprints/'
  image: widget-github-303x182.jpg
  text: 'Over the course of two to three months, our team used the Agile Scrum framework and went through three sprints total, with each sprint culminating into a design review. Read more about our sprint and progress throughout the sprints.'
#
# Use the call for action to show a button on the frontpage
#
# To make internal links, just use a permalink like this
# url: /getting-started/
#
# To style the button in different colors, use no value
# to use the main color or success, alert or secondary.
# To change colors see sass/_01_settings_colors.scss
#
callforaction:
  url: /gallery/
  text: Gallery ›
  style: alert
permalink: /index.html
#
# This is a nasty hack to make the navigation highlight
# this page as active in the topbar navigation
#
homepage: true
---
