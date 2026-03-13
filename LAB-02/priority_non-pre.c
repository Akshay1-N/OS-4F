#include<stdio.h>

struct Process{
    int pid,at,bt,ct,tat,wt,p;
};
int main(){
     printf("Name: Akshay.N\n ");
     printf("USN: 1BM24CS030\n");
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int completed[n];
    struct Process P[n];
    printf("enter the process ids:");
    for(int i=0;i<n;i++){
    scanf("%d",&P[i].pid);
    }

    printf("Enter the arrival time:");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].at);
    }
    printf("Enter the burst time:");
     for(int i=0;i<n;i++){
        scanf("%d",&P[i].bt);
    }
    printf("Enter the Priority:");
     for(int i=0;i<n;i++){
        scanf("%d",&P[i].p);
    }
    printf("Lower the number higher the priority\n");
    for(int i=0;i<n;i++){
    completed[i]=0;
    }
    int current_time=0;
    int completed_count=0;
    int Sumtat=0;
    int Sumwt=0;

    while(completed_count<n){
        int Highest_priority=9999;
        int Selected_process=-1;

        for(int i=0;i<n;i++){
            if(P[i].at<=current_time&& completed[i]==0){
                if(P[i].p<Highest_priority){
                    Highest_priority=P[i].p;
                    Selected_process=i;
                }
            }
        }
        if(Selected_process==-1){
            current_time+=1;
        }
        else{
           int start_time=current_time;
           P[Selected_process].ct=start_time+P[Selected_process].bt;
           P[Selected_process].tat=P[Selected_process].ct-P[Selected_process].at;
            P[Selected_process].wt= P[Selected_process].tat- P[Selected_process].bt;
            current_time=P[Selected_process].ct;
            completed[Selected_process]=1;
            completed_count+=1;
            Sumtat+=P[Selected_process].tat;
        Sumwt+=P[Selected_process].wt;

        }
    }
     printf("P\tAT\tBT\tP\tCT\tTT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].bt,P[i].p,P[i].ct,P[i].tat,P[i].wt);
    }
    printf("Average TAT:%.2f\n",(float)Sumtat/n);
    printf("Average wt:%.2f\n",(float)Sumwt/n);


}
