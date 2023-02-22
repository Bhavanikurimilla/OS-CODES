#include <stdio.h>
 
//user-defined function
int findLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}
 
//main function
int main()
{
   int np,nf,counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
   printf("Enter number of frames: ");
   scanf("%d", &nf);
 
   printf("Enter number of pages: ");
   scanf("%d", &np);
   int frames[nf],pages[np];
 
   printf("Enter the pages: ");
 
   for (i = 0; i < np; ++i)
   {
      scanf("%d", &pages[i]);
   }
 
   for (i = 0; i < nf; ++i)
   {
      frames[i] = -1;
   }
 
 	printf("\n\n");
   for (i = 0; i < np; ++i)
   {
   	  printf("%d  Frames: ",pages[i]);
      flag1 = flag2 = 0;
 
      for (j = 0; j < nf; ++j)
      {
         if (frames[j] == pages[i])
         {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < nf; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = pages[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = findLRU(time, no_of_frames);
         counter++;
         faults++;
         frames[pos] = pages[i];
         time[pos] = counter;
      }
      for (j = 0; j < no_of_frames; ++j)
      {
         printf("%d  ", frames[j]);
      }
      printf("\n");
   }
 	int hit=no_of_pages-faults;
   printf("\nTotal Page Faults = %d", faults);
   printf("\nTotal page Hits = %d", hit);
   printf("\nHit Ratio: %.2f\nFault Ratio: %.2f",(float)hit/no_of_pages,(float)faults/no_of_pages);
 
   return 0;
}
