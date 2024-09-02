---
layout: default
title: Prototyping Machines
---

This is the documentation for the seminar “prototyping machines” by Fabian Morón Zirfas @ University of Applied Sciences Potsdam (Germany) in summer 2017.

---

In order to “prototype machines”, we used a series of exercises to familiarize ourselves with resources, methods and principles for the planning and implementation of fast prototypes in the area of “human machine interaction” and “physical computing”. After a series of workshops, we developed a system that connects digital media to the physical environment and provides tangible interfaces.

## HID Prototypes

{% for page in collections.pages %}

{% if page.data.type != null %}
{% if page.data.type == "hid" %}

<div class="hid block">
    <img src="{{site.baseurl}}{{page.url}}thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}{{page.url}}">{{page.data.title}}</a> by {{page.data.author}}</h3>
    {% if page.data.summary != null %}
    <p>{{page.data.summary}}</p>
    {% endif %}
</div>

{% endif %}
{% endif %}
{% endfor %}

## Video Prototpyes

{% for page in collections.pages %}
{% if page.data.type != null %}
{% if page.data.type == "video" %}


<div class="hid block">
    <img src="{{site.baseurl}}{{page.url}}thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}{{page.url}}">{{page.data.title}}</a> by {{page.data.author}}</h3>
    {% if page.data.summary != null %}
    <p>{{page.data.summary}}</p>
    {% endif %}
</div>

{% endif %}
{% endif %}
{% endfor %}


## Hardware Prototypes

{% for page in collections.pages %}
{% if page.data.type != null %}
{% if page.data.type == "hw" %}

<div class="hid block">
    <img src="{{site.baseurl}}{{page.url}}thumb.png" alt="thumbnail">
    <h3><a href="{{site.baseurl}}{{page.url}}">{{page.data.title}}</a></h3>
   <p> by {% for author in page.data.authors %} <a href="{{ page.data.author-urls[forloop.index0] }}">{{author}}</a>{% if forloop.last == true %} {%else%}, {% endif %}{% endfor %}</p>
    {% if page.data.summary != null %}
    <p>{{page.data.summary}}</p>
    {% endif %}
</div>
{% endif %}
{% endif %}
{% endfor %}

## TL;DR

<div class="block"><p>
Read also the summaries of Victor Vinas thesis “Box. Open System for Connected People” which was the basis for the hardware prototypes.
<ul>
{% for page in collections.pages %}
{% if page.data.type != null %}
{% if page.data.type == "paper" %}
<li><a href="{{site.baseurl}}{{page.url}}">{{page.data.title}}</a></li>
{% endif %}
{% endif %}
{% endfor %}
</ul>
</p></div>
