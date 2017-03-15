#include<stdio.h>
#include<wiringPi.h>
#include<sys/time.h>

int flag = 0;
int val = 0;

int main()
{
	wiringPiSetup();
	pinMode(8,OUTPUT);
	pinMode(9,INPUT);
	
	digitalWrite(8,LOW);
	digitalWrite(8,HIGH);
	delayMicroseconds(10);
	digitalWrite(8,LOW);
	
	struct timeval start,end;
	
	while(1)
	{
		digitalWrite(8,LOW);
	    digitalWrite(8,HIGH);
		delayMicroseconds(10);
		digitalWrite(8,LOW);
		
		while(1)
		{
			val = digitalRead(9);
			if(val == HIGH)
			{
				printf("start\n");
				break;
			}
			else
				continue;
		}
		// get time1
		gettimeofday(&start,NULL);
			while(1)
			{
				val = digitalRead(9);
				if(val == LOW)
				{
					printf("end\n");
					break;
				}
				else
					continue;
			}
		// get time2
		gettimeofday(&end,NULL);
		
		long t1 = start.tv_sec * 1000000 + start.tv_usec;
		long t2 = start.tv_sec * 1000000 + start.tv_usec;
		
		float dis = (float)(t2 - t1)/1000000 * 34000/2;
		printf("%fcm\n", dis);
		delay(2000);
	}
	return 0;
}
