import sys
import math

myLongitude = input()
myLatitude = input()
number = int(input())

bestDistanse = math.inf

for i in range(number):
    n, address, temprary, _, longitude, latitude = [i for i in input().split(";")]
    longitude = longitude.replace(",", ".")
    latitude = latitude.replace(",", ".")
    myLongitude = myLongitude.replace(",", ".")
    myLatitude = myLatitude.replace(",", ".")
    x = (float(longitude) - float(myLongitude)) * math.cos((float(latitude) + float(myLatitude)) / 2)
    y = (float(latitude) - float(myLatitude))
    distanse = math.sqrt(float(x) * float(x) + float(y) * float(y)) * 6371
    if distanse < bestDistanse:
        bestDistanse = distanse
        resultAddress = address

print(resultAddress)