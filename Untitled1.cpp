void Append()
  {
    FILE *ptr;
    int i=0;
    char ch;
    ptr=fopen("vaccine_details.bin","a+");
    fseek(ptr,0,SEEK_END);
    i=ftell(ptr);
    do
    {
       i=i+1;
       printf("Enter the ID number :");
       scanf("%s",D[i].ID);
       printf("Enter the name :");
       scanf("%*c%[^\n]",D[i].Name);
       printf("Enter the House Name :");
       scanf("%*c%[^\n]",D[i].Address);
       printf("Enter the Birth Of Date (DD/MM/YYYY) :");
       scanf("%d%d%d",&D[i].dd,&D[i].mm,&D[i].yy);
       printf("Have you taken the first dose(Y/N) :");
       scanf("%s",D[i].DT1);
       printf("Have you taken the second dose(Y/N) :");
       scanf("%s",D[i].DT2);
       fwrite(&D[i],sizeof(D[i]),1,ptr);
       printf("Do you want to continue adding vaccinators (y/n) : ");
       scanf("%s",&ch);
     }
     while(ch=='y');
    fclose(ptr);
  }
