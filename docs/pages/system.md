---
layout: page-fullwidth
subheadline: "Header"
title: "Style your Header!"
teaser: "These are your options to style the header of each webpage individually. <em>Feeling Responsive</em> uses <a href='http://srobbin.com/jquery-plugins/backstretch/'>Backstretch by Scott Robin</a> to expand them from left to right. The width should be 1600 pixel or higher using a ratio like 16:9 or 21:9 or 2:1."
header:
   image_fullwidth: "header_unsplash_5.jpg"
permalink: "/system/"

widget1:
  title: "About Us"
  url: '/about/'
  image: widget-1-302x182.jpg
  text: 'Our team is made up of four engineers from a diverse set of backgrounds to develop a product that is the intersection between mechanical, electrical, and software engineering.'

widget2:
  title: "About Us2"
  url: '/about/'
  image: widget-1-302x182.jpg
  text: 'Our team is made up of four engineers from a diverse set of backgrounds to develop a product that is the intersection between mechanical, electrical, and software engineering.'

---

<ul>
    {% for post in site.tags.header %}
    <li><a href="{{ site.url }}{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a></li>
    {% endfor %}
</ul>

