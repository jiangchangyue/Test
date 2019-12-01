#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Job
{
public:
	string Name;//��ҵ����
	
	int ExecuteTime;//��ҵ��������ʱ��
	int ExecuteRemainingTime;//��ҵ��������ʱ���ʣ��ʱ��
	

	int StartHour;//����ʱ���Ӧ��Сʱ
	int StartMinute;//����ʱ���Ӧ�ķ���

	int ExecuteHour;//��ʼִ��ʱ���Ӧ��Сʱ
	int ExecuteMinute;//��ʼִ��ʱ���Ӧ�ķ���

	int EndHour;//����ʱ���Ӧ��Сʱ
	int EndMinute;//����ʱ���Ӧ�ķ���
	

	int TurnOverTime;//��תʱ�䣬�÷��Ӽ�
	double WeightedTurnOverTime;//��Ȩ��תʱ��
	
	bool State;//��Ǹ���ҵ�Ƿ�ִ�����
	bool InMemory;//�����ҵ�Ƿ����ڴ�

	bool FirstExecute;//����Ƿ��ǵ�һ��ִ��
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
//�����Ѿ���ɵ���ҵ��Ŀ
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
	int jobCnt = 0;//��ҵ������¼
	int i;

	cout << "������ҵ����:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "������ҵ����:";
		cin >> jobs[i].Name;

		cout << "������ҵ����ʱ��:(����: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "������ҵ��������ʱ��:";
		cin >> jobs[i].ExecuteTime;
		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //����ʱ���Ⱥ����ҵ����
	
	//���ˣ������Ѿ�������ϣ�������ʱ����Ⱥ�˳����������������������㷨
	//��һ����ÿ��ʱ��㣬����˭ȥ�ڴ�
	//�ڶ�����ÿ��ʱ��㣬ִ���ĸ���ҵ

	//��ǰû����ɵ���ҵ�����࣬һ�������ڴ��У�һ���ǲ����ڴ���
	
	int memoryJobCnt = 0;//�ڴ�����ҵ��Ŀ
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//��ǰû������Ҳ����ڴ����ҵ��Ŀ
		
		
	//��ǰʱ��
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;
		
	//������ҵûִ�еĻ�����һֱִ��
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************����ҵ���ڴ�************************
		//ѡ������û����ɵġ������ڴ����ҵ�����ڴ档��Ҫ��ȷһ�㣺�������ȵ��룡
		//���ѡ(numberOfTracks-memoryJobCnt)=times���Ѿ���������ҵ�����ڴ�

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//��ʱ�������ۼƱ��ε����ڴ����Ŀ�����ﵽtimes��
			
		for(i =0 ;i < jobCnt; i++)
		{
			if(tmpCnt >= times)
				break;//��������ڴ����ҵ��Ŀ�����˱����ڴ�������õ���Ŀ����ֹ����ֻ�������1������ôtmpCnt=1ʱ����ֹѭ��
			
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

		//************************���������㷨���ġ��������ڴ�ѡһ����ҵ��׼��ִ�У�************************
		//��ҵ�Ѿ������ڴ棬���Ҵ˿��ڴ��бض���û��ִ�������ҵ����Ϊϵͳ�Ǵ��еģ��ض�ѡ��һ����ҵִ�С�
		//ѡ����������
		int pos = -1;
		for(i = 0; i < jobCnt ;i++)
		{
			if(jobs[i].InMemory==true)
			{
				pos = i;
				break;
			}
		}
			
		//************************ִ��ѡ����Ǹ���ҵ����ʼִ�У�************************
		//��1�������ǰ�ڴ��Ѿ����˵Ļ���ֱ��ִ�����jobs[pos]���ɡ�
		//��2�������ǰ�ڴ�δ����������δ��ɵ���ҵ���Ѿ����뵽���ڴ棬��Ȼ��ֱ��ִ�����jobs[pos]���ɡ�
		//��3�������������������������ڴ�δ�����Ҵ�����ҵû�е��뵽�ڴ档��������£�Ҫ���Ǹ���ҵִ�й����У�
		//     �Ƿ���Ҫ��������ҵ���ڴ档���������Ѿ��������ҵ�����ڴ�Ĺ��ܣ���ô��ε����ڴ����ҵҲֻ����
		//     һ������һ��һ��ѡ��˿���δ��ɡ�δ���ڴ桢��ʼʱ���ǰ����ҵ������Ҫ�жϱ�����ҵִ�й�����
		//     ��ʱ��ͽ�Ҫ������ҵ�Ŀ�ʼʱ��Ĺ�ϵ��
		//     A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ���Ǿ���Ҫִ���걾����ҵ�����Ұѵ�ǰʱ���޸�Ϊ��Ҫ��
		//       ��������ҵ�Ŀ�ʼʱ�䡣
		//     B:������ҵִ�й����У���Ҫ�������ҵ���ˣ��Ǿ���Ҫ�ѵ�ǰʱ������Ϊ��Ҫ�������ҵ�Ŀ�ʼʱ�䣬��
		//       �����ñ�����ҵ��ʣ��ִ��ʱ�䡣
		//     C:������ҵ��ʼִ�е�ʱ�򣬽�Ҫ�������ҵ���Ѿ������ˡ��������ֱ�ӽ�������ĵ����ڴ沽����֮��
		
		//��ԣ�1����2����������
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//�������¿�ʼִ�е�ʱ��
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
		
			//����ҵִ���꣬Ҫ���õ�ǰʱ��
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//�ٴ����õ�ǰʱ��
			//�����ǰ�ڴ��е�������ҵ��ִ����֮�󣬻������ڴ�����δִ�е���ҵX����X�Ŀ�ʼʱ���ڵ�ǰʱ��֮������Ҫ
			//����������ҵ�����ڴ棬��ôҪ�ѵ�ǰʱ������ΪX�Ŀ�ʼʱ�䣬ΪX�����ڴ���׼����ע�����X����Ŀǰ������У�
			//��û����ɡ��ҿ�ʼʱ����Ŀǰʱ��֮���������������δ��ʼִ�е���ҵ�п�ʼʱ�����硣
			
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
			//ѡ��û������Ҳ����ڴ������������ҵ
			int tmpPos = -1;
			for(int i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;
					break;
				}
			}
				
				
			//A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ
			if( ( ( jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour < jobs[tmpPos].StartHour 
				   || ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour
				   && (jobs[pos].ExecuteRemainingTime+currentMinute)%60 <= jobs[pos+1].StartMinute ) ) )
			{
				//�������¿�ʼִ�е�ʱ��
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
				
				//����ҵִ���꣬Ҫ���õ�ǰʱ��
				currentHour = jobs[tmpPos].StartHour;
				currentMinute = jobs[tmpPos].StartMinute;

					
			}
			else if( ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour > jobs[tmpPos].StartHour 
					|| ( (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					&& ( jobs[pos].ExecuteRemainingTime + currentMinute)%60 > jobs[pos+1].StartMinute)))
			{
				// B:������ҵִ�й����У���Ҫ�������ҵ����
				//�������¿�ʼִ�е�ʱ��
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

	//������תʱ�䡢��Ȩ��תʱ�䡢ƽ����תʱ���ƽ����Ȩ��תʱ��
	//���
	cout << "��ҵ\t����ʱ��\t��������ʱ�䣨���ӣ�\t��ʼʱ��\t����ʱ��\t��תʱ�䣨���ӣ�\t��Ȩ��תʱ��" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//������תʱ��
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//���ƽ����תʱ���ƽ����Ȩ��תʱ��
	cout << endl;
	cout << "ƽ����תʱ�䣺 " << (averageTurnOverTime/jobCnt) << endl;
	cout << "ƽ����Ȩ��תʱ�䣺" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************

void SJF(int numberOfTracks)
{
	int jobCnt = 0;//��ҵ������¼
	int i;

	cout << "������ҵ����:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "������ҵ����:";
		cin >> jobs[i].Name;

		cout << "������ҵ����ʱ��:(����: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "������ҵ��������ʱ��:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //����ʱ���Ⱥ����ҵ����

	//���ˣ������Ѿ�������ϣ�������ʱ����Ⱥ�˳����������������������㷨
	//��һ����ÿ��ʱ��㣬����˭ȥ�ڴ�
	//�ڶ�����ÿ��ʱ��㣬ִ���ĸ���ҵ

	//��ǰû����ɵ���ҵ�����࣬һ�������ڴ��У�һ���ǲ����ڴ���
	int memoryJobCnt = 0;//�ڴ�����ҵ��Ŀ
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//��ǰû������Ҳ����ڴ����ҵ��Ŀ
		
		
	//��ǰʱ��
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;
		
	//������ҵûִ�еĻ�����һֱִ��
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************����ҵ���ڴ�************************
		//ѡ������û����ɵġ������ڴ����ҵ�����ڴ档��Ҫ��ȷһ�㣺�������ȵ��룡
		//���ѡ(numberOfTracks-memoryJobCnt)=times���Ѿ���������ҵ�����ڴ�

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//��ʱ�������ۼƱ��ε����ڴ����Ŀ�����ﵽtimes��
			
		for(int i =0 ;i < jobCnt; i++)
		{
			if(tmpCnt >= times)
			{
				break;
			}//��������ڴ����ҵ��Ŀ�����˱����ڴ�������õ���Ŀ����ֹ����ֻ�������1������ôtmpCnt=1ʱ����ֹѭ��
			
			if((jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) 
						&& jobs[i].InMemory==false && jobs[i].State == false)
			{
				jobs[i].InMemory = true;
				notMemoryJobCnt--;
				memoryJobCnt++;
				tmpCnt++;
			}
		}

		//************************���ڴ�ѡһ����ҵ��׼��ִ�У�************************
		//��ҵ�Ѿ������ڴ棬���Ҵ˿��ڴ��бض���û��ִ�������ҵ����Ϊϵͳ�Ǵ��еģ��ض�ѡ��һ����ҵִ�С�
		//ѡ���Ե�ǰʱ��Ϊ�������ʱ����̵���ҵִ��
			
		int minimumTime = 1000000;//�ٶ����ҵʱ�䲻�ᳬ��1000000
		int pos = -1;//�����ҵ��Ӧ�������±�
		for(i = 0; i < jobCnt ;i++)
		{
			if(jobs[i].InMemory == true && jobs[i].ExecuteRemainingTime < minimumTime)
			{
				minimumTime = jobs[i].ExecuteRemainingTime;
				pos = i;
			}
		}
			
			//************************ִ��ѡ����Ǹ���ҵ����ʼִ�У�************************
			//��1�������ǰ�ڴ��Ѿ����˵Ļ���ֱ��ִ�����jobs[pos]���ɡ�
			//��2�������ǰ�ڴ�δ����������δ��ɵ���ҵ���Ѿ����뵽���ڴ棬��Ȼ��ֱ��ִ�����jobs[pos]���ɡ�
			//��3�������������������������ڴ�δ�����Ҵ�����ҵû�е��뵽�ڴ档��������£�Ҫ���Ǹ���ҵִ�й����У�
			//     �Ƿ���Ҫ��������ҵ���ڴ档���������Ѿ��������ҵ�����ڴ�Ĺ��ܣ���ô��ε����ڴ����ҵҲֻ����
			//     һ������һ��һ��ѡ��˿���δ��ɡ�δ���ڴ桢��ʼʱ���ǰ����ҵ������Ҫ�жϱ�����ҵִ�й�����
			//     ��ʱ��ͽ�Ҫ������ҵ�Ŀ�ʼʱ��Ĺ�ϵ��
			//     A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ���Ǿ���Ҫִ���걾����ҵ�����Ұѵ�ǰʱ���޸�Ϊ��Ҫ��
			//       ��������ҵ�Ŀ�ʼʱ�䡣
			//     B:������ҵִ�й����У���Ҫ�������ҵ���ˣ��Ǿ���Ҫ�ѵ�ǰʱ������Ϊ��Ҫ�������ҵ�Ŀ�ʼʱ�䣬��
			//       �����ñ�����ҵ��ʣ��ִ��ʱ�䡣
			//     C:������ҵ��ʼִ�е�ʱ�򣬽�Ҫ�������ҵ���Ѿ������ˡ��������ֱ�ӽ�������ĵ����ڴ沽����֮��
			
			//��ԣ�1����2����������
		
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//�������¿�ʼִ�е�ʱ��
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
		
			//����ҵִ���꣬Ҫ���õ�ǰʱ��
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//�ٴ����õ�ǰʱ��
			//�����ǰ�ڴ��е�������ҵ��ִ����֮�󣬻������ڴ�����δִ�е���ҵX����X�Ŀ�ʼʱ���ڵ�ǰʱ��֮������Ҫ
			//����������ҵ�����ڴ棬��ôҪ�ѵ�ǰʱ������ΪX�Ŀ�ʼʱ�䣬ΪX�����ڴ���׼����ע�����X����Ŀǰ������У�
			//��û����ɡ��ҿ�ʼʱ����Ŀǰʱ��֮���������������δ��ʼִ�е���ҵ�п�ʼʱ�����硣
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
			//ѡ��û������Ҳ����ڴ������������ҵ
			int tmpPos = -1;
			for(int i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;			
					break;
				}
			}
				
				
			//A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ
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
			//�������¿�ʼִ�е�ʱ��
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

				//����ҵִ���꣬Ҫ���õ�ǰʱ��
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
				// B:������ҵִ�й����У���Ҫ�������ҵ����
					
				//�������¿�ʼִ�е�ʱ��
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
	//������תʱ�䡢��Ȩ��תʱ�䡢ƽ����תʱ���ƽ����Ȩ��תʱ��
	//���
	cout << "��ҵ\t����ʱ��\t��������ʱ�䣨���ӣ�\t��ʼʱ��\t����ʱ��\t��תʱ�䣨���ӣ�\t��Ȩ��תʱ��" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//������תʱ��
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//���ƽ����תʱ���ƽ����Ȩ��תʱ��
	cout << endl;
	cout << "ƽ����תʱ�䣺 " << (averageTurnOverTime/jobCnt) << endl;
	cout << "ƽ����Ȩ��תʱ�䣺" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************


void HRRN(int numberOfTracks)
{
	int jobCnt = 0;//��ҵ������¼
	int i;
		
	cout << "������ҵ����:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "������ҵ����:";
		cin >> jobs[i].Name;

		cout << "������ҵ����ʱ��:(����: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "������ҵ��������ʱ��:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //����ʱ���Ⱥ����ҵ����


	//���ˣ������Ѿ�������ϣ�������ʱ����Ⱥ�˳����������������������㷨
	//��һ����ÿ��ʱ��㣬����˭ȥ�ڴ�
	//�ڶ�����ÿ��ʱ��㣬ִ���ĸ���ҵ

	//��ǰû����ɵ���ҵ�����࣬һ�������ڴ��У�һ���ǲ����ڴ���
	int memoryJobCnt = 0;//�ڴ�����ҵ��Ŀ
	int notMemoryJobCnt = jobCnt - getFinishedNumber(jobs, jobCnt) - memoryJobCnt;//��ǰû������Ҳ����ڴ����ҵ��Ŀ
		
		
	//��ǰʱ��
	int currentHour = jobs[0].StartHour;
	int currentMinute = jobs[0].StartMinute;

	//������ҵûִ�еĻ�����һֱִ��
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		//************************����ҵ���ڴ�************************
		//ѡ������û����ɵġ������ڴ����ҵ�����ڴ档��Ҫ��ȷһ�㣺�������ȵ��룡
		//���ѡ(numberOfTracks-memoryJobCnt)=times���Ѿ���������ҵ�����ڴ�

		int times = numberOfTracks - memoryJobCnt;
		int tmpCnt = 0;//��ʱ�������ۼƱ��ε����ڴ����Ŀ�����ﵽtimes��
		
		for(i =0 ;i < jobCnt; i++){
			if(tmpCnt >= times){break;}//��������ڴ����ҵ��Ŀ�����˱����ڴ�������õ���Ŀ����ֹ����ֻ�������1������ôtmpCnt=1ʱ����ֹѭ��
			if((jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) 
					&& jobs[i].InMemory==false && jobs[i].State == false)
			{
				jobs[i].InMemory = true;
				notMemoryJobCnt--;
				memoryJobCnt++;
				tmpCnt++;
			}
		}
			//************************�����㷨���ġ������ڴ�ѡһ����ҵ��׼��ִ�У�************************
			//��ҵ�Ѿ������ڴ棬���Ҵ˿��ڴ��бض���û��ִ�������ҵ����Ϊϵͳ�Ǵ��еģ��ض�ѡ��һ����ҵִ�С�
			//ѡ�������Ӧ�ȵ���ҵִ��
			
		double responseRatio = -1.0;//��Ӧ��=��ҵ�ȴ�ʱ��/��ҵ����ʱ��
		int pos = -1;//�����Ӧ����ҵ��Ӧ�������±�
		for(i = 0; i < jobCnt ;i++)
		{
			int waitTime = (currentHour - jobs[i].StartHour - 1)*60 + 60 + currentMinute - jobs[i].StartMinute;
			if(jobs[i].InMemory==true && (double)waitTime/(double)jobs[i].ExecuteRemainingTime > responseRatio)
			{
				responseRatio = (double)waitTime/(double)jobs[i].ExecuteRemainingTime;
				pos = i;
			}
		}
			
			//************************ִ��ѡ����Ǹ���ҵ����ʼִ�У�************************
			//��1�������ǰ�ڴ��Ѿ����˵Ļ���ֱ��ִ�����jobs[pos]���ɡ�
			//��2�������ǰ�ڴ�δ����������δ��ɵ���ҵ���Ѿ����뵽���ڴ棬��Ȼ��ֱ��ִ�����jobs[pos]���ɡ�
			//��3�������������������������ڴ�δ�����Ҵ�����ҵû�е��뵽�ڴ档��������£�Ҫ���Ǹ���ҵִ�й����У�
			//     �Ƿ���Ҫ��������ҵ���ڴ档���������Ѿ��������ҵ�����ڴ�Ĺ��ܣ���ô��ε����ڴ����ҵҲֻ����
			//     һ������һ��һ��ѡ��˿���δ��ɡ�δ���ڴ桢��ʼʱ���ǰ����ҵ������Ҫ�жϱ�����ҵִ�й�����
			//     ��ʱ��ͽ�Ҫ������ҵ�Ŀ�ʼʱ��Ĺ�ϵ��
			//     A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ���Ǿ���Ҫִ���걾����ҵ�����Ұѵ�ǰʱ���޸�Ϊ��Ҫ��
			//       ��������ҵ�Ŀ�ʼʱ�䡣
			//     B:������ҵִ�й����У���Ҫ�������ҵ���ˣ��Ǿ���Ҫ�ѵ�ǰʱ������Ϊ��Ҫ�������ҵ�Ŀ�ʼʱ�䣬��
			//       �����ñ�����ҵ��ʣ��ִ��ʱ�䡣
			//     C:������ҵ��ʼִ�е�ʱ�򣬽�Ҫ�������ҵ���Ѿ������ˡ��������ֱ�ӽ�������ĵ����ڴ沽����֮��
			
			//��ԣ�1����2����������
		if(memoryJobCnt == numberOfTracks || memoryJobCnt == jobCnt - getFinishedNumber(jobs, jobCnt))
		{
			//�������¿�ʼִ�е�ʱ��
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
		
			//����ҵִ���꣬Ҫ���õ�ǰʱ��
			currentHour = jobs[pos].EndHour;
			currentMinute = jobs[pos].EndMinute;

			//�ٴ����õ�ǰʱ��
			//�����ǰ�ڴ��е�������ҵ��ִ����֮�󣬻������ڴ�����δִ�е���ҵX����X�Ŀ�ʼʱ���ڵ�ǰʱ��֮������Ҫ
			//����������ҵ�����ڴ棬��ôҪ�ѵ�ǰʱ������ΪX�Ŀ�ʼʱ�䣬ΪX�����ڴ���׼����ע�����X����Ŀǰ������У�
			//��û����ɡ��ҿ�ʼʱ����Ŀǰʱ��֮���������������δ��ʼִ�е���ҵ�п�ʼʱ�����硣
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
			//ѡ��û������Ҳ����ڴ������������ҵ
			int tmpPos = -1;
			for(i = 0; i < jobCnt; i++)
			{
				if(jobs[i].State == false && jobs[i].InMemory == false)
				{
					tmpPos = i;
					break;
				}
			}
				
			//A:������ҵִ����ʱ����Ҫ�������ҵ��δ��ʼ
			if(
				(  (jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour < jobs[tmpPos].StartHour 
				   || (
					(jobs[pos].ExecuteRemainingTime + currentMinute)/60 + currentHour == jobs[pos+1].StartHour 
					&& 
					(jobs[pos].ExecuteRemainingTime+currentMinute)%60 <= jobs[pos+1].StartMinute
					)
				)
				){
				//�������¿�ʼִ�е�ʱ��
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
				//����ҵִ���꣬Ҫ���õ�ǰʱ��
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
				// B:������ҵִ�й����У���Ҫ�������ҵ����
				//�������¿�ʼִ�е�ʱ��
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
	//������תʱ�䡢��Ȩ��תʱ�䡢ƽ����תʱ���ƽ����Ȩ��תʱ��
	//���
	cout << "��ҵ\t����ʱ��\t��������ʱ�䣨���ӣ�\t��ʼʱ��\t����ʱ��\t��תʱ�䣨���ӣ�\t��Ȩ��תʱ��" << endl;
		
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//������תʱ��
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
	//���ƽ����תʱ���ƽ����Ȩ��תʱ��
	cout << endl;
	cout << "ƽ����תʱ�䣺 " << (averageTurnOverTime/jobCnt) << endl;
	cout << "ƽ����Ȩ��תʱ�䣺" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";	
}	

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
void singleSJF()
{
	int jobCnt = 0;//��ҵ������¼
	int i;
		
	cout << "������ҵ����:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "������ҵ����:";
		cin >> jobs[i].Name;

		cout << "������ҵ����ʱ��:(����: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "������ҵ��������ʱ��:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //����ʱ���Ⱥ����ҵ����

	int currentHour = jobs[0].StartHour;//��ǰʱ���Ӧ��Сʱ
	int currentMinute = jobs[0].StartMinute;//��ǰʱ���Ӧ�ķ���		

	//����������ϵͳ�£������ҵ���ȣ�ÿ������δ��ɵ���ҵ��ѡʱ����̵�ִ�У�Ҫע���ڵ�ǰʱ��֮ǰ�Ѿ�����
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		int pos = -1;//ѡ��Ҫִ�е���ҵ���±�
		int minimumTime = 1000000;//�ٶ��ʱ�䲻����1000000
		//��ѡһ����ǰʱ�估֮ǰ��������δִ�е���ҵ�����ʱ�����ҵ
		for(i = 0; i < jobCnt; i++)
		{
			if(jobs[i].State == false && jobs[i].ExecuteTime < minimumTime && 
				(jobs[i].StartHour < currentHour || (jobs[i].StartHour == currentHour && jobs[i].StartMinute <= currentMinute)) )
			{
				minimumTime = jobs[i].ExecuteTime;
				pos = i;
			}
		}
		//ִ����������ҵ
			
		jobs[pos].State = true;
		jobs[pos].EndHour = currentHour+(currentMinute+jobs[pos].ExecuteTime)/60;
		jobs[pos].EndMinute = (currentMinute+jobs[pos].ExecuteTime)%60;
		jobs[pos].ExecuteHour = currentHour;
		jobs[pos].ExecuteMinute = currentMinute;

		//���µ�ǰʱ��
		//ע�⣺�������ҵִ����֮��������ҵ��û�п�ʼ�ģ���ǰʱ��Ӧ����Ϊ��δ��ʼ��ҵ������ʱ��
		currentHour = jobs[pos].EndHour;
		currentMinute = jobs[pos].EndMinute;

		//Ѱ�����翪ʼ����ҵ
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
	//������תʱ�䡢��Ȩ��תʱ�䡢ƽ����תʱ���ƽ����Ȩ��תʱ��
	//���
	cout << "��ҵ\t����ʱ��\t��������ʱ�䣨���ӣ�\t��ʼʱ��\t����ʱ��\t��תʱ�䣨���ӣ�\t��Ȩ��תʱ��" << endl;
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//������תʱ��
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//���ƽ����תʱ���ƽ����Ȩ��תʱ��
	cout << endl;
	cout << "ƽ����תʱ�䣺 " << (averageTurnOverTime/jobCnt) << endl;
	cout << "ƽ����Ȩ��תʱ�䣺" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}

//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************
//*********************************************************************************************************************************************************

void singleHRRN()
{
	int jobCnt = 0;//��ҵ������¼
	int i;
		
	cout << "������ҵ����:";
	cin >> jobCnt;
	Job *jobs = new Job[jobCnt];
	
	for(i = 0; i < jobCnt; i++)
	{
		cout << "������ҵ����:";
		cin >> jobs[i].Name;

		cout << "������ҵ����ʱ��:(����: 10 00)";
		cin >> jobs[i].StartHour >> jobs[i].StartMinute;

		cout << "������ҵ��������ʱ��:";
		cin >> jobs[i].ExecuteTime;

		jobs[i].ExecuteRemainingTime = jobs[i].ExecuteTime;
		jobs[i].State = false;
		jobs[i].InMemory = false;
		jobs[i].FirstExecute = true;
	}
	
	TimeSort(jobs, jobCnt);  //����ʱ���Ⱥ����ҵ����


	int currentHour = jobs[0].StartHour;//��ǰʱ���Ӧ��Сʱ
	int currentMinute = jobs[0].StartMinute;//��ǰʱ���Ӧ�ķ���		

	//����������ϵͳ�£������Ӧ�ȵ��ȣ�ÿ������δ��ɵ���ҵ��ѡ�����Ӧ�ȵ�ִ�У�Ҫע���ڵ�ǰʱ��֮ǰ�Ѿ�����
	while(getFinishedNumber(jobs, jobCnt) < jobCnt)
	{
		int pos = -1;//ѡ��Ҫִ�е���ҵ���±�
		double responseRatio = -1.0;
		//��ѡһ����ǰʱ�估֮ǰ��������δִ�е���ҵ�������Ӧ�ȵ���ҵ
		for(i = 0; i < jobCnt; i++)
		{
			//�����Ӧ�ȼ���----�������ȴ�ʱ��/����ʱ��
			int waitTime = (currentHour - jobs[i].StartHour - 1)*60 + 60 + currentMinute - jobs[i].StartMinute;
			if(jobs[i].State==false && (double)waitTime/(double)jobs[i].ExecuteTime>responseRatio && 
				(jobs[i].StartHour<currentHour || (jobs[i].StartHour==currentHour && jobs[i].StartMinute<=currentMinute)) )
			{
				responseRatio = (double)waitTime/(double)jobs[i].ExecuteTime;
				pos = i;
			}
		}
			//ִ����������Ӧ����ҵ
			
		jobs[pos].State = true;	
		jobs[pos].EndHour = currentHour+(currentMinute+jobs[pos].ExecuteTime)/60;
		jobs[pos].EndMinute = (currentMinute+jobs[pos].ExecuteTime)%60;
		jobs[pos].ExecuteHour = currentHour;
		jobs[pos].ExecuteMinute = currentMinute;
		
		//���µ�ǰʱ��
		//ע�⣺�������ҵִ����֮��������ҵ��û�п�ʼ�ģ���ǰʱ��Ӧ����Ϊ��δ��ʼ��ҵ������ʱ��
		currentHour = jobs[pos].EndHour;
		currentMinute = jobs[pos].EndMinute;
	
			
		//Ѱ�����翪ʼ����ҵ
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
		
	//������תʱ�䡢��Ȩ��תʱ�䡢ƽ����תʱ���ƽ����Ȩ��תʱ��
	//���
	cout << "��ҵ\t����ʱ��\t��������ʱ�䣨���ӣ�\t��ʼʱ��\t����ʱ��\t��תʱ�䣨���ӣ�\t��Ȩ��תʱ��" << endl;
	double averageTurnOverTime = 0.0;
	double weightedAverageTurnOverTime = 0.0;
	for(i = 0; i < jobCnt; i++)
	{
		//������תʱ��
		int tmpTime = (jobs[i].EndHour - jobs[i].StartHour -1)*60 + 60 + jobs[i].EndMinute - jobs[i].StartMinute;
		
		jobs[i].TurnOverTime = tmpTime;
		jobs[i].WeightedTurnOverTime = (jobs[i].TurnOverTime+0.0)/(0.0+jobs[i].ExecuteTime);
		
		averageTurnOverTime += (double)jobs[i].TurnOverTime;

		weightedAverageTurnOverTime += (double)jobs[i].WeightedTurnOverTime;

		cout << jobs[i].Name << "\t" << jobs[i].StartHour << ":" << jobs[i].StartMinute << "\t\t\t" << jobs[i].ExecuteTime << "\t\t" << jobs[i].ExecuteHour << ":" << jobs[i].ExecuteMinute << "\t\t" << jobs[i].EndHour << ":" << jobs[i].EndMinute << "\t\t" << jobs[i].TurnOverTime << "\t\t\t" << jobs[i].WeightedTurnOverTime << endl;
	}
		
	//���ƽ����תʱ���ƽ����Ȩ��תʱ��
	cout << endl;
	cout << "ƽ����תʱ�䣺 " << (averageTurnOverTime/jobCnt) << endl;
	cout << "ƽ����Ȩ��תʱ�䣺" << (weightedAverageTurnOverTime/jobCnt) << endl;
	cout << "====================================================================================================================";
}


int main()
{
	int numberOfTracks = 2;//������ϵͳ�ĵ�����Ĭ��2��
	int option;//��ҵ�����㷨�����־�����û�����
	
	while(true)
	{
		cout << "**********************Option**********************" << endl;
		cout << "1�������>>>>>>>>>>FCFS" << endl;
		cout << "2�������>>>>>>>>>>SJF" << endl;
		cout << "3�������>>>>>>>>>>HRRN" << endl;
		cout << "4��������>>>>>>>>>>FCFS" << endl;
		cout << "5��������>>>>>>>>>>SJF" << endl;
		cout << "6��������>>>>>>>>>>HRRN" << endl;
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
				cout << "�����������ݲ˵���ʾ�����㷨���!";
		}
	}
	return 0;
}
