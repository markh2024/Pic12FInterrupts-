# Pic12FInterrupts

## The purpose of this is to show you how to go about using the pic12f range of 8 bit devices   for many uses 

One of the most difficult tasks is understanding how that hardware works

Diagram of  connections using simul ide see links further down 

![SumlIde](https://github.com/user-attachments/assets/042866d9-d291-4bb2-a6bd-5f5c8e3bee7e)


For this  you have to read up on the data sheet (included )  especially when it  come to the use of peripherals  such as timer interrupts, comparators , analogue to digital conversion and what registers to use , capture and compare ,  and much  more 

Bus communications and serial communications are possible with this device  combined  with i2C , one wire , three wire etc

This can be quite challenging  especially if you have never done this before but its rewards are unlimited .  Ive include the sumil ide files  so that you can run simulations on this as well and see how it works and fits together. This is extremely helpful and  would pay  you to go and download this 

Links are   below  but make sure you download the most stable version  in order to run this 

Website: https://simulide.com

Patreon: https://www.patreon.com/simulide 

You will  also need Java 11 , 12 installed  but at any rate  being developer or aspiring to be a developer or enter into design will require  you have knowledge of this at any rate 

Most Linux distro's are shipped with Java latest version 

Additionally you will need MPLABX  and to start with the XC8 , XC16 compilers  all of which you can download via  Microchips website 

Address is as follows https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide   all details are contained on their site   one of the few helpful companies that you can deal with  and they are helpful 

Included also are flow charts showing you how I arrived at my answers and  a spread sheet  for libre office which does contain  a basic module to assist you with determine which  values to send to the port  

If you are using MS office then you will have to port that code to VBA  I shouldn’t think that will be tgo hard for most of you to achieve 

You may need to grant  permissions to run macros but I can assure you they are safe to use  and  is  non destructive  code 

If you want to see the code then Ive posted this as well for you  and yet another excellent open source package that you could also learn much from especially with a view to automation 

Hex code is contained in the folder  named distribution so that  you can load this into your device straight away however  you may wish to add some debounce  to this for which there is function  included in the  C coding itself  and in which case you will need to re compile 


Thanking you and  hope this aids in your future development with regards embedded devices 

Enjoy have fun and learn as much as you can  as this type of knowledge  really will pay off and open may doors for you  thus use it  wisely 

Below is a  the flow chart  I put together to develop a final solution 

![FlowChartInterrupt](https://github.com/user-attachments/assets/6ede5d61-876b-4868-90c0-f8bc1681a9a4)


Other site links  or where you can  find or discuss  topics or  other ideas  
are as follows 

Facebook  https://www.facebook.com/mark.harrington.14289/

Instagram https://www.instagram.com/markukh2021

Codeshare under Mark David Harrington  https://codeshare.io/LwKoQ7

Pastebin https://pastebin.com/u/Mark2020H


Cheers  all , Mark Harrington  Kent London UK DA6 8NP   happy coding 
