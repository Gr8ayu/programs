#include<stdio.h>
int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
int main()
{
    int fr, pgs, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &fr);
	printf("Enter number of pages: ");
	scanf("%d", &pgs);
	printf("Enter reference string: ");
    for(i = 0; i < pgs; ++i){
    	scanf("%d", &pages[i]);
    }
	for(i = 0; i < fr; ++i){
    	frames[i] = -1;
    }
    for(i = 0; i < pgs; ++i)
        {
            flag1 = flag2 = 0;
            for(j = 0; j < fr; ++j){
                if(frames[j] == pages[i]){
                    counter++;
                    time[j] = counter;
                    flag1 = flag2 = 1;
                    break;
                }
            }
            if(flag1 == 0){
                for(j = 0; j < fr; ++j){
                    if(frames[j] == -1){
                        counter++;
                        faults++;
                        frames[j] = pages[i];
                        time[j] = counter;
                        flag2 = 1;
                        break;
                    }
                }
            }
            if(flag2 == 0){
                for(j=0;j<fr;j++)
                {
                    printf("%d--",time[j]);
                }
                printf("\n");
                pos = findLRU(time, fr);
                counter++;
                faults++;
                frames[pos] = pages[i];
                time[pos] = counter;
            }
            printf("\n");
            for(j = 0; j < fr; ++j){
                printf("%d\t", frames[j]);
            }
        }
	printf("\n\nTotal Page Faults = %d", faults);
	printf("\nTotal Page Hits = %d",pgs-faults);
    return 0;
}
