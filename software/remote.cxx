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

#define left1 27
#define left2 28
#define right1 29
#define right2 25  //a motor being connected to GPIO 6


int main()
{
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
	while(1){
		scanf("%c",&input);
		if (input=='s'){
			printf("Backward");
			digitalWrite(left1, LOW);
			digitalWrite(right1, HIGH);
			digitalWrite(left2,HIGH);
			digitalWrite(right2,LOW);
			}else if(input=='a'){
			printf("Left");
			digitalWrite(left1,HIGH);
			digitalWrite(right1,LOW);
			digitalWrite(left2,LOW);
			digitalWrite(right2,LOW);
				}else if(input=='d'){
			printf("Right");
			digitalWrite(left1,LOW);
			digitalWrite(right1,LOW);
			digitalWrite(left2,LOW);
			digitalWrite(right2,HIGH);
					}else if(input=='x'){
			printf("STOP");
			digitalWrite(left1,LOW);
			digitalWrite(right1,LOW);
			digitalWrite(left2,LOW);
			digitalWrite(right2,LOW);
						}else if(input=='w'){
			printf("Forward");
			digitalWrite(left1,HIGH);
			digitalWrite(right1,LOW);
			digitalWrite(left2,LOW);
			digitalWrite(right2,HIGH);
		}else if(input=='b'){
			printf("Finish");
			digitalWrite(left1,LOW);
			digitalWrite(right1,LOW);
			digitalWrite(left2,LOW);
			digitalWrite(right2,LOW);
			break;
		}	
	}
	return 0;
}


