#include "TaskManager.cpp"

int main()
{
	int turn=CONTINUE;

	while(turn!=EXIT)
	{
		ioHandler io;
		int typeSelect;

		typeSelect =io.selectType();	//자료형 선택

		if( typeSelect<INT || STRING<typeSelect) 
			break;

		if(typeSelect == INT)
		{
			TaskManager<int> tsk;
			turn = tsk.startTask();
		}
		else if(typeSelect == DOUBLE)
		{
			TaskManager<double> tsk;
			turn = tsk.startTask();
		}
		else if(typeSelect == RECTANGLE)
		{
			TaskManager<Rectangle> tsk;
			turn = tsk.startTask();
		}
		else if(typeSelect == STRING)
		{
			TaskManager<string> tsk;
			turn = tsk.startTask();
		}
		else
			turn =EXIT;

	}//End of while loop
	return 0;
}