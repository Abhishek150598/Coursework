#include <bits/stdc++.h>

using namespace std;

struct job
{
	int job_id;
	int priority;
	int arrival_time;
	vector <int> cpu_burst;
	vector <int> io_burst;

	void show_job()
	{
		cout << "Job ID: " << job_id << endl;
		cout << "Priority: " << priority << endl;
		cout << "Arrival time: " << arrival_time << endl;
	}

	bool operator<(const job &j) const
	{
		return arrival_time < j.arrival_time;
	}
};

void fcfs(const vector <job> joblist)
{
	priority_queue <job> ready_queue;
	for(int i = 0; i < joblist.size(); i++)
	{
		ready_queue.push(joblist[i]);
	}

	int t = 0;
	int t2 = 0;
	int j = 0;
	int flag = 0;
	int current = -1;
	job current_job;
	while(1)
	{
		if(current == -1 && !ready_queue.empty())
		{
			current_job = ready_queue.top();
			ready_queue.pop();
		}
		cout << "t = " << t << "Current job = " << current_job.job_id;
		if(t2 < current_job.cpu_burst[j] && flag == 0)
		{
			t2++;
		}
		else if(t2 == current_job.cpu_burst[j])
		{
			t2 = 0;
			flag = 1;
		}
		if(t2 < current_job.io_burst[j] && flag == 1)
		{
			t2++;
		}
		else if(t2 == current_job.io_burst[j])
		{
			t2 = 0;
			flag = 0;
			j++;
		}
		t++;
	}
}
int main()
{
	vector <job> joblist;
	string filename;
	cout << "Enter filename" << endl;
	cin >> filename;
	ifstream f;
	f.open(filename);
	while(!f.eof())
	{
		job j;
		f >> j.job_id;
		f >> j.priority;
		f >> j.arrival_time;

		while(1)
		{
			int b;
			f >> b;
			if(b == -1)
			{
				joblist.push_back(j);
				break;
			}
			else
			{
				j.cpu_burst.push_back(b);
			}
			f >> b;
			if(b == -1)
			{
				joblist.push_back(j);
				break;
			}
			else
			{
				j.io_burst.push_back(b);
			}
		}
	}

	for(int i = 0; i < joblist.size(); i++)
	{
		joblist[i].show_job();
	}
	// First come first serve
	//fcfs(joblist);
	
}

