/*
 * cartest1.cxx
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
#include <wiringPi.h>
#include <pthread.h> 
using namespace std;
#define NUM_THREADS 1
#define input1 3
#define input2 22
#define input3 23
#define input4 24  //a motor being connected to GPIO 6
#define enable1 21
#define enable2 22
#define Trig1 4
#define Echo1 5
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

//manual CONTROL
void* manual(void* args)
{
wiringPiSetup();	
	int motor[4];
	motor[0]=input1;
	motor[1]=input2;
	motor[2]=input3;
	motor[3]=input4;
	int i=0;
	for(i=0;i<4;i++){
		pinMode (motor[i],OUTPUT);
		digitalWrite(motor[i],LOW);		
		}	
	char input;	
	while(1){
		scanf("%c",&input);
		if (input=='s'){
			printf("Backward");
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);
			digitalWrite(input1,LOW);
			digitalWrite(input2,HIGH);
			digitalWrite(input3,LOW);
			digitalWrite(input4,HIGH);
			}else if(input=='a'){
			printf("Left");
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);
			digitalWrite(input1,HIGH);
			digitalWrite(input2,LOW);
			digitalWrite(input3,LOW);
			digitalWrite(input4,LOW);
				}else if(input=='d'){
			printf("Right");
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);
			digitalWrite(input1,LOW);
			digitalWrite(input2,LOW);
			digitalWrite(input3,HIGH);
			digitalWrite(input4,LOW);
					}else if(input=='x'){
			printf("STOP");
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);	
			digitalWrite(input1,LOW);
			digitalWrite(input2,LOW);
			digitalWrite(input3,LOW);
			digitalWrite(input4,LOW);
						}else if(input=='w'){
			printf("Forward");			
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);			
			digitalWrite(input1,HIGH);
			digitalWrite(input2,LOW);
			digitalWrite(input3,HIGH);
			digitalWrite(input4,LOW);
		}else if(input=='b'){
			printf("Finish");
			digitalWrite(enable1,HIGH);
			digitalWrite(enable2,HIGH);
			digitalWrite(input1,LOW);
			digitalWrite(input2,LOW);
			digitalWrite(input3,LOW);
			digitalWrite(input4,LOW);
			break;
		}	
	}
	return 0;
}

//automatic CONTROL
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
	
void* automatic(void* args)
{
	
	int rDis=20;
	int rCount=0;
	float dis1;
		if(wiringPiSetup()==-1){
		printf("Fail!!!");
		//return 1;
		}
	
	ultrasonic();
			wiringPiSetup();
			int motor[4];
			motor[0]=input1;
			motor[1]=input2;
			motor[2]=input3;
			motor[3]=input4;
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
					delay(10);
					if(distance2<rDis){
						digitalWrite(enable1,HIGH);
						digitalWrite(enable2,HIGH);
						digitalWrite(input1,LOW);
						digitalWrite(input2,LOW);
						digitalWrite(input3,LOW);
						digitalWrite(input4,LOW);
						delay(300);
						digitalWrite(enable1,HIGH);
						digitalWrite(enable2,HIGH);
						digitalWrite(input1,LOW);
						digitalWrite(input2,LOW);
						digitalWrite(input3,HIGH);
						digitalWrite(input4,LOW);
						delay(300);
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
						digitalWrite(enable1,HIGH);
						digitalWrite(enable2,HIGH);			
						digitalWrite(input1,HIGH);
						digitalWrite(input2,LOW);
						digitalWrite(input3,HIGH);
						digitalWrite(input4,LOW);
							}
								
					}
				}						
		}				
	return 0;	
	}	


int main()
{	
	int mode;
	printf("Please choose a mode");
	cin>>mode;
	if(mode==1){
	
	    
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        
        int ret = pthread_create(&tids[i], NULL, manual, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    
    pthread_exit(NULL);
	}if(mode==2){
			    
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        
        int ret = pthread_create(&tids[i], NULL, automatic, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    
    pthread_exit(NULL);
		
		}
	
}
