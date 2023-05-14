#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char fn[50];
    int choice;
    
    printf("Enter the filename: ");
    scanf("%s", fn);
    
    while(1)
    {
        printf("\n1. Create file\n2. Delete file\n3. Modify file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                fp = fopen(fn, "w");
                printf("File created successfully\n");
                fclose(fp);
                break;
                
            case 2:
                if(remove(fn) == 0)
                {
                    printf("File deleted successfully\n");
                }
                else
                {
                    printf("Error deleting file\n");
                }
                break;
                
            case 3:
                fp = fopen(fn, "a+");
                char dt[100];
                printf("Enter the data you want to write: ");
                scanf("%s", dt);
                fprintf(fp, "%s", dt);
                printf("Data written successfully\n");
                fclose(fp);
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}
