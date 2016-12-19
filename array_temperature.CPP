/* Programmer's name: Eshaan Bansal
   Date: 13/12/2016
   Title: Input temp by time of the day for a week and display related info
        */
    
#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();
    char day[7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    char time[3][10]={"Morning","Noon","Evening"};
    int i,j,temp[3][7];
    for (i=0; i<3; i++) {
        cout<<endl;
        for (j=0; j<7; j++) {
		cout<<"\tEnter "<<time[i]<<" temp(in C) for "<<day[j]<<": ";
                cin>>temp[i][j];
        }
    }
    int max[3], min[3], sum[3]={0,0,0}, sum2=0;
    float time_avg[3], week_avg=0;
    for (i=0; i<3; i++) {
            max[i]=temp[i][0];
            for (j=0; j<7; j++) {
                sum[i]+=temp[i][j];
		if (temp[i][j]>max[i])
                    max[i]=temp[i][j];
                else if (temp[i][j]<min[i])
		    min[i]=temp[i][j];
            }
            time_avg[i]=sum[i]/7;
            sum2+=time_avg[i];
    }
    week_avg=sum2/3;
    cout<<"\n\t******************************************************************\n\n";
    for (i=0; i<3; i++) {
        cout<<"\t"<<time[i]<<endl;
        cout<<"\t\tMaximum temp: "<<max[i]<<endl;
        cout<<"\t\tMinimum temp: "<<min[i]<<endl;
        cout<<"\t\tAverage temp: "<<time_avg[i]<<"\n\n";
    }
    cout<<"\t\tAverage temp for the week: "<<week_avg<<endl;
    getch();    
}