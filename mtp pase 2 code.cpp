#include<iostream>
using namespace std;
int main()
{
	long double mat[200][7];
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//failure rate
	long double avg[7];
	avg[0]=4.154*1e-4;
	avg[1]=3.952*1e-4;
	avg[2]=1.592*1e-4;
	avg[3]=4.783*1e-4;
	avg[4]=2.612*1e-4;
	avg[5]=6.956*1e-4;
	avg[6]=6.264*1e-4;
	
	long double min[7]={0.00025647L,0.00033333L,0.00012121L,0.00039373L,
	0.00020224L,0.00067686L,0.00053525L};
	long double max[7];
	
	for(int i=0;i<7;i++) max[i]=2*avg[i]-min[i];
	
	//={0.00051212L,0.00049487L,0.00020121L,0.00054535L,
	//0.00029272L,0.00083821L,0.00075332L};
	
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//repair rate
	long double avg2[7];
	avg2[0]=3.17460000 ;//
	avg2[1]=2.64210000;//
	avg2[2]=3.33230000;//
	avg2[3]=4.76190000;//
	avg2[4]=4.8990000;//
	avg2[5]=4.68310000;//
	avg2[6]=6.23100000;//
	
	long double min2[7]={2.77512622L,2.15336207L,2.74273867L,4.24826476L,
	4.23617242L,4.03200468L,5.24442022L};
	long double max2[7];
	
	for(int i=0;i<7;i++) max2[i]=2*avg2[i]-min2[i];
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 /* initialize random seed: */
  
  
	//write to file
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	long double r1,r2,r3,r4;
		srand (time(NULL));
		
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<7;j++)
		{
		/*	for(int k=0;k<3;k++)
			{
				r1=min[i]+(rand()/RAND_MAX)*(max[i]-min[i]);
				r2=min[i]+(rand()/RAND_MAX)*(max[i]-min[i]);
				r3=min[i]+(rand()/RAND_MAX)*(max[i]-min[i]);
			}
			*/
			
			r1=min[j]+((long double)rand()/RAND_MAX)*(max[j]-min[j]);
			r2=2*avg[j]-r1;
			
			mat[i*4][j]=r1;
			mat[i*4+1][j]=r2;
			//mat[i*4+2][j]=r3;
			//mat[i*4+3][j]=r4;
			r3=min2[j]+((long double)rand()/RAND_MAX)*(max2[j]-min2[j]);
			r4=2*avg2[j]-r3;
			//cout<<r3<<" "<<r4<<endl;system("pause");
			mat[i*4+2][j]=r3;
			mat[i*4+3][j]=r4;
			
		}
	}
	
	for(int i=0;i<200;i++)
	{
	if(i%4<2)
	{
	
			for(int j=0;j<7;j++)
		{
			//printf("%.8f ",(float)mat[i][j]);
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	for(int i=0;i<200;i++)
	{
	if(i%4>1)
	{
	
			for(int j=0;j<7;j++)
		{
			//printf("%.8f ",(float)mat[i][j]);
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	fclose(stdout);
} 