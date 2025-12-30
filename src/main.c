#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write actions to log file */
void log_action(const char *action) {
    FILE *fp = fopen("logs/system.log", "a");
    if (fp == NULL) {
        printf("Unable to open log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(fp, "%s - %s\n", ctime(&now), action);
    fclose(fp);
}

/* Check network connectivity */
void ping_test() {
    printf("\nRunning ping test...\n");
    system("ping -c 3 8.8.8.8");
    log_action("Ping test executed");
}

/* Show IP configuration */
void show_ip() {
    printf("\nShowing IP configuration...\n");
    system("ip addr show");
    log_action("IP configuration checked");
}

/* Show system information */
void system_info() {
    printf("\nSystem information:\n");
    system("uname -a");
    log_action("System information checked");
}

int main() {
    int choice;

    while (1) {
        printf("\n==== Linux Diagnostic Tool ====\n");
        printf("1. Ping Test\n");
        printf("2. Show IP Configuration\n");
        printf("3. Show System Info\n");
        printf("4. Write Log Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ping_test();
                break;
            case 2:
                show_ip();
                break;
            case 3:
                system_info();
                break;
            case 4:
                log_action("Manual log entry");
                printf("Log written.\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

