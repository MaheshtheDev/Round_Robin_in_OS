#include <bits/stdc++.h>
using namespace std;
struct Process_Data
{
	int Num,Pid,A_time,B_time,Priority,F_time,R_time,W_time,S_time,Res_time;
};
struct Process_Data c;
typedef struct Process_Data sd ;
bool idsort(sd& x ,sd& y)
{
	return x.Pid < y.Pid;
}
bool arrivalsort(sd& x ,sd& y)
{
	if(x.A_time < y.A_time)
		return true;
	else if(x.A_time > y.A_time)
		return false;
	if(x.Priority < y.Priority)
		return true;
	else if(x.Priority > y.Priority)
		return false;
	if(x.Pid < y.Pid)
		return true;
	return false;
}
bool Numsort(sd& x ,sd& y)
{
	return x.Num < y.Num;
}
struct comPare
{
	bool operator()(sd& x ,sd& y)
	{
		if( x.Priority > y.Priority )
			return true;
		else if( x.Priority < y.Priority )
			return false;
		if( x.Pid > y.Pid )
			return true;
		return false;

	}

};
void my_check(vector<sd> mv)
{
	for(int i= 0; i < mv.size() ;i++)
	{
		cout<<"Pid :"<<mv[i].Pid<<" _time : "<<mv[i].A_time<<" B_time : "<<mv[i].B_time<<" Priority : "<<mv[i].Priority<<endl;
	}
}
int main()
{
	vector<sd> ip;
	sd temp;
	int pq_process=0,rq_process = 0,i=0,A,B,Pid,Priority,n,clock,tet = 0;
	cout<<" Enter No.of Processes:";
	cin>>n;
	if(n<=0)
    {
        system("CLS");
        cout<<"Invalid Input";
        exit(0);
    }
	for( i= 0; i< n; i++ )
	{
	    cout<<" "<<i+1<<" Process \n";
	    cout<<"Process Id :";
		cin>>Pid;
		cout<<"Arrival Time:";
		cin>>A;
		cout<<"Burst Time:";
		cin>>B;
		cout<<"Priority :";
		cin>>Priority;
		if(Pid<0||A<0||B<0||Priority<0)
        {
            system("CLS");
            cout<<"Invalid Input";
            exit(0);
        }
		temp.Num = i+1;
		temp.A_time = A;
		temp.B_time = B;
		temp.R_time = B;
		temp.Pid = Pid;
		temp.Priority = Priority;
		ip.push_back(temp);
	}
	sort( ip.begin(), ip.end(), arrivalsort );
    tet = tet + ip[0].A_time;
    for( i= 0;i< n;i++ )
    {
    	if( tet >= ip[i].A_time )
    	{
    		tet = tet +ip[i].B_time;
    	}
    	else
    	{
    		int diff = (ip[i].A_time - tet);
    		tet = tet + diff + B;

    	}
    }
	int Ghant[tet]={0};
	for( i= 0; i< tet; i++ )
	{
		Ghant[i]=-1;
	}
	priority_queue < sd ,vector<Process_Data> ,comPare> pq;
	queue< sd > rq;
	int cpu_state = 0;
	int quantum = 4 ;
	c.Pid = -2;
	c.Priority = 100000;
	for ( clock = 0; clock< tet; clock++ )
	{
		for( int j = 0; j< n ; j++ )
		{
			if(clock == ip[j].A_time)
			{
				pq.push(ip[j]);
			}
		}
		if(cpu_state == 0)
		{
			if(!pq.empty())
			{
				c = pq.top();
				cpu_state = 1;
				pq_process = 1;
				pq.pop();
				quantum = 4;
			}
			else if(!rq.empty())
			{
				c = rq.front();
				cpu_state = 1;
				rq_process = 1;
				rq.pop();
				quantum = 4;
			}
		}
		else if(cpu_state == 1)
		{
			if(pq_process == 1 && (!pq.empty()))
			{
				if(pq.top().Priority < c.Priority )
				{
					rq.push(c);
					c = pq.top();
					pq.pop();
					quantum = 4;
				}
			}
			else if(rq_process == 1 && (!pq.empty()))
			{
				rq.push(c);
				c = pq.top();
				pq.pop();
				rq_process = 0;
				pq_process = 1;
				quantum = 4 ;
			}
		}
		if(c.Pid != -2)
		{
			c.R_time--;
			quantum--;
			Ghant[clock] = c.Pid;
			if(c.R_time == 0)
			{
				cpu_state = 0 ;
				quantum = 4 ;
				c.Pid = -2;
				c.Priority = 100000;
				rq_process = 0;
				pq_process = 0;
			}
			else if(quantum == 0 )
			{
				rq.push(c);
				c.Pid = -2;
				c.Priority = 100000;
				rq_process = 0;
				pq_process = 0;
				cpu_state=0;
			}
		}
	}
	sort( ip.begin(), ip.end(), idsort );
	for(int i=0;i<n;i++)
	{
		for(int k=tet;k>=0;k--)
		{
			if(Ghant[k]==i+1)
			{
				ip[i].F_time=k+1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<tet;k++)
		{

			if(Ghant[k]==i+1)
			{
				ip[i].S_time=k;
				break;
			}
		}
	}
	sort( ip.begin(), ip.end(), Numsort );
	for(int i=0;i<n;i++)
	{
		ip[i].Res_time=ip[i].S_time-ip[i].A_time;
		ip[i].W_time=(ip[i].F_time-ip[i].A_time)-ip[i].B_time;

	}
	cout<<"Process Id | Response Time | Completion Time | Waiting Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<ip[i].Pid<<"                 "<<ip[i].Res_time<<"               "<<ip[i].F_time<<"           "<<ip[i].W_time<<endl;

	}
	return 0;
}
