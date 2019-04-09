/*
 * ultrasonicTest1.cxx
 * 
 * Copyright 2019  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;
#define Trig1 2
#define Echo1 3
#define left1 27
#define left2 28
#define right1 29
#define right2 25
#include <stdio.h>
#include <wiringPi.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>


void ultrasonic(void){
	pinMode(Echo1,INPUT);//define Echo as input
	pinMode(Trig1,OUTPUT);//define Trig as output
	}
	
	

float disMeasure(void){
	struct timeval tv1;	
	struct timeval tv2;
	long start,stop;
	float dis1;
	digitalWrite(Trig1,LOW);
	delayMicroseconds(2);
	digitalWrite(Trig1,HIGH);
	delayMicroseconds(10);
	digitalWrite(Trig1,LOW);
	while(!(digitalRead(Echo1)==1));
	gettimeofday(&tv1,NULL);
	while(!(digitalRead(Echo1)==0));
	gettimeofday(&tv2,NULL);
	start=tv1.tv_sec*1000000+tv1.tv_usec;
	stop=tv2.tv_sec*1000000+tv2.tv_usec;
	dis1=(float)(stop-start)/1000000*34000/2;
	return dis1;
	}

int main(void)
{
	int rDis=20;
	int rCount=0;
	float dis1;
		if(wiringPiSetup()==-1){
		printf("Fail!!!");
		return 1;
		}
	
	ultrasonic();
			wiringPiSetup();
			int motor[4];
			motor[0]=left1;
			motor[1]=right1;
			motor[2]=left2;
			motor[3]=right2;
			int i=0;
			for(i=0;i<4;i++){
				pinMode (motor[i],OUTPUT);
				digitalWrite(motor[i],LOW);		
				}
			char input;			
			for(;;){
				scanf("%c",&input);
				if(input=='w'){
					while(1){
					dis1=disMeasure();
					float distance2=dis1;
					printf("%f \n",distance2);
					printf("distance1=%0.2f cm\n",dis1);
					delay(1000);
					if(distance2<rDis){
						digitalWrite(left1,HIGH);
						digitalWrite(right1,LOW);
						digitalWrite(left2,LOW);
						digitalWrite(right2,LOW);
						delay(1000);
						rCount=rCount+1;
						if(rCount==3){
							rCount=0;
							rDis=rDis+25;
							if(rDis>100){
								rDis=rand()%(19-5+1)+5;
								}
							}
						printf("%d \n",rCount);
						printf("%d \n",rDis);										
						}else if(distance2>rDis){
						digitalWrite(left1,LOW);
						digitalWrite(left2,HIGH);
						digitalWrite(right1,HIGH);
						digitalWrite(right2,LOW);
							}
								
					}
				}						
		}		
		
	return 0;
}


