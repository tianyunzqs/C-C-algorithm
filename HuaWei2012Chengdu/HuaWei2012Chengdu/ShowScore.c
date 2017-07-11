#include<stdio.h>

int cal_score(int score[], int judge_type[], int n)
{
	int expert_sum=0, common_sum=0;
	int expert_num=0, common_num=0;
	int expert_ave, common_ave;
	int i;
	for(i=0; i<n; i++)
	{
		switch(judge_type[i])
		{
			case 1:
			{
				expert_num++;
				expert_sum += score[i];
				break;
			}
			case 2:
			{
				common_num++;
				common_sum += score[i];
				break;
			}
			default : 
			{
				printf("出现非专家评委或大众评委！");
				return;
			}
		}
	}
	if(common_num==0)
	{
		expert_ave = (int)(expert_sum/expert_num);
		return expert_ave;
	}
	else
	{
		expert_ave = (int)(expert_sum/expert_num);
		common_ave = (int)(common_sum/common_num);
		return (int)(0.6*expert_ave + 0.4*common_ave);
	}
}

void main()
{
	int score[]={12,13,14,13};
	int judge_type[]={1,1,2,2};
	int n=3;
	printf("%d", cal_score(score, judge_type, n));
}