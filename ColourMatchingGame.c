//speed, inputTime and delayTime to be tested and changed accordingly
void levelMod(int level, int & speed, int & inputTime, int & delayTime)
{
	speed = 10+level*3;
	inputTime = 16000-(level*1000);
	delayTime = 1000 - (75*level);
}

//DownUp & leftRight to Be Synced
void motorDownUp (int mpower,int delayTime)
{
		nMotorEncoder[motorA] = 0;
		motor[motorA] = -mpower;
		while(nMotorEncoder[motorA]>-50)
		{}
		motor[motorA] = 0;
		nMotorEncoder[motorA] = 0;
		wait1Msec(delayTime);
		motor[motorA] = mpower;
		while(nMotorEncoder[motorA]<50)
		{}
		motor[motorA] = 0;
}

void position(int n, int*output, int*positions, int mpower)
{
	nMotorEncoder[motorB] = 0;
	if (n == 0)
	{
		motor[motorB] = mpower;
		while(nMotorEncoder[motorB]<positions[output[n]-1])
		{}
		motor[motorB] = 0;
	}
	if (output[n] - (output[n-1] >= 0))
	{
		motor[motorB] = mpower;
		while(nMotorEncoder[motorB]<(positions[output[n]-1]-positions[output[n-1]-1]))
		{}
		motor[motorB] = 0;
	}
	if (output[n] - output[n-1]<0)
	{
		motor[motorB] = -mpower;
		while(nMotorEncoder[motorB]>((positions[output[n]-1]-positions[output[n-1]-1])))
		{}
		motor[motorB] = 0;
	}

}

void resetPosition(int*positions, int*output, int i)
{
	nMotorEncoder[motorB] = 0;
	motor[motorB] = -15;
	while(nMotorEncoder[motorB] != -(positions[output[i-1]-1]))
	{}
	motor[motorB] = 0;
}

int randomColour()
{
	int rand = random(6);
	if (rand == 0)
		return 1;
	else
		return rand;
}

bool win(int*output, int*input,int x, int i)
{
	while(output[x] == input[x] && x<i)
		x++;
	if(output[x-1] != input[x-1])
		return false;
	else
		return true;
}

task main()
{
	displayString(0, "Welcome");
	// more instructions to be added on screen as game goes
	//maybe buttons can be used later on to pick modes and levels, and read through instructions
	displayString(1, "Press Any Button to Start");
	int const MAX = 30;
	int positions[6] = {0,36,72,108,144,180};
	int output[MAX];
	int input[MAX];
	int i = 0, x = 0;
	int level=1, speed, inputTime, delayTime;
	SensorType[S1] = sensorTouch;
	SensorType[S2] = sensorColorNxtFULL;
	while(nNxtButtonPressed == 0)
	{}
	for(int numColor = 3;numColor<31 ;numColor += 3)
	{
		levelMod(level, speed, inputTime, delayTime);

		for(i = 0; i<numColor; i++)
		{
			output[i]=randomColour();
		}

		for(int n = 0; n<i ;n++)
		{
			nMotorEncoder[motorB] = 0;
			position(n,output, positions,speed);
			motorDownUp(speed, delayTime);
		}
	//	for(int z = 0; z<i;z++)
//		{
		//	displayString(z, "%s", output[z]);
		// }
		resetPosition(positions, output, i);
		//time[T1] = 0;
		for(int n = 0; n<i; n++)
		{
			while(SensorValue[S1] == 0)
			{}
			while(SensorValue[S1] == 1)
			{}
			input[n] = SensorValue[S2];
		}
	/*	while(win(output,input,x) && x<i)
		{
			x++;
		}*/
		while(output[x] == input[x] && x<i)
		{
			x++;
		}



		if(output[x-1] != input[x-1])
			numColor = 31;
		else
			level++;
		/*if (win(output,input,x))
			//Winner dance
			level++;
		else
			numColor = 31;*/
	}
}
