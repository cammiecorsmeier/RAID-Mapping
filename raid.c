#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//raid 0 calculation
void raid_0(int N, int C, int queries[], int Q) {
    if(C == 0){ //this is when chunk size = 0
    	for (int i = 0; i < Q; i++) {
            int address = queries[i];
            int disk = address % N;	//regular formula
            int stripe = address / N;
            printf("%d %d\n", disk, stripe);
       	}
    }else{	//for chunk size > 0
	for (int i = 0; i < Q; i++) {
	    int address = queries[i];
	    int disk = (address/C) % N;	//must divide address by chunk size
	    int stripe = (address / (C * N)) * C + (address % C); 
	    printf("%d %d\n", disk, stripe);
	}
    }
}

//raid 1 calculation
void raid_1(int S, int queries[], int Q) {
    for (int i = 0; i < Q; i++) {
        int address = queries[i];
	int disk = 0;		//the disks dont change since it is a duplicate on both
        int stripe = address % S; //stripe depends on number of stripes instead of disks
        int mirror_disk = disk + 1;
        printf("%d %d %d\n", disk, stripe, mirror_disk);
    }
}

//raid 01 calculation
void raid_01(int N, int queries[], int Q) {
    for (int i = 0; i < Q; i++) {
        int address = queries[i];
        int disk = address % (N/2);	//must divide N by 2 because of duplicates
        int stripe = address / (N/2);	//same thing here
        int mirror_disk = disk + (N/2);
        printf("%d %d %d\n", disk, stripe, mirror_disk);
    }
}

//raid 10 calculation
void raid_10(int N, int queries[], int Q) {
    for (int i = 0; i < Q; i++) {
        int address = queries[i];
	int disk = (address * 2) % N;	//must multiply address by 2 because of duplicates
	int mirror_disk = disk + 1;	
	int stripe = address / (N/2);	//stripe is the same as raid 01
        printf("%d %d %d\n", disk, stripe, mirror_disk);
    }
}

//raid 4 calculation
void raid_4(int N, int queries[], int Q) {
   int parity_disk = N - 1;
   for (int i = 0; i < Q; i++) {
       int address = queries[i];
       int disk = address % (N - 1);	//must subtract N by 1 to account for parity
       int stripe = address / (N - 1);	//same thing here
       printf("%d %d %d\n", disk, stripe, parity_disk);
   }
}

//raid 5 calculation
void raid_5(int N, int queries[], int Q) {
    for (int i = 0; i < Q; i++) {
    	int address = queries[i];
        int stripe = address / (N - 1);	//stripe is the same as raid 4
	int parity_disk = (N-1) - (stripe % N);	//parity disk depends on N and stripe
	int disk = address % N;		//basic formula works here
        printf("%d %d %d\n", disk, stripe, parity_disk);
  }
}

int main() {
    int N, C, S, Q;
    char T[2];
    //this takes input from the terminal for all the variables
    scanf("%s %d %d %d %d", T, &N, &C, &S, &Q);
    int queries[Q];
    for (int i = 0; i < Q; i++) {
	//this reads each query one by one
        scanf("%d", &queries[i]);
    }

    //this calls the type of computation needed based on the input
    if (strcmp(T, "0")==0) {
        raid_0(N, C, queries, Q);
    } else if (strcmp(T, "1") == 0) {
        raid_1(S, queries, Q);
    } else if (strcmp(T, "01") == 0){
	raid_01(N, queries, Q);
    } else if (strcmp(T, "10") == 0) {
        raid_10(N, queries, Q);
    } else if (strcmp(T, "4") == 0) {
        raid_4(N, queries, Q);
    } else if (strcmp(T, "5") == 0) {
        raid_5(N, queries, Q);
    } else {
        printf("Invalid RAID level\n");
    }

    return 0;
}
