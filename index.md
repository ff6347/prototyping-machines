---
layout: default
title: Prototyping Machines
---

This is the documentation for the seminar “prototyping machines” by Fabian Morón Zirfas @ University of Applied Sciences Potsdam (Germany) in summer 2017.  

---

In order to “prototype machines”, we used a series of exercises to familiarize ourselves with resources, methods and principles for the planning and implementation of fast prototypes in the area of “human machine interaction” and “physical computing”. After a series of workshops, we developed a system that connects digital media to the physical environment and provides tangible interfaces.  

## HID Prototypes

{% for page in site.pages %}
{% if page.type != null %}
{% if page.type == "hid" %}

<div class="hid block">
    <img src="{{site.baseurl}}/{{page.url}}/thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}/{{page.url}}">{{page.title}}</a> by {{page.author}}</h3>
    {% if page.summary != null %}
    <p>{{page.summary}}</p>
    {% endif %}
</div>

{% endif %}
{% endif %}
{% endfor %}

## Video Prototpyes

{% for page in site.pages %}
{% if page.type != null %}
{% if page.type == "video" %}

<div class="hid block">
    <img src="{{site.baseurl}}/{{page.url}}/thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}/{{page.url}}">{{page.title}}</a> by {{page.author}}</h3>
    {% if page.summary != null %}
    <p>{{page.summary}}</p>
    {% endif %}
</div>

{% endif %}
{% endif %}
{% endfor %}


## Hardware Prototypes

{% for page in site.pages %}
{% if page.type != null %}
{% if page.type == "hw" %}

<div class="hid block">
    <img src="{{site.baseurl}}/{{page.url}}/thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}/{{page.url}}">{{page.title}}</a></h3>
   <p> by {% for author in page.authors %} <a href="{{ page.author-urls[forloop.index0] }}">{{author}}</a>{% if forloop.last == true %} {%else%}, {% endif %}{% endfor %}</p>
    {% if page.summary != null %}
    <p>{{page.summary}}</p>
    {% endif %}
</div>
{% endif %}
{% endif %}
{% endfor %}

<div class="block"><p>
Read also the summaries of Victor Vinas thesis “Box. Open System for Connected People” which was the basis for the hardware prototypes.  
<ul>
{% for page in site.pages %}
{% if page.type != null %}
{% if page.type == "paper" %}
<li><a href="{{site.baseurl}}/{{page.url}}">{{page.title}}</a></li>
{% endif %}
{% endif %}
{% endfor %}
</ul>
</p></div>
