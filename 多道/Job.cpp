#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Job
{
public:
	string Name;//作业名称
	
	int ExecuteTime;//作业估计运行时间
	int ExecuteRemainingTime;//作业估计运行时间的剩余时间
	

	int StartHour;//进入时间对应的小时
	int StartMinute;//进入时间对应的分钟

	int ExecuteHour;//开始执行时间对应的小时
	int ExecuteMinute;//开始执行时间对应的分钟

	int EndHour;//结束时间对应的小时
	int EndMinute;//结束时间对应的分钟
	

	int TurnOverTime;//周转时间，用分钟记
	double WeightedTurnOverTime;//带权周转时间
	
	bool State;//标记该作业是否执行完成
	bool InMemory;//标记作业是否在内存

	bool FirstExecute;//标记是否是第一次执行
};

int compare(Job job1, Job job2)
{
	if(job1.StartHour < job2.StartHour)
	{
		return 0;
	}
	
	else if(job1.StartHour > job2.StartHour)
	{
			return 1;
	}

	else
	{
		if(job1.StartMinute < job2.StartMinute)
		{
			return 0;
		}
		else if(job1.StartMinute > job2.StartMinute)
		{
			return 1;
		}else
		{
			return 0;
		}
	}
}
void TimeSort(Job *jobs, int length)
{
	int i,j,last;
	Job t;
	i = length;
	while(i > 0)
	{
		last = 0;
		for(j =0; j < i-1; j++)
		{
			if(compare(jobs[j], jobs[j+1]))
			{
				t = jobs[j+1];
				jobs[j+1] = jobs[j];
				jobs[j] = t;
				last = j+1;
			}
		}
		i = last;
	}
}
//计算已经完成的作业数目
int getFinishedNumber(Job* jobs, int jobCnt)
{
	int num = 0;
	for(int i = 0; i < jobCnt; i++)
	{
		if(jobs[i].State == true)
		{
			num ++;
		}
	}
	return num;
}

void FCFS(int numberOfTracks)
{
	int jobCnt = 0;//作业总数记录
	int i;

	cout << "输入作业总数:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "输入作业名称:";
		cin >> jobs[i].Name;

		cout << "输入作业进入时间:(例如: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "输入作业估计运行时间:";
		cin >> jobs[i].ExecuteTime;
		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //按照时间先后给作业排序
	
	//到此，数据已经加载完毕，并根据时间的先后顺序进行了排序，下面进入核心算法
	//第一步，每个时间点，调度谁去内存
	//第二步，每个时间点，执行哪个作业

	//当前没有完成的作业分两类，一类是在内存中，一类是不在内存中
	
	int memoryJobCnt = 0;//内存中作业数目
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//当前没有完成且不在内存的作业数目
		
		
	//当前时间
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;
		
	//存在作业没执行的话，就一直执行
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************调作业到内存************************
		//选几个还没有完成的、不在内存的作业调入内存。需要明确一点：先来的先调入！
		//最多选(numberOfTracks-memoryJobCnt)=times个已经到来的作业调入内存

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//临时变量，累计本次调入内存的数目，最多达到times个
			
		for(i =0 ;i < jobCnt; i++)
		{
			if(tmpCnt >= times)
				break;//如果调入内存的作业数目大于了本次内存允许调用的数目，终止。若只允许调入1个，那么tmpCnt=1时候终止循环
			
			if( 
				(
				  jobs[i].StartHour < currentHour 
				  || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)
				) && jobs[i].InMemory == false && jobs[i].State == false
			  )
			{
				jobs[i].InMemory = true;
				notMemoryJobCnt--;
				memoryJobCnt++;
				tmpCnt++;
			}
		}

		//************************【【【【算法核心】】】从内存选一个作业（准备执行）************************
		//作业已经调入内存，并且此刻内存中必定有没有执行完的作业。因为系统是串行的，必定选择一个作业执行。
		//选择最先来的
		int pos = -1;
		for(i = 0; i < jobCnt ;i++)
		{
			if(jobs[i].InMemory==true)
			{
				pos = i;
				break;
			}
		}
			
		//************************执行选择的那个作业（开始执行）************************
		//（1）如果当前内存已经满了的话，直接执行完成jobs[pos]即可。
		//（2）如果当前内存未满并且所有未完成的作业都已经调入到了内存，仍然是直接执行完成jobs[pos]即可。
		//（3）如果不是上面两种情况，即内存未满，且存在作业没有调入到内存。这种情况下，要考虑该作业执行过程中，
		//     是否需要调入新作业到内存。由于上面已经完成了作业调入内存的功能，那么这次调入内存的作业也只会有
		//     一个！这一个一定选择此刻尚未完成、未在内存、开始时间最靠前的作业。还需要判断本次作业执行过程中
		//     的时间和将要调入作业的开始时间的关系。
		//     A:本次作业执行完时，将要调入的作业尚未开始。那就需要执行完本次作业。并且把当前时间修改为将要调
		//       入的这个作业的开始时间。
		//     B:本次作业执行过程中，将要调入的作业来了，那就需要把当前时间设置为将要调入的作业的开始时间，并
		//       且设置本次作业的剩余执行时间。
		//     C:本次作业开始执行的时候，将要调入的作业早已经来过了。这种情况直接交给上面的调入内存步骤解决之。
		
		//针对（1）（2）两种情形
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//先设置下开始执行的时间
			if(jobs[pos].FirstExecute == true)
			{
				jobs[pos].FirstExecute = false;
				jobs[pos].ExecuteHour = currentHour;
				jobs[pos].ExecuteMinute = currentMinute;
			}

			jobs[pos].State = true;
			jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
			jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
			jobs[pos].InMemory = false;
			memoryJobCnt--;
		
			//该作业执行完，要设置当前时间
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//再次设置当前时间
			//如果当前内存中的所有作业都执行完之后，还存在内存外尚未执行的作业X，且X的开始时间在当前时间之后，则需要
			//把这样的作业调入内存，那么要把当前时间设置为X的开始时间，为X调入内存做准备。注意这个X就是目前在外存中，
			//且没有完成、且开始时间在目前时间之后，且在所有外存尚未开始执行的作业中开始时间最早。
			
			if(memoryJobCnt==0 && getFinishedNumber(jobs, jobCnt) < jobCnt)
			{
				for(int i = 0; i < jobCnt; i++)
				{
					if(jobs[i].InMemory == false && jobs[i].State == false)
					{
						if(jobs[i].StartHour > currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute > currentMinute))
						{
							currentHour = jobs[i].StartHour;						
							currentMinute = jobs[i].StartMinute;
						}
						break;
					}
				}
			}	
				
		}
		
		else
		{
			//选中没有完成且不在内存的最先来的作业
			int tmpPos = -1;
			for(int i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;
					break;
				}
			}
				
				
			//A:本次作业执行完时，将要调入的作业尚未开始
			if( ( ( jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour < jobs[tmpPos].StartHour 
				   || ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour
				   && (jobs[pos].ExecuteRemainingTime+currentMinute)%60 <= jobs[pos+1].StartMinute ) ) )
			{
				//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
					//jobs[pos].ExecuteStartTime(jobs[pos].getExecuteHour()+":"+jobs[pos].getExecuteMinute());
				}

				jobs[pos].State = true;
				jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
				jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
				jobs[pos].InMemory = false;
				memoryJobCnt--;
				
				//该作业执行完，要设置当前时间
				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;

					
			}
			else if( ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour > jobs[tmpPos].StartHour 
					|| ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					&& ( jobs[pos].ExecuteRemainingTime + currentMinute)%60 > jobs[pos+1].StartMinute)))
			{
				// B:本次作业执行过程中，将要调入的作业来了
				//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
				}
				int tmpTime = 0;
				if(jobs[tmpPos].StartHour == currentHour)
				{
					tmpTime = jobs[tmpPos].StartMinute - currentMinute;
				}
				else
				{
					tmpTime = (jobs[tmpPos].StartHour - 1 - currentHour)*60 + 60 + jobs[tmpPos].StartMinute - currentMinute;
				}
				jobs[pos].ExecuteRemainingTime = jobs[pos].ExecuteRemainingTime - tmpTime;

				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;	
			}	
		}
	}

	//计算周转时间、带权周转时间、平均周转时间和平均带权周转时间
	//输出
	cout << "作业\t进入时间\t估计运行时间（分钟）\t开始时间\t结束时间\t周转时间（分钟）\t带权周转时间" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//计算周转时间
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//输出平均周转时间和平均带权周转时间
	cout << endl;
	cout << "平均周转时间： " << (averageTurnOverTime/jobCnt) << endl;
	cout << "平均带权周转时间：" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************

void SJF(int numberOfTracks)
{
	int jobCnt = 0;//作业总数记录
	int i;

	cout << "输入作业总数:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "输入作业名称:";
		cin >> jobs[i].Name;

		cout << "输入作业进入时间:(例如: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "输入作业估计运行时间:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //按照时间先后给作业排序

	//到此，数据已经加载完毕，并根据时间的先后顺序进行了排序，下面进入核心算法
	//第一步，每个时间点，调度谁去内存
	//第二步，每个时间点，执行哪个作业

	//当前没有完成的作业分两类，一类是在内存中，一类是不在内存中
	int memoryJobCnt = 0;//内存中作业数目
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//当前没有完成且不在内存的作业数目
		
		
	//当前时间
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;
		
	//存在作业没执行的话，就一直执行
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************调作业到内存************************
		//选几个还没有完成的、不在内存的作业调入内存。需要明确一点：先来的先调入！
		//最多选(numberOfTracks-memoryJobCnt)=times个已经到来的作业调入内存

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//临时变量，累计本次调入内存的数目，最多达到times个
			
		for(int i =0 ;i < jobCnt; i++)
		{
			if(tmpCnt >= times)
			{
				break;
			}//如果调入内存的作业数目大于了本次内存允许调用的数目，终止。若只允许调入1个，那么tmpCnt=1时候终止循环
			
			if((jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) 
						&& jobs[i].InMemory==false && jobs[i].State == false)
			{
				jobs[i].InMemory = true;
				notMemoryJobCnt--;
				memoryJobCnt++;
				tmpCnt++;
			}
		}

		//************************从内存选一个作业（准备执行）************************
		//作业已经调入内存，并且此刻内存中必定有没有执行完的作业。因为系统是串行的，必定选择一个作业执行。
		//选择以当前时间为起点运行时间最短的作业执行
			
		int minimumTime = 1000000;//假定最长作业时间不会超过1000000
		int pos = -1;//最短作业对应的数组下标
		for(i = 0; i < jobCnt ;i++)
		{
			if(jobs[i].InMemory == true && jobs[i].ExecuteRemainingTime < minimumTime)
			{
				minimumTime = jobs[i].ExecuteRemainingTime;
				pos = i;
			}
		}
			
			//************************执行选择的那个作业（开始执行）************************
			//（1）如果当前内存已经满了的话，直接执行完成jobs[pos]即可。
			//（2）如果当前内存未满并且所有未完成的作业都已经调入到了内存，仍然是直接执行完成jobs[pos]即可。
			//（3）如果不是上面两种情况，即内存未满，且存在作业没有调入到内存。这种情况下，要考虑该作业执行过程中，
			//     是否需要调入新作业到内存。由于上面已经完成了作业调入内存的功能，那么这次调入内存的作业也只会有
			//     一个！这一个一定选择此刻尚未完成、未在内存、开始时间最靠前的作业。还需要判断本次作业执行过程中
			//     的时间和将要调入作业的开始时间的关系。
			//     A:本次作业执行完时，将要调入的作业尚未开始。那就需要执行完本次作业。并且把当前时间修改为将要调
			//       入的这个作业的开始时间。
			//     B:本次作业执行过程中，将要调入的作业来了，那就需要把当前时间设置为将要调入的作业的开始时间，并
			//       且设置本次作业的剩余执行时间。
			//     C:本次作业开始执行的时候，将要调入的作业早已经来过了。这种情况直接交给上面的调入内存步骤解决之。
			
			//针对（1）（2）两种情形
		
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//先设置下开始执行的时间
			if(jobs[pos].FirstExecute == true)
			{
				jobs[pos].FirstExecute = false;
				jobs[pos].ExecuteHour = currentHour;
				jobs[pos].ExecuteMinute = currentMinute;
			}

			jobs[pos].State = true;
			jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
			jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
			jobs[pos].InMemory = false;
			memoryJobCnt--;
		
			//该作业执行完，要设置当前时间
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//再次设置当前时间
			//如果当前内存中的所有作业都执行完之后，还存在内存外尚未执行的作业X，且X的开始时间在当前时间之后，则需要
			//把这样的作业调入内存，那么要把当前时间设置为X的开始时间，为X调入内存做准备。注意这个X就是目前在外存中，
			//且没有完成、且开始时间在目前时间之后，且在所有外存尚未开始执行的作业中开始时间最早。
			if(memoryJobCnt==0 && getFinishedNumber(jobs, jobCnt)<jobCnt)
			{
				for(int i = 0; i < jobCnt; i++)
				{
					if(jobs[i].InMemory==false && jobs[i].State==false)
					{
						if(jobs[i].StartHour>currentHour || (jobs[i].StartHour==currentHour && jobs[i].StartMinute>currentMinute))
						{							
							currentHour = jobs[i].StartHour;						
							currentMinute = jobs[i].StartMinute;
						}
						break;
					}
				}
			}	
		}
		else
		{
			//选中没有完成且不在内存的最先来的作业
			int tmpPos = -1;
			for(int i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;			
					break;
				}
			}
				
				
			//A:本次作业执行完时，将要调入的作业尚未开始
			if(
				(  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour < jobs[tmpPos].StartHour
				   || (
					(jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					&&
					(jobs[pos].ExecuteRemainingTime + currentMinute)%60 <= jobs[pos+1].StartMinute
					)
				)
				)
			{		
			//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
				}

				jobs[pos].State = true;
				jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
				jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
				jobs[pos].InMemory = false;
				memoryJobCnt--;

				//该作业执行完，要设置当前时间
				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;
			}
			else if(
					(  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour > jobs[tmpPos].StartHour 
				   	   || (
					  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour
					  && 
					  (jobs[pos].ExecuteRemainingTime + currentMinute)%60 > jobs[pos+1].StartMinute
					)
					)
				)
			{
				// B:本次作业执行过程中，将要调入的作业来了
					
				//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
				}
		
				int tmpTime = 0;
				if(jobs[tmpPos].StartHour == currentHour)
				{
					tmpTime = jobs[tmpPos].StartMinute - currentMinute;
				}
				else
				{
					tmpTime = (jobs[tmpPos].StartHour - 1 - currentHour)*60 + 60 + jobs[tmpPos].StartMinute - currentMinute;
				}
				jobs[pos].ExecuteRemainingTime = jobs[pos].ExecuteRemainingTime-tmpTime;

				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;					
			}	
		}	
	}
	//计算周转时间、带权周转时间、平均周转时间和平均带权周转时间
	//输出
	cout << "作业\t进入时间\t估计运行时间（分钟）\t开始时间\t结束时间\t周转时间（分钟）\t带权周转时间" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//计算周转时间
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//输出平均周转时间和平均带权周转时间
	cout << endl;
	cout << "平均周转时间： " << (averageTurnOverTime/jobCnt) << endl;
	cout << "平均带权周转时间：" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************


void HRRN(int numberOfTracks)
{
	int jobCnt = 0;//作业总数记录
	int i;
		
	cout << "输入作业总数:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "输入作业名称:";
		cin >> jobs[i].Name;

		cout << "输入作业进入时间:(例如: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "输入作业估计运行时间:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //按照时间先后给作业排序


	//到此，数据已经加载完毕，并根据时间的先后顺序进行了排序，下面进入核心算法
	//第一步，每个时间点，调度谁去内存
	//第二步，每个时间点，执行哪个作业

	//当前没有完成的作业分两类，一类是在内存中，一类是不在内存中
	int memoryJobCnt = 0;//内存中作业数目
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//当前没有完成且不在内存的作业数目
		
		
	//当前时间
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;

	//存在作业没执行的话，就一直执行
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************调作业到内存************************
		//选几个还没有完成的、不在内存的作业调入内存。需要明确一点：先来的先调入！
		//最多选(numberOfTracks-memoryJobCnt)=times个已经到来的作业调入内存

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//临时变量，累计本次调入内存的数目，最多达到times个
		
		for(i =0 ;i < jobCnt; i++){
			if(tmpCnt >= times){break;}//如果调入内存的作业数目大于了本次内存允许调用的数目，终止。若只允许调入1个，那么tmpCnt=1时候终止循环
			if((jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) 
					&& jobs[i].InMemory==false && jobs[i].State == false)
			{
				jobs[i].InMemory = true;
				notMemoryJobCnt--;
				memoryJobCnt++;
				tmpCnt++;
			}
		}
			//************************【【算法核心】】从内存选一个作业（准备执行）************************
			//作业已经调入内存，并且此刻内存中必定有没有执行完的作业。因为系统是串行的，必定选择一个作业执行。
			//选择最高响应比的作业执行
			
		double responseRatio = -1.0;//响应比=作业等待时间/作业处理时间
		int pos = -1;//最高响应比作业对应的数组下标
		for(i = 0; i < jobCnt ;i++)
		{
			int waitTime = (currentHour - jobs[i].StartHour - 1)*60 + 60 + currentMinute - jobs[i].StartMinute;
			if(jobs[i].InMemory==true && (double)waitTime/(double)jobs[i].ExecuteRemainingTime > responseRatio)
			{
				responseRatio = (double)waitTime/(double)jobs[i].ExecuteRemainingTime;
				pos = i;
			}
		}
			
			//************************执行选择的那个作业（开始执行）************************
			//（1）如果当前内存已经满了的话，直接执行完成jobs[pos]即可。
			//（2）如果当前内存未满并且所有未完成的作业都已经调入到了内存，仍然是直接执行完成jobs[pos]即可。
			//（3）如果不是上面两种情况，即内存未满，且存在作业没有调入到内存。这种情况下，要考虑该作业执行过程中，
			//     是否需要调入新作业到内存。由于上面已经完成了作业调入内存的功能，那么这次调入内存的作业也只会有
			//     一个！这一个一定选择此刻尚未完成、未在内存、开始时间最靠前的作业。还需要判断本次作业执行过程中
			//     的时间和将要调入作业的开始时间的关系。
			//     A:本次作业执行完时，将要调入的作业尚未开始。那就需要执行完本次作业。并且把当前时间修改为将要调
			//       入的这个作业的开始时间。
			//     B:本次作业执行过程中，将要调入的作业来了，那就需要把当前时间设置为将要调入的作业的开始时间，并
			//       且设置本次作业的剩余执行时间。
			//     C:本次作业开始执行的时候，将要调入的作业早已经来过了。这种情况直接交给上面的调入内存步骤解决之。
			
			//针对（1）（2）两种情形
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//先设置下开始执行的时间
			if(jobs[pos].FirstExecute == true)
			{
				jobs[pos].FirstExecute = false;
				jobs[pos].ExecuteHour = currentHour;
				jobs[pos].ExecuteMinute = currentMinute;
			}

			jobs[pos].State = true;
			jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
			jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
			jobs[pos].InMemory = false;
			memoryJobCnt--;
		
			//该作业执行完，要设置当前时间
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//再次设置当前时间
			//如果当前内存中的所有作业都执行完之后，还存在内存外尚未执行的作业X，且X的开始时间在当前时间之后，则需要
			//把这样的作业调入内存，那么要把当前时间设置为X的开始时间，为X调入内存做准备。注意这个X就是目前在外存中，
			//且没有完成、且开始时间在目前时间之后，且在所有外存尚未开始执行的作业中开始时间最早。
			if(memoryJobCnt==0 && getFinishedNumber(jobs, jobCnt)<jobCnt)
			{
				for(i = 0; i < jobCnt; i++){
					if(jobs[i].InMemory == false && jobs[i].State == false)
					{				
						if(jobs[i].StartHour>currentHour || (jobs[i].StartHour==currentHour && jobs[i].StartMinute>currentMinute))
						{
							currentHour = jobs[i].StartHour;						
							currentMinute = jobs[i].StartMinute;
						}
						break;
					}
				}
			}		
		}
		else
		{
			//选中没有完成且不在内存的最先来的作业
			int tmpPos = -1;
			for(i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;
					break;
				}
			}
				
			//A:本次作业执行完时，将要调入的作业尚未开始
			if(
				(  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour < jobs[tmpPos].StartHour 
				   || (
					(jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					&& 
					(jobs[pos].ExecuteRemainingTime+currentMinute)%60 <= jobs[pos+1].StartMinute
					)
				)
				){
				//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
				}

				jobs[pos].State = true;
				jobs[pos].EndHour = currentHour + (jobs[pos].ExecuteRemainingTime + currentMinute)/60;
				jobs[pos].EndMinute = (jobs[pos].ExecuteRemainingTime + currentMinute) % 60;
				jobs[pos].InMemory = false;
				memoryJobCnt--;
				//该作业执行完，要设置当前时间
				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;
			}
			else if(
					(  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour > jobs[tmpPos].StartHour 
				   	   || (
					  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					  && 
					  (jobs[pos].ExecuteRemainingTime + currentMinute)%60 > jobs[pos+1].StartMinute
					)
					)
				)
			{
				// B:本次作业执行过程中，将要调入的作业来了
				//先设置下开始执行的时间
				if(jobs[pos].FirstExecute == true)
				{
					jobs[pos].FirstExecute = false;
					jobs[pos].ExecuteHour = currentHour;
					jobs[pos].ExecuteMinute = currentMinute;
				}
		
				int tmpTime = 0;
				if(jobs[tmpPos].StartHour == currentHour)
				{
					tmpTime = jobs[tmpPos].StartMinute - currentMinute;
				}
				else
				{
					tmpTime = (jobs[tmpPos].StartHour - 1 - currentHour)*60 + 60 + jobs[tmpPos].StartMinute - currentMinute;
				}

				jobs[pos].ExecuteRemainingTime = jobs[pos].ExecuteRemainingTime-tmpTime;
				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;		
			}
		}	
	}
	//计算周转时间、带权周转时间、平均周转时间和平均带权周转时间
	//输出
	cout << "作业\t进入时间\t估计运行时间（分钟）\t开始时间\t结束时间\t周转时间（分钟）\t带权周转时间" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//计算周转时间
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
	//输出平均周转时间和平均带权周转时间
	cout << endl;
	cout << "平均周转时间： " << (averageTurnOverTime/jobCnt) << endl;
	cout << "平均带权周转时间：" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";	
}	

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
void singleSJF()
{
	int jobCnt = 0;//作业总数记录
	int i;
		
	cout << "输入作业总数:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "输入作业名称:";
		cin >> jobs[i].Name;

		cout << "输入作业进入时间:(例如: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "输入作业估计运行时间:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //按照时间先后给作业排序

	int currentHour = jobs[0].StartHour;//当前时间对应的小时
	int currentMinute = jobs[0].StartMinute;//当前时间对应的分钟		

	//单道批处理系统下，最短作业调度，每次在尚未完成的作业中选时间最短的执行，要注意在当前时间之前已经到达
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		int pos = -1;//选择要执行的作业的下标
		int minimumTime = 1000000;//假定最长时间不超过1000000
		//先选一个当前时间及之前到来的尚未执行的作业中最短时间的作业
		for(i = 0; i < jobCnt; i++)
		{
			if(jobs[i].State == false && jobs[i].ExecuteTime < minimumTime && 
				(jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) )
			{
				minimumTime = jobs[i].ExecuteTime;
				pos = i;
			}
		}
		//执行这个最短作业
			
		jobs[pos].State = true;
		jobs[pos].EndHour = currentHour+(currentMinute+jobs[pos].ExecuteTime)/60;
		jobs[pos].EndMinute = (currentMinute+jobs[pos].ExecuteTime)%60;
		jobs[pos].ExecuteHour = currentHour;
		jobs[pos].ExecuteMinute = currentMinute;

		//更新当前时间
		//注意：如果此作业执行完之后，其他作业都没有开始的，当前时间应该设为尚未开始作业的最早时间
		currentHour = jobs[pos].EndHour;
		currentMinute = jobs[pos].EndMinute;

		//寻找最早开始的作业
		for(i = 0; i < jobCnt; i++)
		{
			if(jobs[i].State == false)
			{
				int tmpHour = jobs[i].StartHour;
				int tmpMinute = jobs[i].StartMinute;
				if(tmpHour>currentHour || (tmpHour==currentHour && tmpMinute>currentMinute))
				{
					currentHour = tmpHour;
					currentMinute = tmpMinute;
				}
				break;
			}
		}		
	}
	//计算周转时间、带权周转时间、平均周转时间和平均带权周转时间
	//输出
	cout << "作业\t进入时间\t估计运行时间（分钟）\t开始时间\t结束时间\t周转时间（分钟）\t带权周转时间" << endl;
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//计算周转时间
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//输出平均周转时间和平均带权周转时间
	cout << endl;
	cout << "平均周转时间： " << (averageTurnOverTime/jobCnt) << endl;
	cout << "平均带权周转时间：" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************

void singleHRRN()
{
	int jobCnt = 0;//作业总数记录
	int i;
		
	cout << "输入作业总数:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "输入作业名称:";
		cin >> jobs[i].Name;

		cout << "输入作业进入时间:(例如: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "输入作业估计运行时间:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //按照时间先后给作业排序


	int currentHour = jobs[0].StartHour;//当前时间对应的小时
	int currentMinute = jobs[0].StartMinute;//当前时间对应的分钟		

	//单道批处理系统下，最高响应比调度，每次在尚未完成的作业中选最高响应比的执行，要注意在当前时间之前已经到达
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		int pos = -1;//选择要执行的作业的下标
		double responseRatio = -1.0;
		//先选一个当前时间及之前到来的尚未执行的作业中最高响应比的作业
		for(i = 0; i < jobCnt; i++)
		{
			//最高响应比简化下----》》》等待时间/处理时间
			int waitTime = (currentHour - jobs[i].StartHour - 1)*60 + 60 + currentMinute - jobs[i].StartMinute;
			if(jobs[i].State==false && (double)waitTime/(double)jobs[i].ExecuteTime>responseRatio && 
				(jobs[i].StartHour<currentHour || (jobs[i].StartHour==currentHour && jobs[i].StartMinute<=currentMinute)) )
			{
				responseRatio = (double)waitTime/(double)jobs[i].ExecuteTime;
				pos = i;
			}
		}
			//执行这个最高响应比作业
			
		jobs[pos].State = true;	
		jobs[pos].EndHour = currentHour+(currentMinute+jobs[pos].ExecuteTime)/60;
		jobs[pos].EndMinute = (currentMinute+jobs[pos].ExecuteTime)%60;
		jobs[pos].ExecuteHour = currentHour;
		jobs[pos].ExecuteMinute = currentMinute;
		
		//更新当前时间
		//注意：如果此作业执行完之后，其他作业都没有开始的，当前时间应该设为尚未开始作业的最早时间
		currentHour = jobs[pos].EndHour;
		currentMinute = jobs[pos].EndMinute;
	
			
		//寻找最早开始的作业
		for(i = 0; i < jobCnt; i++)
		{
			if(jobs[i].State==false)
			{
				int tmpHour = jobs[i].StartHour;
				int tmpMinute = jobs[i].StartMinute;
				if(tmpHour>currentHour || (tmpHour==currentHour && tmpMinute>currentMinute))
				{
					currentHour = tmpHour;
					currentMinute = tmpMinute;
				}
				break;
			}
		}
	}
		
	//计算周转时间、带权周转时间、平均周转时间和平均带权周转时间
	//输出
	cout << "作业\t进入时间\t估计运行时间（分钟）\t开始时间\t结束时间\t周转时间（分钟）\t带权周转时间" << endl;
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//计算周转时间
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//输出平均周转时间和平均带权周转时间
	cout << endl;
	cout << "平均周转时间： " << (averageTurnOverTime/jobCnt) << endl;
	cout << "平均带权周转时间：" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}


int main()
{
	int numberOfTracks = 2;//批处理系统的道数，默认2道
	int option;//作业调度算法种类标志，由用户输入
	
	while(true)
	{
		cout << "**********************Option**********************" << endl;
		cout << "1（多道）>>>>>>>>>>FCFS" << endl;
		cout << "2（多道）>>>>>>>>>>SJF" << endl;
		cout << "3（多道）>>>>>>>>>>HRRN" << endl;
		cout << "4（单道）>>>>>>>>>>FCFS" << endl;
		cout << "5（单道）>>>>>>>>>>SJF" << endl;
		cout << "6（单道）>>>>>>>>>>HRRN" << endl;
		cout << "0        >>>>>>>>>>exit" <<endl;

		
		cin >> option;

		switch(option)
		{
			case 0:
				return 0;
			
			case 1: 
				FCFS(numberOfTracks);
				break;
			
			case 2:
				SJF(numberOfTracks);
				break;
			
			case 3:
				HRRN(numberOfTracks);
				break;
			
			case 4:
				FCFS(1);
				break;

			case 5:
				singleSJF();
				break;
			
			case 6:
				singleHRRN();
				break;

			default:
				cout << "输入错误，请根据菜单提示输入算法编号!";
		}
	}
	return 0;
}
