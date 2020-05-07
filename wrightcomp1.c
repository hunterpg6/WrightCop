#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <math.h>

#define hours 45



struct payy{
 char name[40],career[20];
 int idno, hourswork,overtime;
 float p_overrate, p_nht,p_nis;
 float incometax;
} payrollinfo;

FILE *equipment;
FILE *material;
FILE *subcontractor;
FILE *workers;
FILE *pay;
void logwright();
void addequipment();
void addmaterial();
void addsubcontract();
void addworker();
void payroll();

float nht,nis;
/* This presents the options in the program*/
int main ()
{
int password;
 char username[30];
 printf("\n");
 printf(" \tWrights Construction Company");
 printf("\n");
 printf("Enter username and password\n");
 scanf("%s%d",username,&password);
 if((password = 1234) && (strcmp(username,"paigeadmin")==0))
 {
     printf(" Correct, you may now enter the system\n");
     system("pause");
     system("cls");
     logwright();

 } else  {
   printf("Password or Username is incorrect\n");
   printf("Closing System\n");
   system("pause");

}


}
/* this presents the log in page for Wright Construction */
void logwright(){


	int price;
	char options;
    printf(" Welcome to Wright Construction Company\n");
    printf("Enter e for Equipments\n");
    printf("Enter m for Materials\n");
    printf("Enter w for Workers\n");
    printf("Enter s for Subcontractors\n");
    printf("Enter p for Payroll\n");
    scanf("%s",&options);

    switch(options){

    	case 'e':
    			addequipment();
    			break;
    	case 'm':
    			addmaterial();
    			break;
		case 'w':
    			addworker();
    			break;
		case 's':
    	     	addsubcontract();
    			break;
		case 'p':
    			payroll();
    			break;
        default:
             printf("\nIncorrect key ");
             Sleep(2000);
             main();
             break;
	}


}

/* this is the function used for the adding of equipment*/
void addequipment(){
  int price,options,choice10;
  char purchasedfrom[60],datepurchase[9],periodrent[9],rentedfrom[60],addequip[40],prevequip[40];
  system("cls");
  printf("Please enter the equipment: ");
  scanf("%s",addequip);
  printf("Please enter price of equipment: ");
  scanf("%d",&price);
  printf(" If equipment is purchased enter 1 or equipment is rented enter 2: ");
  scanf("%d",&options);
  if(options==1){
  printf("Please enter date of purchase: ");
  scanf("%s",datepurchase);
   printf("Please eneter purchased from: ");
  scanf("%s",purchasedfrom);
  } else{
   printf("Please enter period of rent: ");
   scanf("%s",periodrent);
   printf("Please enter rented from: ");
  scanf("%s",rentedfrom);
  }
  if((equipment=fopen("equipment.txt","a+"))== NULL){
  printf("File could not be opened\n");
  }
  else{
  if(options==1){
  	fprintf(equipment,"%s\t%d\t%s\t%s\n",addequip,price,datepurchase,purchasedfrom);
  }
  if (options==2){
  	fprintf(equipment,"%s\t%d\t%s\t%s\n",addequip,price,periodrent,rentedfrom);
  }

  fclose(equipment);
  }
  printf("\n");
  printf("Enter 1 To Continue\n");
  scanf("%d",&choice10);

  switch(choice10)
  {
  case 1:
      system("cls");
    logwright();
    break;


  }

  }


/* this is the function used for the adding of material*/
void addmaterial(){
	int price,choice11;
	char purchasedfrom[60],datepurchase[9],addmat[40],prevmat[40];
	system("cls");
	printf("Please enter the material: ");
	printf("-");
	scanf("%s",addmat);
	printf("Please the price of material: ");
	printf("-");
	scanf("%d",&price);
	printf("Please enter the date of purchase: ");
	printf("-");
	scanf("%s",datepurchase);
	printf("Please enter where the material was perchased from: ");
	scanf("%s",purchasedfrom);

  if((material=fopen("material.txt","a+"))== NULL){
	printf("File could not be opened\n");
} else{
   fprintf(material,"%s\t%d\t%s\t%s\n",addmat,price,datepurchase,purchasedfrom);

 fclose(material);

}
printf("\n");
  printf("Enter 1 To Continue\n");
  scanf("%d",&choice11);

  switch(choice11)
  {
  case 1:
      system("cls");
    logwright();
    break;

}
}
 /* this is the function used for the adding of  subcontractors*/
 void addsubcontract(){
 	  int paid,pay,choice12;
 	  char option,contractedfrom[40],periodspent[9],addsubcontract[40],doe[9];
 	  system("cls");
 	  printf("Please enter where the contractor was contracted from: ");
 	  printf("-");
 	  scanf("%s",contractedfrom);
 	  printf("Please enter the name of the contractor:\n");
 	  printf("-");
 	  scanf("%s",addsubcontract);
 	  printf("Please enter the date of entry:\n");
 	  printf("-");
 	  scanf("%s",doe);
 	  printf("Please enter the period the contractor spent:\n ");
 	  scanf("%s",periodspent);
 	  if (option==paid){
 	   printf("Please enter the amount paid to the contractor:\n ");
	   scanf("%d",&paid);
	   } else {
	   printf("Please enter the amount that shuold be paid:\n ");
	   scanf("%d",&pay);
	   }

 if ((subcontractor=fopen("subcontract.txt","a+"))== NULL) {
 	  printf("File could not be open");
 }
 else{
 if(option==paid){
 	 fprintf(subcontractor,"%s\t%s\t\%d\n",contractedfrom,addsubcontract,periodspent,paid);
 }
 if(option==pay){
 	fprintf(subcontractor,"%s\t%s\t\%d\n",contractedfrom,addsubcontract,periodspent,pay);
 }

 fclose(subcontractor);
 }

 printf("\n");
  printf("Enter 1 To Continue\n");
  scanf("%d",&choice12);

  switch(choice12)
  {
  case 1:
      system("cls");
    logwright();
    break;
 }



 }
 /* this is the function used for the adding of workers*/
 void addworker() {
 int salary,idno,choice13;
 char address,addworker[40],dob[9],doe[9],position[20];
 system("cls");
 printf("Please enter the name of the worker: ");
 scanf("%s",addworker);
 printf("Please enter the i.d number for worker: ");
 scanf("%d",&idno);
 printf("Please enter the adress of the worker: ");
 scanf("%s",address);
 printf("Please enter the position of the worker: ");
 scanf("%s",position);
 printf("Please enter the salary of worker: ");
 scanf("%d",&salary);
 printf("Please enter the date of employment: ");
 scanf("%s",doe);

if ((workers=fopen("worker.txt","a+"))== NULL){
	printf("File could not be open");
}
 else {
 fprintf(workers,"%s\t%d\t%s\t%s\t%d\t%d\n",addworker,&idno,address,position,&salary,doe);

 fclose(workers);
 }

 printf("\n");
  printf("Enter 1 To Continue\n");
  scanf("%d",&choice13);

  switch(choice13)
  {
  case 1:
      system("cls");
    logwright();
    break;
}
 }

/* this is the function used for the adding of information needed to calculate the salary*/
void payroll(){
	int option,choice14,count=0;
	float grosssalary,netpay,payrate,totaltax;
	float overrate;

	system("cls");
	printf("Please enter the name of the worker: \n");
	getchar();
	gets(payrollinfo.name);
	printf("Please enter the id number of the worker: \n");
	scanf("%d",&payrollinfo.idno);
	printf("Please enter the hours worked: \n");
	scanf("%d",&payrollinfo.hourswork);
    printf("Please enter the overtime hours:");
	scanf("%d",&payrollinfo.overtime);
	printf("Please enter the career: \n");
	scanf("%s",payrollinfo.career);
	if ((strcmp(payrollinfo.career,"painter")==1)){
	payrate = 2500;

	}
    if ((strcmp(payrollinfo.career,"carpenter")==1)){
    payrate = 2500;
	}
	if ((strcmp(payrollinfo.career,"supervisor")==1)){
	payrate = 5000;
	}
	if (strcmp(payrollinfo.career,"tiler")==1){
	payrate = 3000;
	}
	if ((strcmp(payrollinfo.career,"mason")==1)){
	payrate = 2500;
	}
	if ((strcmp(payrollinfo.career,"laborer")==1)){
	payrate = 1500;
	}
	grosssalary=payrollinfo.hourswork*payrate;
	nht=grosssalary*0.035;
	nis=grosssalary*0.028;
	payrollinfo.incometax=grosssalary*0.25;
	overrate=payrollinfo.overtime*10;
	totaltax=nht+nis+payrollinfo.incometax;
	netpay=grosssalary-totaltax;
	printf("Gross Salary : %.1f\n",grosssalary);
	printf("NHT: %.1f\n",nht);
	printf("NIS: %.1f\n",nis);
    printf("Income Tax : %.1f\n",payrollinfo.incometax);
    printf("Over Rate : %.1f\n",overrate);
    printf("Total Tax : %.1f\n",totaltax);
    printf("Net Pay : %.1f\n",netpay);

   if ((pay=fopen("pay.txt","a+"))== NULL){
	printf("File could not be open");
}
 else {
 fprintf(pay,"%s\t%d\t%d\t%d\t%s\n",payrollinfo.name,payrollinfo.idno,payrollinfo.hourswork,payrollinfo.overtime,payrollinfo.career);
 fclose(pay);
}
     system("pause");
     main();

}
