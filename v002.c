
//Including Header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring function

char* word_correction_2(char* c);
void delay(int n);
void loading();
void searching();
int bus();

//main function
int main()
{
    printf("\n\n\n\t\t\t\t");
    printf("Welcome to Dhaka Bus route service.");
    printf("\n\n\t\t\t\t");
    printf("Press any key to start exploring..");
    getchar();
    loading();
    bus();
//while loop start again and again
    while(1)
    {
        printf("\nWant to search again?\n(1 to restart. 2 to end)");
		printf("\n\t\t\t\t\t1/2:");
    int main_in;
    scanf("%d",&main_in);
    if(main_in==1)
    {
            system("cls");
            bus();
    }
    if(main_in==2)
        return 0;
    }
}


//main bus route function
int bus()
{
    //declaring files
    FILE * file;
    FILE* fp;

	//Declaring veriables
    char bus_name[100][100],sorted_bus_name[100][100];
    char chr[100],in_file[100];
    char d[100];
    char in[100],out[100],bus_route[100];
    char c[1000];
    char q[100];
    char form[100];
    int e=0,Toerror=0;
    int revt=0,flag_count=0,form_cheak=0;
    char fIn;
    char p[100];
    char tIn;
    char* to;
    char* t;
	//for reverse order
    int rev=1;
    int form_flag=0;
	//inisialize
    int i=0;
    int start=0,end=0,flag=0;
	//input taking start here
form_a:
    system("cls");
    printf("Press any key to search...");
    getchar();
    system("cls");
    printf("\t\t\t\t\t\tFROM:");
    gets(p);
	//sent it to word correction function and return correct word and store it in char veriable
    t=word_correction_2(p);
    strcpy(form,t);
	//printf("%s",t);
    searching();
	//input choice
	//if it return ** then the word does not exist
	if(!strcmp(form,"**"))
    {
        printf("Sorry no result found.\nPlease search again");
        getchar();
        goto form_a;
    }
    else{
    printf("\n\t\t\t\t\t\tAre you searching for :%s?\n",form);
    printf("\t\t\t\t\t\tEnter your choice(y/n):");
    fIn=getchar();
    if(fIn=='n'||fIn=='N')
    {
        system("cls");
        goto form_a;
    }
    else if(fIn=='y'|| fIn=='Y')
        goto to_a;
    else
    {
        printf("\t\t\t\t\t\tInvalid input");
        getchar();
        //system("cls");
        goto form_a;
    }
    }
to_a:

    getchar();
    printf("\t\t\t\t\t\tto:");
    gets(q);
    to=word_correction_2(q);
    searching();
    if(!strcmp(to,"**"))
    {
        printf("\t\t\t\t\tSorry no result found.\n\t\t\t\tPlease search again.\n\t\t\t\tPress any key to search...");
        //getchar();
        goto to_a;
    }
    else
    {
    printf("\n\t\t\t\t\t\tAre you searching for :%s?\n",to);
    printf("\t\t\t\t\t\tEnter your choice(y/n):");
    tIn=getchar();
    if(tIn=='n'||tIn=='N')
        goto to_a;
    else if(tIn=='y'|| tIn=='Y')
        goto Search;
    else
    {
        printf("\t\t\t\t\t\tInvalid input");
        goto to_a;
    }
    }

Search:
    printf("\n\n\t\t\tShowing result form location %s to %s>>>\n",form,to);
    char area_name[6000][100]=
    {
        "!","A01.txt","mirpur10","mirpur2","mirpur1","gabtoli","savar","nobinogor","chondra",
        "!","A11.txt","mirpur10","mirpur14","kajipara","sheorapara","agargaon","farmgate","shahbagh","maotijheel","sayedabad","jatrabari",
        "!","trust.txt","mirpur10","cantonment","banani","notunbazar",
        "!","trust.txt","mirpurdohs","kalshi","ecb","garrison","adamjeschool","workshop","saudicolony","jahangirgate","farmgate","kawranbazar","banglamotor","shahbag","highcourt","pressclub","paltan","gpo",
        "!","A06.txt","mirpur10","mirpur2","mirpur1","gabtoli","savar","nobinogor","chondra",
        "!","A05.txt","mirpur10","mirpur1","mazarroad","beribadh","ashuliya","fantasykingdom","nondonpark",
        "!","A04.txt","mirpur10","kalshi","bisshoroad","airport","uttara","abdullahpur",
        "!","A03.txt","gabtoli","technical","ansarcamp","mirpur1","sonyhall","mirpur2","mirpur10","mirpur11","purobi","kalshi","ecbsquare","mes","shewrapara","kurilbishwaroad","bashundhara","nadda","natunbazar","bashtola","shahjadpur","uttarbaddabazar","badda","madhyabadda","merul","rampurabridge","banashree","demra","staffquarter",
        "!","A01.txt","gabtoli","mirpur1","mirpur10","mirpur12","mirpur11","kalshi","bisshoroad","airport","uttora","abdullahpur","tongi","gazipur",
        "!","A02.txt","gabtoli","mirpur1","mirpur10","mirpur11","mirpur12","kalshi","banani","gulshan2","gulshan1","baddalinkroad",
        "!","A03.txt","gabtoli","mirpur1","mirpur10","mirpur12","kalshi","kurilflyover","nutunbazar",
        "!","A01.txt","gabtoli","abdullahpur",
        "!","A45.txt","gabtoli","mirpur1","mirpur10","kazipara","shewrapara","mohakhali","kakoli","banani","gulshan2","nutunbazar","badda","rampura",
        "!","A46.txt","mohammadpur","asadgate","shukrabad","kolabagan","citycollege","sciencelab","shahbag","pressclub","gulistan","arambag","notredamecollege",
        "!","A15.txt","mohammadpur","shankar","starkabab","jhigatola","citycollege","sciencelab","shahbag","pressclub","gulistan","arambag","notredamecollege",
        "!","A11.txt","mohammadpur","asadgate","farmgate","mohakhali","titumircollege","gulshan1","badda","notunbazar",
        "!","A04.txt","agargaon","mirpur10","kalshi","bisshoroad","airport","uttara","abdullahpur",
        "!","A04.txt","shiyamasjid","shyamoli","agargaon","mirpur10","kalshi","bisshoroad","airport","uttara","abdullahpur",
        "!","A34.txt","mirpursonycinemahall","mirpur10","kazipara","shewrapara","mohakhali","gulshan1","badda","rampura","bonoshri",
        "!","A34.txt","mirpursonycinemahall","mirpur10","kazipara","shewrapara","mohakhali","gulshan1","badda","rampura","khilgaonkhidmahospital",
        "!","A07.txt","roopnagarabasik","mirpur2","mirpur1","kolyanpur","shyamoli","asadgate","shukrabad","kolabagan","sciencelab","newmarket","nilkhet","azimpur",
        "!","A37.txt","roopnagarabasik","mirpur2","mirpur1","khamarbari","farmgate","gulistan","keraniganj",
        "!","A12.txt","kalshi","mirpursare11","mirpur10","kazipara","shewrapara","idb","khamarbari","farmgate","karwanbazar","shahbag","gulistan","sadarghat",
        "!","A08.txt","chiriyakhana","mirpur1","gabtoli","savar","nobinogor","chondra",
        "!","A40.txt","chiriyakhana","mirpur1","mirpur10","agargaon","bijoysarani","farmgate","banglamotor","mogbazar","malibag","komlapur",
        "!","A38.txt","chiriyakhana","mirpur1","khamarbari","farmgate","pressclub","motijhil",
        "!","A09.txt","mirpur1","technical","kolyanpur","asadgate","kolabagan","sciencelab","shahbag","pressclub","gulistan","motijhil","jatrabari",
        "!","A13.txt","mirpur1","kolyanpur","shyamoli","agargaon","notunrasta","mohakhali","flyover","banani","gulshan2","notunbazar",
        "!","A39.txt","mirpur1","kolyanpur","shyamoli","asadgate","shukrabad","kolabagan","sciencelab","newmarket","nilkhet","azimpur",
        "!","A39.txt","mirpur14","mirpur1","technical","kolyanpur","asadgate","kolabagan","sciencelab","newmarket","nilkhet","azimpur","tsc","shahbag","pressclub","gulistan","tikatuli","jatrabari",
        "!","A10.txt","asadgate","shyamoli","kolyanpur","technical","mirpur1","mirpur2","mirpur6","cholontikamor","mirpur7","mirpur11","mirpur12",
        "!","A14.txt","savar","gabtoli","kolyanpur","shyamoli","agargaon","notunrasta","mohakhali","gulshan1","baddalinkroad","notunbazar",
        "!","A35.txt","savar","hemayetpur","gabtoli","technical","kallyanpur","shyamoli","shishumela","agargaon","ziauddan","bijoysarani","jahangirgate","mohakhali","wirelessmor","gulshanbridge","gulshan1","badda","rampurabridge","banashree",
        "!","A36.txt","baipayl","savar","hemayetpur","aminbazar","gabtoli","technical","kallyanpur","shyamoli","shishumela","collegegate","asadgate","dhanmondi27","dhanmondi32","kalabagan","citycollege","newmarket","nilkhet","azimpur","bakshibazar","gulistan","signboard⇄chankharpul","fulbaria",

		"!","A16.txt","mirpur12","pallabi","purobi","mirpur11","mirpur10","kajipara","shewrapara","taltola","agargaon","khamarbari","dhanmondi27","dhanmondi32","kalabagan","citycollege","newmarket","nilkhet","azimpur","dhakeswari",
        "!","A23.txt","mirpur12","mirpur11","mirpur10","kazipara","shewrapara","mohakhali","gushan1","badda","natunbazar",
        "!","A24.txt","mirpur12","shewrapara","gulistangolap","shahmazar",
        "!","A25.txt","mirpur12","sadarghat","victoriapark",
        "!","A26.txt","mirpur12","mirpur10","agargaon","farmgate","shahbag","motijhil","notredamecollege",
        "!","A27.txt","mirpur12","mirpur10","kakoli","ecb","airport","uttara","abdullahpur",

		"!","A21.txt","gulistan","shahbag","farmgate","shyamoli","gabtoli","savar","nobinogor","nandanpark",
        "!","A21.txt","gulistan","shahbag","farmgate","banani","uttara","gazipur","shibbari",
        "!","A22.txt","gulistan","polton","malibag","mogbazar","saatrasta","nabisko","mohakhali","bonani","airport","uttara","abdullahpur","tongi","gazipur","kaliyakoir",
        "!","A33.txt","motijhil","gulistan","gpo","paltan","pressclub","highcourt","shahbag","banglamotor","karwanbazar","farmgate","khamarbari","jahangirgate","mohakhali","chairmanbari","banani","kakoli","staffroad","mes","shewrabazar","kurilbisshoroad","khilkhet","airport","jashimuddin","rajlakshmi","azampur","uttarahousebuilding","abdullahpur","tongi","boardbazar","gazipurchowrasta","shibbari",
        "!","A33.txt","motijhil","gulistan","gpo","paltan","pressclub","highcourt","shahbag","banglamotor","karwanbazar","farmgate","khamarbari","asadgate","collegegate","shishumela","shyamoli","kalyanpur","darussalam","technical","gabtoli","aminbazar","hemayetpur","savar","nobinagar","baipayl","ziranibazar","nandanpark",
        "!","A17.txt","motijhil","gulistan","polton","malibag","mogbazar","saatrasta","nabisko","mohakhali","gulshan1","baddalinkroad","notunbazar",
        "!","A22.txt","motijhil","komlapur","malibag","mogbazar","nabisko","mohakhali","banani","khilkhet","airport","uttara","tongi","boardbazar","gazipur",
        "!","A17.txt","motijhil","gulistan","polton","malibag","mogbazar","karwanbazar","farmgate","bijoysarani","mohakhali","gulshan1","gulshan2","notunbazar",
        "!","A44.txt","balughat","cantonment","bijoysarani","farmgate","banglamotor","shahbag","polton","gulistan","motijhil",
        "!","A18.txt","mirpur14","mirpur10","mirpur1","technical","kolyanpur","asadgate","sciencelab","shahbag","pressclub","motijhil","komlapur","mugda","khilgaon",
        "!","A28.txt","mirpur14","mirpur10","kazipara","agargaon","shyamoli","asadgate","mohammadpur","dhanmondi15","jhigatola","sciencelab","dhakacollege","newmarket","nilkhet","edencollege","azimpur",
        "!","A29.txt","mirpur14","mirpur1","shyamoli","asadgate","mohammadpur","shankar","dhanmondi15","jhigatola","katabon","shahbag","gulistan","motijhil","notredamecollege",
        "!","A30.txt","mirpur14","kochukhet","soinikclub","kakoli","banani",
        "!","A42.txt","adabor","shiyamasjid","shyamoli","collegegate","asadgate","kolabagan","sciencelab","shahbag","kakrail","fokirapul","motijhil","doyaganj",
        "!","A42.txt","shaymoli","asadgate","kolabagan","sciencelab","katabon","shahbag","gulistan",
        "!","A41.txt","modonpur","narayanganj","jatrabari","bangladeshbank","mogbazar","mohakhali","tongibridge",
        "!","A41.txt","jatrabari","sayedabad","mugda","khilgaon","malibag","mogbazar","karwanbazar","farmgate","asadgate","shyamoli","gabtoli","savar",
        "!","A31.txt","azimpur","kolabagan","asadgate","farmgate","mohakhali","banani","uttarahousebuilding",
        "!","A31.txt","azimpur","sciencelab","shahbag","kakrail","mouchak","malibag","rampura","badda","kurilbisshoroad","uttarahousebuilding",
        "!","A31.txt","azimpur","nilkhet","newmarket","citycollege","kalabagan","dhanmondi32","dhanmondi27","khamarbari","farmgate","jahangirgate","mohakhali","shainikclub","banani","kakoli","staffroad","mes","shewrabazar","kurilbishwaroad","khilkhet","airport","jashimuddin","rajlakshmi","azampur","housebuilding","abdullahpur","tongi","stationroad","millgate","boardbazar","gazipurchowrasta",
        "!","A31.txt","edencollege","nilkhet","newmarket","citycollege","kolabagan","panthapath","karwanbazar","bottola","nabisco","mohakhali","wirelessgate","gulshan1","badda","uttarbaddabazar","shahzadpur","bashtola","natunbazar","nadda","basundhara","kurilbisshoroad",
        "!","A32.txt","edencollege","sciencelab","kolabagan","asadgate","khamarbari","kakoli","bonani","abdullahpur",
        "!","A20.txt","sadarghatvictoriapark","rayshahebbazar","nayabazar","golapshahmazar","gpo","paltan","kakrail","shantinagar","malibaghmor","mouchak","malibagrailgate","rampura","merul","maddhyabadda","badda","uttorbaddabazar","shahjadpur","bashtola","natunbazar","nadda","bashundhara","jamunafuturepark","kurilbisshoroad","khilkhet","airport","jashimuddin","rajlakshmi","azampur","uttarahousebuilding","abdullahpur","tongi","stationroad","millgate","hossainmarket","boardbazar","gazipur",
        "!","A20.txt","sadarghat","victoriapark","kakrail","mouchak","malibagrailgate","badda","notunbazar","basundhara","kuril","uttara","tongi","gazipur",
        "!","A20.txt","sadarghat","victorialpark","gulistan","kakrail","malibag","mogbazar","mohakhali","airport","abdullahpur","gazipurbypass","chondra",
        "E"
    };
    printf("\t\t\t\t\t\t");
    loading();
    printf("\n");
//start searching
    while(1)
    {
//if match break!
START:
        if(!strcmp(area_name[i],"!"))
			//if we found ! then we store the file name after the next index
            strcpy(in_file,area_name[i+1]);
        if(!strcmp(area_name[i],form))
        {
            start=i;
            //printf(" %d",i);
            while(1)
            {
                if(!strcmp(area_name[i],to))
                {
                    form_cheak=1;
                    rev=0;
                    end=i;
                    flag=1;
                    flag_count=1;
                    goto FLAG;
                }
                else if(!strcmp(area_name[i],"!"))
                {
                    strcpy(in_file,area_name[i+1]);
                    start=i+2;
                    goto START;
                }
                else if(!strcmp(area_name[i],"E"))
                {
                    if(form_flag==1)
                    printf("\t\t\t\t\t\tNot found!!\n");
                    else
                        goto Reverse;
                }
                i++;
            }
        }
        else if(!strcmp(area_name[i],"E"))
        {
            Reverse:
                form_flag=1;
            if(rev==1 && revt==0)
            {
                char temp[100];
                strcpy(temp,form);
                strcpy(form,to);
                strcpy(to,temp);
                i=0;
                revt=1;
                goto START;
            }
            printf("\n\n\t\t\t\t\tSearch completed\n\n");
            break;
        }
        i++;
    }
FLAG:
    if(flag==1)
    {
        //printf("File:%s\n",in_file);
        if(rev==0)
        {
            for(int j=start; j<=end; j++)
            {
                printf ("%s", strupr(area_name[j]));
                if(j<end)
                    printf("-->");
            }
            printf("\n");
            flag=0;
        }
        if(rev==1 )
        {
            for(int j=end; j>=start; j--)
            {
                printf ("%s", strupr(area_name[j]));
                if(j>start)
                    printf("-->");
            }
            printf("\n");
            flag=0;
        }
		//open file for read the bus name
        fp = fopen(in_file,"r");
        while(!feof(fp))
        {
			//store it in a 2D char array
            fscanf(fp, "%s",bus_name[e]);
            e++;
        }
        fclose(fp);
        //end
        goto START;
        exit(1);
    }
    else if(flag_count==0)
    {
        printf("\t\t\t\tNo route!!\nPlease search again.");
        return 0;
    }
    //remove duplicate

    for (int i = 0; i <= e; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            if(strcmp(bus_name[i], bus_name[j]) == 0)
            {
                strcpy(sorted_bus_name[i], bus_name[i]);
                i++;
            }
            else
                strcpy(sorted_bus_name[i], bus_name[i]);
        }
    }


if(flag==0){
    printf("\t\t\tAvailable Buses:\n");
    for(int i=0; i<=e; i++)
    {
        if(sorted_bus_name[i][0]==' ')
            continue;
        else
            {
                printf("%s ",sorted_bus_name[i]);
                if(i<e)
                    printf("Poribahan.\n");
            }
    }
}
else
    printf("S");

}
//
char* word_correction_2(char* c)
{
    int right_tag=0;
    int final_curr;
    char s[1000],i,j=0,test=0;
    for(int i=0; i<strlen(c); i++)
    {
        //space remover
IF:
        if((c[i]==' '|| c[i]=='_' || c[i]=='-' || c[i]=='.') && c[i]!='\0')
        {
            i++;
            goto IF;
        }
        {
            s[j]=c[i];
            j++;
        }
    }
    s[j]='\0';
    strlwr(s);
    strcpy(c,s);
    //printf("%s",c);
    int pre_corr=0,curr=0,pre_err=0,err=0;
    char a[217][100]=
{
    "mirpur10","mirpur2","mirpur1","gabtoli","savar","nobinogor","chondra","ecb",
    "mirpur14","kajipara","sheorapara","agargaon","farmgate","shahbagh","maotijheel","sayedabad","jatrabari",
    "cantonment","banani","notunbazar",
    "mirpurdohs","ecb","garrison","adamjeschool","workshop","saudicolony","jahangirgate","kawranbazar","banglamotor","shahbag","highcourt",
    "pressclub","paltan","gpo",
    "mazarroad","beribadh","ashuliya","fantasykingdom","nondonpark",
    "kalshi","airport","uttara","abdullahpur",
    "technical","ansarcamp","sonyhall","mirpur11","purobi","ecbsquare","mes","shewrapara","kurilbishwaroad","bashundhara","nadda","natunbazar",
    "bashtola","shahjadpur","uttarbaddabazar","badda","madhyabadda","merul","rampurabridge","banashree","demra","staffquarter",
    "uttora","tongi","gazipur",
    "gulshan1","baddalinkroad",
    "kurilflyover","nutunbazar","bisshoroad",
    "kazipara","mohakhali","kakoli","rampura",
    "asadgate","shukrabad","kolabagan","citycollege","sciencelab","gulistan","arambag","notredamecollege",
    "shankar","starkabab","jhigatola",
    "mohammadpur","titumircollege","shiyamasjid",
    "mirpursonycinemahall","bonoshri","khilgaonkhidmahospital",
    "roopnagarabasik","shyamoli","newmarket","nilkhet","azimpur","khamarbari","keraniganj",
    "mirpursare11","idb","karwanbazar","sadarghat","mogbazar","malibag",
    "chiriyakhana","motijhil","notunrasta","flyover","tsc","tikatuli","mirpur6","cholontikamor","mirpur7",
    "hemayetpur","kallyanpur","ziauddan","wirelessmor","gulshanbridge",
    "baipayl","bakshibazar","signboard⇄chankharpul","fulbari","pallabi","taltola","dhakeswari","gushan1","gulistangolap",
    "shahmazar","victoriapark","mirpur12","shibbari","kaliyakoir",
    "chairmanbari","jashimuddin","rajlakshmi","azampur",
    "shishumela","kalyanpur","darussalam","aminbazar","nobinagar","ziranibazar","nandanpark",
    "saatrasta","nabisko","khilkhet","gulshan2","balughat","bijoysarani","polton","kolyanpur","komlapur",
    "mirpur14busstand","dhakmondi15","dhakacollege","dhanmondi15","kochukhet","soinikclub",
    "adabor","collegegate","fokirapul","doyaganj","shaymoli","katabon",
    "modonpur","narayanganj","bangladeshbank","tongibridge","mugda","khilgaon",
    "kakrail","mouchak","kurilbisshoroad","uttarahousebuilding","kalabagan","dhanmondi32","dhanmondi27","shainikclub","staffroad","shewrabazar",
    "housebuilding","stationroad","millgate","boardbazar","gazipurchowrasta","panthapath","bottola","nabisco","wirelessgate","shahzadpur","edencollege",
    "sadarghatvictoriapark","rayshahebbazar","nayabazar","golapshahmazar","shantinagar","malibaghmor","malibagrailgate",
    "maddhyabadda","uttorbaddabazar","jamunafuturepark","hossainmarket","basundhara","kuril","victorialpark","gazipurbypass",
    "!"
};

    char currect[100];
    for(int k=0; k<217; k++)
    {
        int i=0,j=0,d=0;
        if(c[0]==a[k][0])
        {
            right_tag=1;
            if(strlen(c)>=strlen(a[k]) && (strlen(c)-strlen(a[k]))<4)
            {
                {
A:
                    while(i<strlen(c))
                    {
B:
                        while(j<strlen(a[k]))
                        {
                            if(c[i]==a[k][j])
                            {
                                curr++;
                                i++;
                                j++;
                                if(curr==strlen(a[k]-1))
                                    goto end;
                                //printf("%s:%d%d ",a[k],i,j);
                                goto A;
                            }
                            else
                            {
                                //printf("%sE:%d%d ",a[k],i,j);
                                if((c[i+1]==a[k][j]))

                                    //if(((i+1)<strlen(c-1))&&(c[i+1]==a[k][j]))
                                {
                                    //printf("Goto B:");
                                    //printf("%s:%d%d ",a[k],i,j);
                                    i++;
                                    goto B;
                                }
                                else
                                {
                                    err++;
                                    i++;
                                    j++;
                                    //printf("Q:%d%d ",i,j );
                                    goto A;
                                }
                            }
                        }
                        i++;
                    }
                }
end:
                if(curr>=pre_corr && err<pre_err)
                {
                    strcpy(currect,a[k]);
                    pre_corr=curr;
                    pre_err=err;
                }
                //printf("A:%d  ",curr);
                curr=0;
                err=0;
            }
            else if(strlen(a[k])-strlen(c)<4)
            {
                {
C:
                    while(i<strlen(c))
                    {
D:
                        while(j<strlen(a[k]))
                        {
                            if(c[i]==a[k][j])
                            {
                                curr++;
                                i++;
                                j++;
                                if(curr==strlen(a[k]-1))
                                    goto end2;
                                //printf("%s:%d%d ",a[k],i,j);
                                goto C;
                            }
                            else
                            {
                                //printf("E:%d%d ",i,j);
                                if((c[i]==a[k][j+1]))
                                    //if(((j+1)<strlen(c-1))&&(c[i]==a[k][j+1]))
                                {
                                    // printf("Goto B:");
                                    j++;
                                    goto D;
                                }
                                else
                                {
                                    i++;
                                    j++;
                                    err++;
                                    //printf("Q:%d%d ",i,j );
                                    goto C;
                                }

                            }
                        }
                        i++;
                    }
                }

end2:
                if(curr>=pre_corr && pre_err>err)
                {
                    strcpy(currect,a[k]);
                    pre_corr=curr;
                    pre_err=err;
                }
                // printf("A:%d  ",curr);
                curr=0;
                err=0;
            }
        }
    }
    if(right_tag==0)
    {
        {
            strcpy(currect,"**");
            char *res=currect;
            return res;
        }
    }

    char *res=currect;
    return res;
}
//


void searching()
{
    char s[]="Searching";
    printf("\n");
    printf("\n\t\t\t\t\t\t");
    for(int i=0;i<9;i++)
    {
        printf("%c",s[i]);
        delay(5000);
    }
    printf("\n");
    printf("\t\t\t\t\t");
    for(int i=1;i<26;i++)
    {
        printf("%c",220);
        delay(1000);
    }
}
void loading()
{
    char s[]="loading";
    printf("\n");
    printf("\n\t\t\t\t\t\t");
    for(int i=0;i<8;i++)
    {
        printf("%c",s[i]);
        delay(5000);
    }
    printf("\n");
    printf("\t\t\t\t\t");
    for(int i=1;i<26;i++)
    {
        printf("%c",220);
        delay(1000);
    }
}
void delay(int n)
{
    for(int i=0;i<25000*n;i++)
    {

    }
}



