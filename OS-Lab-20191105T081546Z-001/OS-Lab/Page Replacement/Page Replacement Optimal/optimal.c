#include<stdio.h>

int main()
{
    int fr, pgs, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &fr);

    printf("Enter number of pages: ");
    scanf("%d", &pgs);

    printf("Enter page reference string: ");

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
                       flag1 = flag2 = 1;
                       break;
                   }
            }

            if(flag1 == 0){
                for(j = 0; j < fr; ++j){
                    if(frames[j] == -1){
                        faults++;
                        frames[j] = pages[i];
                        flag2 = 1;
                        break;
                    }
                }
            }

            if(flag2 == 0){
                flag3 =0;

                for(j = 0; j < fr; ++j){
                    temp[j] = -1;

                    for(k = i + 1; k < pgs; ++k){
                        if(frames[j] == pages[k]){
                            temp[j] = k;
                            break;
                        }
                    }
                }

                for(j = 0; j < fr; ++j){
                    if(temp[j] == -1){
                        pos = j;
                        flag3 = 1;
                        break;
                    }
                }

                if(flag3 ==0){
                    max = temp[0];
                    pos = 0;

                    for(j = 1; j < fr; ++j){
                        if(temp[j] > max){
                            max = temp[j];
                            pos = j;
                        }
                    }
                }

                frames[pos] = pages[i];
                faults++;
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
