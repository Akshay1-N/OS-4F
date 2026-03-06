#include<stdio.h>

struct Process{
    int id,at,bt,ct,tat,wt;
};
int main(){
    printf("Name: Akshay.N\n ");
    printf("USN: 1BM24CS030\n");
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct Process P[n];
    printf("enter the process ids:");
    for(int i=0;i<n;i++){
    scanf("%d",&P[i].id);
    }

    printf("Enter the arrival time:");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].at);
    }
    printf("Enter the burst time:");
     for(int i=0;i<n;i++){
        scanf("%d",&P[i].bt);
    }
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(P[i].at> P[j].at){
                struct Process temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }
    int Sumtat=0;
    int Sumwt=0;
     int current_time=0;
    for(int i=0;i<n;i++){
        if(current_time<P[i].at){
            current_time=P[i].at;
        }
        P[i].ct=current_time+P[i].bt;
        P[i].tat=P[i].ct-P[i].at;
        P[i].wt=P[i].tat-P[i].bt;
        current_time=P[i].ct;
        Sumtat+=P[i].tat;
        Sumwt+=P[i].wt;
    }
    printf("Process\tArrivaltime\tBursttime\tCompletiontime\tTurnaroundtime\tWaitingtime\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i].id,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt);
    }
    printf("Average TAT:%.2f\n",(float)Sumtat/n);
    printf("Average wt:%.2f\n",(float)Sumwt/n);

}
