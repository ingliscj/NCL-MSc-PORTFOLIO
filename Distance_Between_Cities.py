#!/usr/bin/env python
# coding: utf-8

# In[10]:


from geopy.geocoders import Nominatim
from geopy import distance

geolocator = Nominatim(user_agent='Distance_Between_Two_Cities')
print("When entering cities please follow this format: City State(or Country)")
location1 = geolocator.geocode(str(input("Please Enter City 1: ")))
location2 = geolocator.geocode(str(input("Please Enter City 2: "))) 
coor1 = (location1.latitude, location1.longitude)
coor2 = (location2.latitude, location2.longitude)
d = distance.distance
print('The distance between {} and {} is'.format(location1, location2), int(d(coor1, coor2).miles), 'miles.')


# In[ ]:




