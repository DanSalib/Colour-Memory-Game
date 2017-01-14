//Colour Matching Memory Game
void levelMod(int level, int & speed, int & inputTime, int & delayTime)
{
	speed = 25*level;
	inputTime = 1000/level;
	delayTime = 4000 - (1000*level);
}

void motorDownUp (int pow,int delayTime)
{
	
	if(down)
	{
		nMotorEncoder[motorA] = 0;
		motor[motorA] = pow;
		while(nMotorEncoder[motorA]<90)
		{}
		motor[motorA] = 0;
		wait1Msec(delayTime);
		motor[motorA] = -pow;
		while(nMotorEncoder[motorA]<90)
		{}
		motor[motorA] = 0;
	}	
}

int position(int n, int output[], int positions[], int pow)
{ 
	nMotorEncoder[motorB] = 0;
	if (n == 0)	
	{
		motor[motorB] = pow;
		while(nMotorEncoder[motorB]<positions[output[n]-1])
		{}
		motor[motorB] = 0;
	}
	else if (output[n] == output[(n-1)])
	{}	
	else if (output[n] - (output[n-1]>0)
	{
		motor[motorB] = pow;
		while(nMotorEncoder[motorB]<fabs((positions[output[n]-1]-positions[output[n-1]-1]))
		{}
		motor[motorB] = 0;
	}
	else
	{
		motor[motorB] = -pow;
		while(nMotorEncoder[motorB]<fabs((positions[output[n]-1]-positions[output[n-1]-1])
		{}
		motor[motorB] = 0;
	}
		
}

void resetPosition()
{
	int endPosition = nMotorEncoder[MotorB];
	nMotorEncoder[MotorB] = 0;
	motor[motorB] = 50;
	while(nMotorEncoder[MotorB<endPosition])
	{}
	motor[motorB] = 0;
}

int randomInt()
{
	return rand () %7+1;
}

bool win(output[], input[],x)
{
	if(output[x] != input[x])
		return false;
	else
		return true;
}


task main()
{
	displaystring(0, "Welcome");
	// more instructions to be added on screen as game goes
	//maybe buttons can be used later on to pick modes and levels, and read through instructions
	displaystring(1, "Press Any Button to Start");
	int const MAX = 30;
	int positions[6] = {0,36,72,108,144,180};
	int endPosition
	int output[MAX];
	int input[MAX];
	int i = 0, x = 0, level;
	int level=1, speed, inputTime, delayTime;
	SensorType[S1] = sensorTouch;
	SensorType[S2] = sensorColorNxtFULL;
	while(nNxtButtonPressed == 0)
	{}
	for(int numColor = 3;numColor<31 ;numColor += 3)
	{
		levelMod(level, speed, inputTime, delayTime)
		
		for(i = 0; i<numColor; i++)
		{
			output[i]=randomInt();
		}
		
		for(int n = 0; n<i ;n++)
		{
			position(n,output, positions,speed)
			motorDownUp(speed, delayTime);
		}
		resetPosition();
		time[T1] = 0;
		for(int n = 0; n<i; n++)
		{
			while(SensorVale[S1] == 0)
			{}
			while(SensorValue[S1] == 1)
			{}
			input[n] = SensorValue[S2];
		}
		while(win(output,input,x) && x<i)
		{
			x++;
		}
		if (win(ouput,input,x))
			//Winner dance
		else
			//loser dance
		
		level++;
		
	}	
}
