#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int total[2],max_overs,max_balls,toss,j=1,this_is,wicket=0,i,rand_no,player_runs[100][100],four[100][100],six[100][100],str=1,flag,nstr=2,extra[4],player_balls[100][100],inning,w[12],bowler_wickets[100][100],bowler_overs[100][100],bowler_runs[100][100];
char ch;
char *team[12],*team_players[100][100],*bowler[100][100];
int over=0,teamp1,teamp2,current_bowler=0;
time_t t;
int var=73;
int maxbat[3],maxbowl[3],point[100][100];
int player_length,balls_length,runs_length,four_length,six_length,strrate_length,other;

void func_banner()
{
	printf("      ***************************************************************************************************\n");
	printf("      *    *********  *********     *********  *********  *    *  *********  *********  *  *********    *\n");
	printf("      *    *          *        *        *      *          *   *   *              *      *  *            *\n");
	printf("      *    *          *        *        *      *          *  *    *              *      *  *            *\n");
	printf("      *    *          *       *         *      *          * *     *              *      *  *            *\n");
	printf("      *    *          ********          *      *          **      *******        *      *  *********    *\n");
	printf("      *    *          *       *         *      *          * *     *              *      *          *    *\n"); 
	printf("      *    *          *        *        *      *          *  *    *              *      *          *    *\n");
	printf("      *    *          *         *       *      *          *   *   *              *      *          *    *\n");	
	printf("      *    *********  *          *  *********  *********  *    *  *********      *      *  *********    *\n");
	printf("      ***************************************************************************************************\n");	
}

int func(int l)              //calculate the length of int
{
	int temp=0;	
	while(l)
	{
		temp++;
		l/=10;
	}
	return temp;
}

void func_length(int k)
{

	player_length=strlen(team_players[inning][k]);
	runs_length=0;//func(player_runs[inning][k]);
	balls_length=0;//func(player_balls[inning][k]);	
	four_length=0;//func(four[inning][k]);
	six_length=0;//func(six[inning][k]);
	strrate_length=0;//func(four[inning][k]);
}

void func_final_scoreboard()
{
	int k,temp,temp1;
	int thirteen=13,sixteen=16,eleven=11,saventeen=17,thirtytwo=32;
	double temp2;
	temp1=wicket;
	if (inning==1)
		temp=teamp1;
	else temp=teamp2;
	if(wicket==10)
		temp1--;
		printf("      			     *************** %s ***************\n\n",team[temp]);
		printf("Batsman %*cuns %*calls %*cour %*cix %*ctr Rate\n",thirtytwo+10,'R',sixteen,'B',sixteen,'F',sixteen+1,'S',sixteen-3,'S');
		for(k=1;k<=temp1+2;k++)
		{
			temp2=player_balls[inning][k];
			func_length(k);
			if(w[k]==1)	
			printf("%s %*cold %*d %*d %*d %*d %*.2f\n",team_players[inning][k],30-player_length,'B',sixteen,player_runs[inning][k],20-runs_length,player_balls[inning][k],20-balls_length,four[inning][k],20-four_length,six[inning][k],20-six_length,player_runs[inning][k]/temp2*100.0); 
			else if(w[k]==2)
			printf("%s %*cun Out %*d %*d %*d %*d %*.2f\n",team_players[inning][k],30-player_length,'R',thirteen,player_runs[inning][k],20-runs_length,player_balls[inning][k],20-balls_length,four[inning][k],20-four_length,six[inning][k],20-six_length,player_runs[inning][k]/temp2*100.0);
			else if(w[k]==3)
		printf("%s %*cbw %*d %*d %*d %*d %*.2f\n",team_players[inning][k],30-player_length,'l',saventeen,player_runs[inning][k],20-runs_length,player_balls[inning][k],20-balls_length,four[inning][k],20-four_length,six[inning][k],20-six_length,player_runs[inning][k]/temp2*100.0); 
			else if(w[k]==4)
			printf("%s %*catch Out %*d %*d %*d %*d %*.2f\n",team_players[inning][k],30-player_length,'C',eleven,player_runs[inning][k],20-runs_length,player_balls[inning][k],20-balls_length,four[inning][k],20-four_length,six[inning][k],20-six_length,player_runs[inning][k]/temp2*100.0);
			else
			printf("%s %*cot Out %*d %*d %*d %*d %*.2f\n",team_players[inning][k],30-player_length,'N',thirteen,player_runs[inning][k],20-runs_length,player_balls[inning][k],20-balls_length,four[inning][k],20-four_length,six[inning][k],20-six_length,player_runs[inning][k]/temp2*100.0);
		}
	
	
}

void func_Toss()
{
	
	printf("*** Toss *** \nHead or Tail\n");
	printf("Ready .....\n");	
	printf("press Enter key...");
	scanf("%c",&ch);
	srand((unsigned) time(&t));
	toss=rand()%2;
	if(toss==0)
		printf("Head\n");
	else printf("Tail\n");
	printf("press enter key...");
	scanf("%c",&ch);

}

func_max_overs()
{
	if(max_overs==10)
		max_balls=60;
	else if(max_overs==20)
		max_balls=120;
}


void func_team()
{
	
	int m;
	team[1]="India";
	team[2]="Australia";
	team[3]="Pakistan";
	team[4]="South Africa";
	team[5]="West indies";
	team[6]="England";
	team[7]="New Zealand";
	team[8]="Sri Lanka";
	team[9]="Bangladesh";
	team[10]="Zimbabwe";	
	printf("******** Choose Your Teams ********\n");
	for(m=1;m<=10;m++)
		printf("%d %s\n",m,team[m]);
	printf("player1 (won the toss):");
	scanf("%d",&teamp1);
	printf("player2 :");
	scanf("%d",&teamp2);
	getchar();
}
void func_india(int x)
{
		team_players[x][1]="RG Sharma";
		team_players[x][2]="S Dhawan";
		team_players[x][3]="V Kohli";
		team_players[x][4]="AM Rahane";
		team_players[x][5]="SK Raina";
		team_players[x][6]="MS Dhoni";
		team_players[x][7]="RA Jadeja";
		team_players[x][8]="R Ashwin";
		team_players[x][9]="Mohammed Shami";
		team_players[x][10]="MM Sharma";
		team_players[x][11]="UT Yadav";
	
		bowler[x][5]="RA Jadeja";
		bowler[x][4]="R Ashwin";
		bowler[x][3]="Mohammed Shami";
		bowler[x][2]="MM Sharma";
		bowler[x][1]="UT Yadav";


}
void func_australia(int x)
{
	
		team_players[x][1]="AJ Finch";         
		team_players[x][2]="DA Warner";
		team_players[x][3]="SPD Smith";
		team_players[x][4]="GJ Maxwell";
		team_players[x][5]="SR Watson";
		team_players[x][6]="MJ Clarke";
		team_players[x][7]="JP Faulkner";
		team_players[x][8]="BJ Haddin";
		team_players[x][9]="MG Johnson";
		team_players[x][10]="MA Starc";
		team_players[x][11]="JR Hazlewood";

	
		bowler[x][5]="JP Faulkner";
		bowler[x][4]="BJ Haddin";
		bowler[x][3]="MG Johnson";
		bowler[x][2]="MA Starc";
		bowler[x][1]="JR Hazlewood";
	
}


void func_pakistan(int x)
{	

		team_players[x][1]="ahmed Shehzad";
		team_players[x][2]="Younis Khan";
		team_players[x][3]="Haris Sonail";
		team_players[x][4]="Misbah-ul-Haq";
		team_players[x][5]="Sohaib Maqsood";
		team_players[x][6]="Umar Akmal";
		team_players[x][7]="Shahid Afridi";
		team_players[x][8]="Wahab Riaz";
		team_players[x][9]="Yasir Shah";
		team_players[x][10]="Sohail Khan";
		team_players[x][11]="Mohammad irfan";


		bowler[x][5]="Shahid Afridi";
		bowler[x][4]="Wahab Riaz";
		bowler[x][3]="Yasir Shah";
		bowler[x][2]="Sohail Khan";
		bowler[x][1]="Mohammad irfan";
}
void func_southafrica(int x)
{
		team_players[x][1]="HM Amla";
		team_players[x][2]="Q de Kock";
		team_players[x][3]="F du Plessis";
		team_players[x][4]="AB de Villiers";
		team_players[x][5]="DA Miller";
		team_players[x][6]="JP Duminy";
		team_players[x][7]="WD Parnell";
		team_players[x][8]="VD Philander";
		team_players[x][9]="DW Steyn";
		team_players[x][10]="M Morkel";
		team_players[x][11]="Imran Tahir";

	
		bowler[x][5]="WD Parnell";
		bowler[x][4]="VD Philander";
		bowler[x][3]="DW Steyn";
		bowler[x][2]="M Morkel";
		bowler[x][1]="Imran Tahir";
	
}	
	


void func_westindies(int x)
{
		team_players[x][1]="Ch Gayle";
		team_players[x][2]="J Charles";
		team_players[x][3]="LMP simmons";
		team_players[x][4]="MN Samules";
		team_players[x][5]="D Ramdin";
		team_players[x][6]="JL Carter";
		team_players[x][7]="DJG Sammy";
		team_players[x][8]="AD Russell";
		team_players[x][9]="JO Holder";
		team_players[x][10]="JE Taylor";
		team_players[x][11]="SJ Benn";

	
		bowler[x][5]="DJG Sammy";
		bowler[x][4]="AD Russell";
		bowler[x][3]="JO Holder";
		bowler[x][2]="JE Taylor";
		bowler[x][1]="SJ Benn";

}	


void func_england(int x)
{
		team_players[x][1]="MM Ali";
		team_players[x][2]="IR Bell";
		team_players[x][3]="GS Ballance";
		team_players[x][4]="JE Root";
		team_players[x][5]="EJG Morgan";
		team_players[x][6]="JWA Taylor";
		team_players[x][7]="JC Buttler";
		team_players[x][8]="CR Woakes";
		team_players[x][9]="SCJ Broad";
		team_players[x][10]="ST Finn";
		team_players[x][11]="JM A nderson";

		bowler[x][5]="JC Buttler";
		bowler[x][4]="CR Woakes";
		bowler[x][3]="SCJ Broad";
		bowler[x][2]="ST Finn";
		bowler[x][1]="JM A nderson ";
}	

void func_newzealand(int x)
{	

		team_players[x][1]="MJ guptill";
		team_players[x][2]="BB McCullum";
		team_players[x][3]="KS Williamson";
		team_players[x][4]="LRPL Taylor";
		team_players[x][5]="GD Elliott";
		team_players[x][6]="CJ Anderson";
		team_players[x][7]="L Ronchi";
		team_players[x][8]="DL Vettori";
		team_players[x][9]="AF Milne";
		team_players[x][10]="TG Southee";
		team_players[x][11]="TA Boult";

		bowler[x][5]="L Ronchi";
		bowler[x][4]="DL Vettori";
		bowler[x][3]="AF Milne";
		bowler[x][2]="TG Southee";
		bowler[x][1]="TA Boult";
	
}
void func_srilanka(int x)
{
		team_players[x][1]="HDRL Thirimanne";	
		team_players[x][2]="KC Sangakkara"; 
		team_players[x][3]="DPMD Jayawardene";	 
		team_players[x][4]="FDM Karunaratne";
		team_players[x][5]="LD Chandimal";	
		team_players[x][6]="BMAJ Mendis";
		team_players[x][7]="NLTC Perera";
		team_players[x][8]="KMDN Kulasekara";
		team_players[x][9]="SMSM Senanayake";		
		team_players[x][10]="HMRKB Herath";
		team_players[x][11]="L Malinga";
	
		bowler[x][5]="NLTC Perera";
		bowler[x][4]="KMDN Kulasekara";
		bowler[x][3]="SMSM Senanayake";		
		bowler[x][2]="HMRKB Herath";
		bowler[x][1]="L Malinga";
	//team_players[]="PVD Chameera"
	//team_players[]="RAS Lakmal"
	//team_players[]="TM Dilshan"
	//team_players[]="AD Mathews"

}

void func_bangladesh(int x)
{	
		team_players[x][1]="Anamul Haque";            
		team_players[x][2]="Tamim Iqbal";
		team_players[x][3]="Soumya sarkar";
		team_players[x][4]="Mahumudullah";
		team_players[x][5]="Shakib Al Hasan	";
		team_players[x][6]="Muhfiqure Rahim	";
		team_players[x][7]="Sabbir Rahman";
		team_players[x][8]="Mashrafe Mortaza";
		team_players[x][9]="Mominul Haque";
		team_players[x][10]="Rubel Hossain";
		team_players[x][11]="Taskin Ahmed";


		bowler[x][5]="Sabbir Rahman	";
		bowler[x][4]="Mashrafe Mortaza";
		bowler[x][3]="Mominul Haque	";
		bowler[x][2]="Rubel Hossain	";
		bowler[x][1]="Taskin Ahmed";
	
}	
 


void func_zimbabwe(int x)
{
	
		team_players[x][1]="CJ Chibhabha";
		team_players[x][2]="Sikandar Raza";
		team_players[x][3]="H Masakadza";
		team_players[x][4]="BRM Taylor";
		team_players[x][5]="SC Williams";
		team_players[x][6]="CR Ervine";
		team_players[x][7]="T Kamungozi";
		team_players[x][8]="RW Chakabva";
		team_players[x][9]="S Matsikenyeri";
		team_players[x][10]="SF Mire";
		team_players[x][11]="T Mupariwa";


		bowler[x][5]="T Kamungozi";
		bowler[x][4]="RW Chakabva";
		bowler[x][3]="S Matsikenyeri";
		bowler[x][2]="SF Mire";
		bowler[x][1]="T Mupariwa";

	//team_players[]="T Panyangara
	//team_players[]="TL Chatara
	//team_players[]="P Utseya
	//team_players[]="E Chigumbura
}

void func_teamplayers()
{
	if(teamp1==1)
		func_india(1);
	else if(teamp1==2)
		func_australia(1);			
	else if(teamp1==3)
		func_pakistan(1);
	else if(teamp1==4)
		func_southafrica(1);
	else if(teamp1==5)
		func_westindies(1);
	else if(teamp1==6)
		func_england(1);
	else if(teamp1==7)
		func_newzealand(1);
	else if(teamp1==8)
		func_srilanka(1);
	else if(teamp1==9)
		func_bangladesh(1);
	else if(teamp1==10)
		func_zimbabwe(1);
	if(teamp2==1)
		func_india(2);
	else if(teamp2==2)
		func_australia(2);			
	else if(teamp2==3)
		func_pakistan(2);
	else if(teamp2==4)
		func_southafrica(2);
	else if(teamp2==5)
		func_westindies(2);
	else if(teamp2==6)
		func_england(2);
	else if(teamp2==7)
		func_newzealand(2);
	else if(teamp2==8)
		func_srilanka(2);
	else if(teamp2==9)
		func_bangladesh(2);
	else if(teamp2==10)
		func_zimbabwe(2);
}

void func_random_no(time_t t)
{
	
	rand_no=rand()%100;
	//printf("random no %d\n",rand_no);
}

void func_overs()
{
	int temp1,temp2;
	temp1=over%10;
	if(flag!=2 && flag!=3)
	{
		if(temp1==5)
			over+=5;
		else over+=1;
			
	}
	
}

void func_this_is()    
{
	int extratemp=0,temp;
	flag=0;
	if((rand_no >=0 && rand_no <20) || (rand_no>=90 && rand_no<97))
		 this_is = 1;
	else if(rand_no>=20 && rand_no<37)
		this_is = 0; 
	else if(rand_no >=37 && rand_no <63 )
		this_is = 2;
	else if(rand_no >=63 && rand_no < 66)
		this_is = 3;
	else if(rand_no >= 66 && rand_no < var )
	{
		this_is =4;
		four[inning][str]++;
	}	
	else if(rand_no >=var && rand_no < 79)
		{	
			wicket++;
			player_balls[inning][str]++;
			if(rand_no>=70 && rand_no<=73)
			{	
				bowler_wickets[other][current_bowler]+=1;
				printf("oops!! this is bold       %s %d/%d\n\n",team_players[inning][str],player_runs[inning][str],player_balls[inning][str]);
				w[str]=1;
			}				
			else if(rand_no==74)
			{			
				printf("oops!! This is Run out     %s %d/%d\n\n",team_players[inning][str],player_runs[inning][str],player_balls[inning][str]);
				w[str]=2;
			}			
			else if(rand_no==76 || rand_no==77)
			{			
				bowler_wickets[other][current_bowler]+=1;
				printf("oops!! this is Lbw        %s %d/%d\n\n",team_players[inning][str],player_runs[inning][str],player_balls[inning][str]);
				w[str]=3;
			}
			else
			{
				bowler_wickets[other][current_bowler]+=1;
				printf("oops!! this is catch Out    %s %d/%d\n\n",team_players[inning][str],player_runs[inning][str],player_balls[inning][str]);
				w[str]=4;
			}
			if(max_overs==10 && wicket==3)
				var-=2;
			else if(max_overs==20 && wicket==3)
				var-=1;
			flag=1;
			this_is =0;							//wicket
			str=wicket+2;
		}
	else if(rand_no >=79 && rand_no <85 )
	{
		this_is = 6;
		six[inning][str]++;
	}	
	else if(rand_no >=85 && rand_no <90 )
	{
		bowler_runs[other][current_bowler]+=1;
		this_is=0;
		flag=2;
		extratemp+=1;
		if(rand_no==85)
		{
			extratemp+=4;								//wide
			bowler_runs[other][current_bowler]+=4;
		}	
	}
	else if(rand_no >=97 && rand_no <=100 )
	{
		bowler_runs[other][current_bowler]+=1;	
		flag=3;									//no ball;
		extratemp+=1;
		if(rand_no==100)
		{
			this_is = 6;
			six[inning][str]++;
		}		
		else(this_is = rand_no%10-7);
		
	}
	if(rand_no==85)
		printf("this is four on wide ball\n");	
	else if(flag==1);	
	else if(flag==2)
	{
		printf("this is wide ball\n");
	}
	else if(flag==3)
		printf("this is %d on no ball\n",this_is);
	else 
	{
		printf("this is %d run\n" ,this_is);
		temp=player_balls[inning][str];
		player_balls[inning][str]=temp+1;
	}
	bowler_runs[other][current_bowler]+=this_is;	
	player_runs[inning][str]=player_runs[inning][str]+this_is;	//no ball
	total[j]+=this_is;
	total[j]+=extratemp;
	extra[inning]+=extratemp;
}

void func_change_strike()
{
	int temp1,temp2;
	temp2=over%10;
	if((this_is%2!=0 && flag!=2 && flag!=3) || (temp2==5 && flag!=2 && flag!=3) || (this_is%2==0 && flag==2 && flag==3))
	{
		temp1=str;
		str=nstr;
		nstr=temp1;
	}
}

void func_change_bowler()
{
	int temp,temp1,temp2;
	temp=over%10;

	
	if(temp==1 && flag!=2 && flag!=3 && over>9)
	{
			current_bowler+=1;
			if(current_bowler>5)
				current_bowler%=5;
	}
	temp1=bowler_overs[other][current_bowler]%10;
	if(flag!=2 && flag!=3)
	{
		if(temp1==5)
			bowler_overs[other][current_bowler]+=5;
		else bowler_overs[other][current_bowler]+=1;
			
	}
}
void func_live_scoreboard()
{
	int k,temp,max_length1,max_length2;
	if(j==1)
		k=teamp1;
	else k=teamp2;
	max_length1=strlen(team_players[inning][str]);
	max_length2=strlen(team_players[inning][nstr]);
		if(wicket!=10)
		{
			printf("%s %d/%d       %s %d/%d   %s %d/%d    overs = %.1f    bowler = %s  %.1f  %d/%d",team[k],total[j],wicket,team_players[inning][str],player_runs[inning][str],player_balls[inning][str],team_players[inning][nstr],player_runs[inning][nstr],player_balls[inning][nstr],over/10.0,bowler[other][current_bowler],bowler_overs[other][current_bowler]/10.0,bowler_runs[other][current_bowler],bowler_wickets[other][current_bowler]);
			if(inning==2)
					printf("    Target = %d\n",total[1]+1);
			else
				printf("\n");
		}

	
}


void func_mom(int inning)
{
	
	int i,j,t=2,momi,momp,max;
	while(t--)
	{
		for(i=1;i<=11;i++)
		{
			point[inning][i]+=player_runs[inning][i];
			point[inning][i]+=(2*six[inning][i]);
			if(player_runs[inning][i]==0)
				point[inning][i]-=5;
			else if(player_runs[inning][i]>25)
				point[inning][i]+=10;
			if(bowler_wickets[inning][i]==1)
					point[inning][i]+=20;
			else if(bowler_wickets[inning][i]>1)
					{	
						point[inning][i]+=20;
						point[inning][i]+=(10*(bowler_wickets[inning][i]-1));
					}
			if(total[1]>total[2] && inning==1)
					point[inning][i]+=30;
			else if(total[2]>total[1] && inning==2)
					point[inning][i]+=30;
		}
		inning--;
	}	
	t=2;
	inning=2;
	max=0;
	while(t--)
	{
		for(i=1;i<=11;i++)
		{
			if(point[inning][i]>max)
				{
					max=point[inning][i];
					momi=inning;
					momp=i;
				}

		}
		inning--;

	}
	printf("    **********%s is man of the match**********\n",team_players[momi][momp]);

}

int main(int argc, char const *argv[])
{
	int wicket1,m,k;
	extra[1]=0;
	extra[2]=0;
	inning=1;
	func_banner();
	printf("                          	  <<<<<<  Hello!! This is cricet 2015 >>>>>\n");
		
	
	while(1)
	{
		printf("select overs 10 or 20 :");
		scanf("%d",&max_overs);
		if(max_overs==10 || max_overs == 20)
			break;
	}	
	getchar();
	func_max_overs();
	func_Toss();
	func_team();
	//*team_players=malloc(sizeof(char)*100);	
	func_teamplayers();
	printf("Best of luck to both captains\n");
	srand((unsigned) time(&t));
	while(inning<3)
	{
		if(inning==1)
			other=2;
		else other=1;
		for(i=0;i<=12;i++)
		{
			bowler_runs[other][i]=0;
			player_runs[inning][i]=0;
			player_balls[inning][i]=0;
			four[inning][i]=0;
			six[inning][i]=0;
			bowler_wickets[other][i]=0;
			bowler_overs[other][i]=0;
			point[inning][i]=0;
			if(i<3)
			{
				maxbat[i]=0;	
				maxbowl[i]=0;
			}	
		}
		over=0,current_bowler=1;
		printf("				  ******************inning %d*******************\n",inning);
		total[j]=0,wicket=0,str=1,nstr=2,extra[inning]=0;
		while(wicket!=10 && over/10.0<max_overs)
		{
			printf("press Enter key:");
			scanf("%c",&ch);
			//getchar();
			func_random_no(t);
			func_this_is();
			func_change_strike();
			func_overs();		
			func_change_bowler();	
			func_live_scoreboard();
			
			//printf("run team %d = %d\n",j,total[j]);
			player_runs[inning][wicket+1];
			player_runs[inning][wicket+2];
			if(inning==2 && total[2]>total[1])
				break;
		}
		func_final_scoreboard();
		if(inning==1)
			wicket1=wicket;
		var=73;
		printf("Total runs      %d/%d 		Extras=%d\n",total[j],wicket,extra[j]);
			
		j++;
		inning++;
	}
	printf("%s = %d/%d\n",team[teamp1],total[1],wicket1);
	printf("%s =%d/%d\n",team[teamp2],total[2],wicket);
	if(total[1]==total[2])
		printf("Match is Draw\n");
	else if(total[1]>total[2])
		printf("%s won this match by %d Runs\n",team[teamp1],total[1]-total[2]);
	else printf("%s won this match by %d wickets\n",team[teamp2],10-wicket);
	func_mom(2);
	return 0;
} 

