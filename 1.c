#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct recd
{
  char name[32];
  char branch[32];
  char roll_no[7];
  int semester;
  char fname[32];
  char mname[32];
  int hno;
  char street[20];
  char city[10];
  char state[10];
  char country[10];
};
typedef struct recd stud;
static int num = 0;
static int maxCount = 0;
void input(stud *data)
{
  if(maxCount < num)
  {
    printf("Enter Name :");
    fflush(stdin);
    gets(data[maxCount].name);
    printf("Enter Branch : ");
    fflush(stdin);
    gets(data[maxCount].branch);
    printf("Enter Roll no : ");
    fflush(stdin);
    gets(data[maxCount].roll_no);
    printf("Enter Semester(1/2/3/4/5/6/7/8) : ");
    fflush(stdin);
    scanf("%d", &data[maxCount].semester);
    printf("Enter father's name :");
    fflush(stdin);
    gets(data[maxCount].fname);
    printf("Enter mother's Name :");
    fflush(stdin);
    gets(data[maxCount].mname);
    printf("Enter house no. ");
    fflush(stdin);
    scanf("%d", &data[maxCount].hno);
    printf("Enter street name :");
    fflush(stdin);
    gets(data[maxCount].street);
    printf("Enter city :");
    fflush(stdin);
    gets(data[maxCount].city);
    printf("Enter state :");
    fflush(stdin);
    gets(data[maxCount].state);
    printf("Enter Country :");
    fflush(stdin);
    gets(data[maxCount].country);
    maxCount++;
  }
  else
  {
    printf("No more space.\n");
  }
}
int search(stud *data, char key[])
{
  for(int i = 0 ; i < maxCount; i++){
    if(strcmp(key, data[i].roll_no) == 0)
    {
      printf("RECORD FOUND!!!!\n");
      printf("%s\t%s\t", data[i].roll_no,data[i].name);
      printf("%s\t%d\n", data[i].branch, data[i].semester);
      printf("%s\t%s\t", data[i].fname,data[i].mname);
      printf("%d\t%s\t", data[i].hno,data[i].street);
      printf("%s\t%s\t%s\t", data[i].city,data[i].state,data[i].country);
      return i;
    }
  }
  return -1;
}
void traverse(stud *data){
  FILE *fpointer = fopen("myRecord.txt", "w");
    printf("Name\tBranch\tRollNo.\tSemester\n");
  for(int i = 0; i < maxCount; i++)
  {
    fprintf(fpointer,"%s %s %s %d %s %s %d %s %s %s %s\n", data[i].name, data[i].branch, data[i].roll_no, data[i].semester,data[i].fname,data[i].mname,data[i].hno,data[i].street,data[i].city,data[i].state, data[i].country);
    printf("%s\t%s\t%s\t%d\t%s\t %s\t %d\t %s\t %s\t %s\t %s\n", data[i].name, data[i].branch, data[i].roll_no, data[i].semester,data[i].fname,data[i].mname,data[i].hno,data[i].street,data[i].city,data[i].state, data[i].country);
  }
  fclose(fpointer);
}
void delete(stud *data)
{
  char roll_no_del[20];
  printf("Enter the roll no : ");
  fflush(stdin);
  gets(roll_no_del);
  int result = search(data, roll_no_del);
  if(result != -1)
  {
    for(int i = result ; i < maxCount; i++)
    {
      data[i] = data[i+1];
    }
    maxCount--;
  }
  printf("RECORD DELETED!!!");
}
void update(stud *data)
{
  char roll_no_del[20];
  printf("Enter the roll no : ");
  fflush(stdin);
  gets(roll_no_del);
  int result = search(data, roll_no_del);
  if(result != -1)
  {
    printf("Enter updated Name :");
    fflush(stdin);
    gets(data[result].name);
    printf("Enter updated Branch : ");
    fflush(stdin);
    gets(data[result].branch);
    printf("Enter updated Roll no : ");
    fflush(stdin);
    gets(data[result].roll_no);
    printf("Enter updated Semester (1/2/3/4/5/6/7/8): ");
    fflush(stdin);
    scanf("%d",&data[result].semester);
    printf("Enter father's name :");
    fflush(stdin);
    gets(data[result].fname);
    printf("Enter mother's Name :");
    fflush(stdin);
    gets(data[result].mname);
    printf("Enter hno ");
    fflush(stdin);
    scanf("%d",&data[result].hno);
    printf("Enter street name :");
    fflush(stdin);
    gets(data[result].street);
    printf("Enter city :");
    fflush(stdin);
    gets(data[result].city);
    printf("Enter state :");
    fflush(stdin);
    gets(data[result].country);
    printf("Enter country :");
    fflush(stdin);
    gets(data[result].country);
    printf("RECORD UPDATED!!!");
    
  }
  else{
    printf("NO record found.\n");
  }
}
void reportgen(stud *data)
{
  int choice;
  int count=0;
  char city2[32];
  char street2[32];
  char country2[32];
  printf("1. REPORT BASED ON STREET\n2. REPORT BASED ON CITY\n3. REPORT BASED ON COUNTRY\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:
            printf("REPORT BASED ON street\n");
            printf("Enter street: ");
            fflush(stdin);
            gets(street2);
            for(int i = 0;i < maxCount;i++){
              if(strcmp(street2, data[i].street) == 0)
              {
                printf("%s\t%s\t", data[i].roll_no,data[i].name);
                printf("%s\t%d\n", data[i].branch, data[i].semester);
                printf("%s\t%s\t", data[i].fname,data[i].mname);
                printf("%d\t%s\t", data[i].hno,data[i].street);
                printf("%s\t%s\t%s\t", data[i].city,data[i].state,data[i].country);
                count++;
              }
            }
           if (count!=0) {
             printf("Number of records in street %s are %d\n",street2,count);
           }
           else
            printf("NO records in street %s\n",street2);
          break;
    case 2:
            printf("REPORT BASED ON city\n");
            printf("Enter city: ");
            fflush(stdin);
            gets(city2);
            for(int i = 0;i < maxCount;i++){
              if(strcmp(city2, data[i].city) == 0)
              {
                printf("%s\t%s\t", data[i].roll_no,data[i].name);
                printf("%s\t%d\n", data[i].branch, data[i].semester);
                printf("%s\t%s\t", data[i].fname,data[i].mname);
                printf("%d\t%s\t", data[i].hno,data[i].street);
                printf("%s\t%s\t%s\t", data[i].city,data[i].state,data[i].country);
                count++;
              }
            }
           if (count!=0) {
             printf("Number of records in city %s are %d.\n",city2,count);
           }
           else
            printf("NO records in city %s.\n",city2);
          break;
     case 3:
            printf("REPORT BASED ON country\n");
            printf("Enter country: ");
            fflush(stdin);
            gets(country2);
            for(int i = 0;i < maxCount;i++){
              if(strcmp(country2, data[i].country) == 0)
              {
                printf("%s\t%s\t", data[i].roll_no,data[i].name);
                printf("%s\t%d\t", data[i].branch, data[i].semester);
                printf("%s\t%s\t", data[i].fname,data[i].mname);
                printf("%d\t%s\t", data[i].hno,data[i].street);
                printf("%s\t%s\t%s\n", data[i].city,data[i].state,data[i].country);
                count++;
              }
            }
           if (count!=0) {
             printf("Number of records in country %s are %d\n",country2,count);
           }
           else
            printf("NO records in country %s\n",country2);
          break;
    default:
          printf("INVALID INPUT\n");
          break;
  }
}
int main()
{

  printf("************* STUDENT RECORD USING DATA STRUCTURE: ARRAY *********\n");
  printf("\nEnter Max Number of Students to work with:");
  scanf("%d",&num);
  stud *data = (stud *)malloc(sizeof(stud) * num);
  int choice,number;
  char d_roll[30],f;
  do{
    printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
    printf("1. Input a record.\n");
    printf("2. Delete a record.\n");
    printf("3. Search a record.\n");
    printf("4. Traverse.\n");
    printf("5. Update a record.\n");
    printf("6. Generate the report\n");
    printf("7. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        input(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 2:
        delete(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 3:
        printf("Enter the roll no : ");
        scanf("%s", &d_roll);
        int result = search(data, d_roll);
        if(result == -1)
          printf("Not found\n");
        else
          printf("Found at postion %d", result + 1);
      printf("\nWant to return to main menu?(Y/N)");
  		scanf(" %c", &f);
        break;
      case 4:
        traverse(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 5:
        update(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 6:
        reportgen(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      default:
        exit(0);
    }
  }while(f=='Y'||f=='y');
  return 0;
}
